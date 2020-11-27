/*
Program: Folder Monitoring & Sorting Program
Author:  Sheldon Maschmeyer & Alex
Date:
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int mainMenu();
int stopMonitoring();
int startMonitoring();

int main() {
	mainMenu();
}

int checkUserExists(char* userName) {
  //Ref: Simple searching a file for a string https://www.codingunit.com/c-tutorial-searching-for-strings-in-a-text-file
  FILE *fp = fopen("MonitorList.txt", "r");
  char buffer[512];
  if (!fp) {
    printf("Fatal Error: Cannot Open MonitorList.txt File");
    mainMenu();
	exit(0);
  }
  while(fgets(buffer, 512, fp) != NULL) {
    if((strstr(buffer, userName)) != NULL) {
      printf("%s is already being monitored!", userName);
      fclose(fp);
      return 1;
    }
  }
  return 0;
}

void addUser(char* uName) {
	//int p = 0;
	char userName[50]; 
  	if(strcmp(uName, "") == 0) {
		printf("Please enter the username to add to the monitoring list:\n UserName: ");
		while(scanf(" %s", userName) == 0);
	}
	else strcpy(userName, uName);
	if(checkUserExists(userName) == 1) mainMenu();
	FILE *fp = fopen("MonitorList.txt", "a"); //appending to the end of the file
	if (!fp) {
		printf("Error: Cannot open MonitorList.txt file");
		mainMenu();
		return;
	}
	fprintf(fp, "%s\n", userName);
	fclose(fp);
	if(stopMonitoring() == 0) startMonitoring();
	mainMenu();
	return;
}

void removeUser(char* uName) {
  char userName[50]; 
  if(strcmp(uName, "") == 0) {
  	printf("Please enter the username to remove from the monitoring list:\n UserName: ");
  //int p = 0;
	while(scanf(" %s", userName) == 0);
  }
  if(strcmp(uName, "sheldon")) {
	  printf("\n User sheldon is the administrator, too dangerous to be removed\n");
	  mainMenu();
	  return;
  }
  else strcpy(userName, uName);
	
  printf("Removing user from Monitoring List...\n");
  FILE* fp1 = fopen("MonitorList.txt", "r");
  FILE* fp2 = fopen("~temp.txt", "w");
  char buffer[50];
  int found = 0;
  
  while(fgets(buffer, 50, fp1) != NULL) {
    if((strstr(buffer, userName)) == NULL) {
      fprintf(fp2, "%s", buffer);
    }
    else if( strstr(buffer, userName) != NULL) found++;
  }
  fclose(fp1);
  fclose(fp2);
  if(found > 0) {
    remove("MonitorList.txt");
    rename("~temp.txt", "MonitorList.txt");
    printf("User Removed \n");
  }
  else {
    remove("~temp.txt");
    printf("User not found in the Monitoring List \n");
  }
  if(stopMonitoring() == 0) startMonitoring();
  mainMenu();
}

void createSFTPAccount() {
	char userName[20]; 
	char cmd[100];

	while(1) {
		printf("\n Please enter the username to create: \n");
		while(scanf(" %s", userName) == 0);
		if(strstr(userName, "-")) {
			printf("\n Error: usernames have no special symbols, all lowercase, no spaces, under 19 characters \n");	
			continue;
		}
		strcpy(cmd, "sudo adduser ");
		strcat(cmd, userName);
		int error = system(cmd);
		if (error != 0) {
			if(error == 256) {
				printf("\n Simplified: usernames have no special symbols, all lowercase, no spaces, under 19 characters \n");	
				continue;
			}
			else {
				printf("Error: %d ", error);
				exit(0);
			}
		}
		else break;
	}
	strcpy(cmd, "sudo usermod -g ftpaccess ");
	strcat(cmd, userName);
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	
	addUser(userName);

	mainMenu();
}

void createFullAccount() {
	char userName[20]; 
	char cmd[100];
	printf("Please enter the username to create: \n");
	while(scanf(" %s", userName) == 0);
	strcpy(cmd, "sudo adduser ");
	strcat(cmd, userName);
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	strcpy(cmd, "sudo usermod -g ftpaccess ");
	strcat(cmd, userName);
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	strcpy(cmd, "sudo chown ");
	strcat(cmd, userName);
	strcat(cmd, ":ftpaccess+rw /home/");
	strcat(cmd, userName);
	strcat(cmd, "storage");
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	strcpy(cmd, "sudo chmod g+w /home/");
	strcat(cmd, userName);
	strcat(cmd, "storage");
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	
	mainMenu();
}

void deleteAccount() {
	printf("Delete User Account");
	char userName[20]; 
	char cmd[100];

	printf("Please enter the username to delete: \n");
	while(scanf(" %s", userName) == 0);
	if(strcmp(userName, "sheldon")) {
	  printf("\n User sheldon is the administrator, too dangerous to be removed\n");
	  mainMenu();
	  return;
	}
	strcpy(cmd, "sudo deluser ");
	strcat(cmd, userName);
	strcat(cmd, " --remove-home");
	
	if (system(cmd) != 0) {
		printf("Error");
		exit(0);
	}
	removeUser(userName);
	
	mainMenu();
}

int stopMonitoring() {
	int e = system("sudo killall -s SIGTERM -e RealTimeMonitor");
	printf("\n Stopping.");
	if(e != 0) 
		printf("\nmonitoring likely not started, likely nothing to stop\n");
	printf("\n It's dead Jim! Stopped Monitoring. \n");
	mainMenu();
	return 0;
}

int startMonitoring() {
	printf("Launching monitoring from the config tool runs in the same terminal, \n to stop monitoring properly, press crtl+C \n");
	int e = system("./RealTimeMonitor");
	if(e != 0 & e != 2)
		printf("\nError starting Monitoring\n Please restart the PC: %d\n", e);
	else if (e == 2)
		printf("\nStopped Monitoring \n");
	mainMenu();
	return 0;
}

int mainMenu() {
	printf("\nMain Menu \n1. Add Existing User to Monitoring List \n2. Remove Existing User from Monitoring List \n3. Create NEW User Account and add to Monitoring List \n4. Delete User Account \n5. Stop Monitoring \n6. Start Monitoring \n7. Exit\n");
	int choice = -1;
	char* p = (char*)malloc(2);
	strcpy(p, "");
	while(scanf("%d", &choice))
	// add/remove an existing user to the list of users being monitored.
	switch(choice) {
		case 1:
			addUser(p);
			return 0;
		case 2:
			removeUser(p);
			return 0;
		case 3:
			createSFTPAccount();
			return 0;
		case 4:
			deleteAccount();
			return 0;
    	case 5:
			stopMonitoring();
      		return 0;
		case 6:
			startMonitoring();
			return 0;
		case 7:
			return 0;
		default:
			return 0;
	}
}
