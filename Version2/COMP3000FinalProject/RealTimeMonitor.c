//The template for monitoring a folder for changes in real time
//is from source: https://www.ibm.com/developerworks/library/l-ubuntu-inotify/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/inotify.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <dirent.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) ) //this definition is used by event monitor
#define BUF_Size    (100) //This definition is used for files
//Declared two global variables used by the sig_handler
volatile sig_atomic_t savingGrace = 0;
char firstUser[BUF_Size];

typedef struct thread_data {
  char buffer[BUF_Size];
  int sTime;
} thread_data;

static void sig_handler(int signum) {
  savingGrace = 1;
  errno = 0;
  char path[BUF_Size];
  strcpy(path, "/home/");
  strcat(path, firstUser);
  strcat(path, "/storage/stop.thread");
  FILE *fp;
  fp = fopen(path, "w");
  remove(path);
  if(fp == NULL) printf("Error stopping program using a stop dummy file: %s", strerror(errno));
  fclose(fp);
}

char* currentTime() {
  time_t theTime;
  theTime = time(NULL);
  return ctime(&theTime);
}

int launchFilesort(char* userName) {
  int status;
  int pid = fork();
  if (pid == 0) {
    //char* env[] = {"/usr/bin/sudo", NULL};
    errno = 0;
    execl("./Filesort", "Filesort", userName, NULL);
    if(errno != 0) printf("Error launching filesort %s:", strerror(errno));
  }
  else if (pid < 0) status = -1;
  else {
    if(waitpid(pid, &status, 0) != pid) status = -1;
  }
  return status;
}

void* startMonitoringUser (void* argv) {
  thread_data* tdata = (thread_data*) argv;
  int fd;
  int wd;
  int sTime = tdata->sTime;
  char* userName = tdata->buffer;
  printf("sTime %d \n", sTime); 
  int length; 
  int i;
  char monitorBuffer[BUF_LEN];
  
  char fullDir[50];
  strcpy(fullDir, "/home/");
  strcat(fullDir, userName);
	strcat(fullDir, "/storage/");
  
  fd = inotify_init();
  
  char email[200];
  
  if (fd < 0) {
    perror( "inotify_init" );
  }
  
  //wd = inotify_add_watch( fd, fullDir,IN_MODIFY|IN_DELETE|IN_CREATE);
  wd = inotify_add_watch(fd, fullDir,IN_ALL_EVENTS);
  
  length = read( fd, monitorBuffer, BUF_LEN );  
 
  if (length < 0) printf("Error monitoring: Stopped Monitoring");
 
  while (i < length & savingGrace == 0) {
    struct inotify_event *event = ( struct inotify_event * ) &monitorBuffer[ i ];
    if ( event->len ) {
      sleep(sTime);
      DIR *dp;
      struct dirent *ep;
      char filesList[200];
      strcpy(filesList, "\n");
      dp = opendir(fullDir);
        if (dp != NULL){
          while(ep = readdir(dp)) {
            if(ep->d_type == DT_REG) { //DT_REG b/c I don't want a list of directories
              strcat(filesList, ep->d_name);
              strcat(filesList, "\n");
            }
          }
        } //ref: stackoverflow.com/questions/306533/how-do-i-get-a-list-of-files-in-a-directory-in-c
      closedir(dp);
      if(strcmp(filesList, "\n") != 0) {
        printf("File(s) in a directory were created or modified.\n"); 

        strcpy(email, "echo \"Notice: Files created or modified by "); 
        strcat(email, userName);
        strcat(email, " ");
        strcat(email, currentTime());
        strcat(email, " \n");
        strcat(email, filesList);
        strcat(email, " \" | mutt -s \"User: ");
        strcat(email, userName);
        strcat(email, " created or modified files on PC ");
        //strcat(email, currentTime());
        strcat(email,"\" comp3000sheldon@gmail.com");
        system(email);
        launchFilesort(userName);
      }
    }
    //This flushes/syncs the file descriptor, buffer and properly reads again
    fsync(fd);
    length = read( fd, monitorBuffer, BUF_LEN );
  }
  errno = 0;
  inotify_rm_watch( fd, wd );
  if(errno != 0) {
    printf("Error stopping monitoring %s", strerror(errno));
    exit(0);
  }
  close( fd );
  if(errno != 0) {
    printf("Error stopping monitoring %s", strerror(errno));
    exit(0);
  }
  else {
    printf("Stopped Monitoring\n");
    exit(0);
  }
}

char UsersToMonitor() {
	
  //Ref: Simple searching a file for a string https://www.codingunit.com/c-tutorial-searching-for-strings-in-a-text-file
	FILE *fp = fopen("MonitorList.txt", "r");
	int numUsers = 0;
	int t;
	while (t != EOF) {
		t = fgetc(fp);
		if(t == '\n') numUsers++;
	}
	fseek(fp, 0, SEEK_SET);
  pthread_t threads[numUsers];
  void* retvals[numUsers];
  thread_data tdata[numUsers];
  
	char buffer[BUF_Size];
	char prog[100];
	if (!fp) {
		printf("Error: Cannot Open MonitorList.txt File");
		exit(0);
	}
  int count = 0;
	while(fgets(buffer, BUF_Size, fp) != NULL) {	
		if(strcmp(buffer,"") == 0 | strcmp(buffer, "/n") == 0 | strcmp(buffer, "\0") == 0) continue;
		strtok(buffer, "\n");
    printf("The buffer: %s \n", buffer);
    if(count == 0) strcpy(firstUser, buffer);
	  errno = 0;
    strcpy(tdata[count].buffer, buffer);
    tdata[count].sTime = 10;
    pthread_create(&threads[count], NULL, startMonitoringUser, (void*)&tdata[count]);
	  count++;
  }
  int i;
  for (i = 0; i < count; ++i) {
    errno = 0;
    if(pthread_join(threads[i], &retvals[i]) != 0) printf("Error joining threads %s \n", strerror(errno));
  }
}

int main() {
  signal(SIGINT, sig_handler);
  signal(SIGTERM, sig_handler);
	UsersToMonitor();
	return 0;
}