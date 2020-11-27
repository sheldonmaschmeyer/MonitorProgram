#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

#define text_SIZE 11
#define data_SIZE 13
#define audio_SIZE 9
#define video_SIZE 14
#define _3D_SIZE 4
#define raster_SIZE 12
#define vector_SIZE 4
#define pageLayout_SIZE 3
#define spreadsheet_SIZE 3
#define database_SIZE 6
#define executable_SIZE 9
#define gameFiles_SIZE 5
#define CAD_SIZE 2
#define GIS_SIZE 3
#define web_SIZE 13
#define plugin_SIZE 2
#define font_SIZE 4
#define system_SIZE 11
#define settings_SIZE 3
#define endcoded_SIZE 3
#define compressed_SIZE 11
#define diskImage_SIZE 7
#define developer_SIZE 18
#define backupFiles_SIZE 2

const char* textFiles[text_SIZE] = {"doc", "docx", "log", "msg", "odt", "pages", "rtf", "tex", "txt", "wpd", "wps"};
const char* dataFiles[data_SIZE] = {"csv", "dat", "ged", "key", "keychain", "pps", "ppt", "pptx", "sdf", "tar", "tax2016", "vcf", "xml"};
const char* audioFiles[audio_SIZE] = {"aif", "iff", "m3u", "m4a", "mid", "mp3", "mpa", "wav", "wma", };
const char* videoFiles[video_SIZE] = {"3g2", "3gp", "asf", "avi", "flv", "m4v", "mov", "mp4", "mpg", "rm", "srt", "swf", "vob", "wmv"};
const char* _3DFiles[_3D_SIZE] = {"3dm", "3ds", "max", "obj"};
const char* rasterImageFiles[raster_SIZE] = {"bmp", "dds", "gif", "jpg", "png", "psd", "pspimage", "tga", "thm", "tif", "tiff", "yuv"};
const char* vectorImageFiles[vector_SIZE] = {"ai", "eps", "ps", "svg"};
const char* pageLayoutFiles[pageLayout_SIZE] = {"indd", "pct", "pdf"};
const char* spreadsheetFiles[spreadsheet_SIZE] = {"xlr", "xls", "xlsx"};
const char* databaseFiles[database_SIZE] = {"accdb", "db", "dbf", "mdb", "pdb", "sql"};
const char* executableFiles[executable_SIZE] = {"apk", "app", "bat", "cgi", "com", "exe", "gadget", "jar", "wsf"};
const char* gameFiles[gameFiles_SIZE] = {"dem", "gam", "nes", "rom", "sav"};
const char* CAD_Files[CAD_SIZE] = {"dwg", "dxf"};
const char* GIS_Files[GIS_SIZE] = {"gpx", "kml", "kmz"};
const char* webFiles[web_SIZE] = {"asp", "aspx", "cer", "cfm", "csr", "css", "htm", "html", "js", "jsp", "php", "rss", "xhtml"};
const char* pluginFiles[plugin_SIZE] = {"crx", "plugin"};
const char* fontFiles[font_SIZE] = {"fnt", "fon", "otf", "ttf"};
const char* systemFiles[system_SIZE] = {"cab", "cpl", "cur", "deskthemepack", "dll", "dmp", "drv", "icns", "ico", "lnk", "sys"};
const char* settingsFiles[settings_SIZE] = {"cfg", "ini", "prf"};
const char* endcodedFiles[endcoded_SIZE] = {"hqx", "mim", "uue"};
const char* compressedFiles[compressed_SIZE] = {"7z", "cbr", "deb", "gz", "pkg", "rar", "rpm", "sitx", "tag.gz", "zip", "zipx"};
const char* diskImageFiles[diskImage_SIZE] = {"bin", "cue", "dmg", "iso", "mdf", "toast", "vcd"};
const char* developerFiles[developer_SIZE] = {"c", "class", "cpp", "cs", "dtd", "fla", "h", "java", "lua", "m", "pl", "py", "sh", "sln", "swift", "vb", "vcxproj", "xcodeproj"};
const char* backupFiles[backupFiles_SIZE] = {"bak", "tmp"};

char tempStr[] = "";

int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("Too many or too few arguments\n");
		exit(0);
	}
	
	char* userName = argv[1];
	//printf("USER: %s\n", userName);
	
	//create required directories
	//TEXT
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Text");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//DATA
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Data");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//AUDIO
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Audio");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//VIDEO
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Video");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//3D IMAGES
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/3D_Images");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//RASTER IMAGES
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Raster_Images");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//VECTOR IMAGES
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Vector_Images");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//PAGE LAYOUT
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Page_Layouts");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Spreadsheet
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Spreadsheets");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Database
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Database");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Executable
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Executable");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Game files
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Game");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//CAD
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/CAD");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//GIS
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/GIS");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Web files
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Web");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Plugin
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Plugin");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Font
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Font");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//System
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/System");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Setting_Files
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Setting_Files");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Encoded_Files
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Encoded_Files");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Compressed
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Compressed");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Disk_Images
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Disk_Images");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Developer_Files
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Developer_Files");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Backups
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Backups");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	//Misc
	strcpy(tempStr, "mkdir /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Misc");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	
	
	printf("Moving and Sorting files\n");
	//moving text files
	//printf("Move Text files\n");
	for(int i=0; i < text_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, textFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, textFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Text 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, textFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving data files
	//printf("Move Data files\n");
	for(int i=0; i < data_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, dataFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, dataFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Data 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, dataFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving audio files
	//printf("Move Audio files\n");
	for(int i=0; i < audio_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, audioFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, audioFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Audio 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, audioFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving video files
	//printf("Move Video files\n");
	for(int i=0; i < video_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, videoFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, videoFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Video 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, videoFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving 3d image files
	//printf("Move 3D Images files\n");
	for(int i=0; i < _3D_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, _3DFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, _3DFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/3D_Images 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, _3DFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving raster image files
	//printf("Move Raster Images files\n");
	for(int i=0; i < raster_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, rasterImageFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, rasterImageFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Raster_Images 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, rasterImageFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving vector image files
	//printf("Move Vector Images files\n");
	for(int i=0; i < vector_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, vectorImageFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, vectorImageFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Vector_Images 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, vectorImageFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Page Layout files
	//printf("Move Page Layout files\n");
	for(int i=0; i < pageLayout_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, pageLayoutFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, pageLayoutFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Page_Layouts 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, pageLayoutFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Spreadsheet files
	//printf("Move Spreadsheet files\n");
	for(int i=0; i < spreadsheet_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, spreadsheetFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, spreadsheetFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Spreadsheets 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, spreadsheetFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Database files
	//printf("Move Database files\n");
	for(int i=0; i < database_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, databaseFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, databaseFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Database 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, databaseFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Executable files
	//printf("Move Executable files\n");
	for(int i=0; i < executable_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, executableFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, executableFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Executable 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, executableFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Game files
	//printf("Move Game files\n");
	for(int i=0; i < gameFiles_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, gameFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, gameFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Game 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, gameFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving CAD files
	//printf("Move CAD files\n");
	for(int i=0; i < CAD_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, CAD_Files[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, CAD_Files[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/CAD 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, CAD_Files[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving GIS files
	//printf("Move GIS files\n");
	for(int i=0; i < GIS_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, GIS_Files[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, GIS_Files[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/GIS 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, GIS_Files[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Web files
	//printf("Move Web files\n");
	for(int i=0; i < web_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, webFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, webFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Web 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, webFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Plugin files
	//printf("Move Plugin files\n");
	for(int i=0; i < plugin_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, pluginFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, pluginFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Plugin 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, pluginFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Font files
	//printf("Move Font files\n");
	for(int i=0; i < font_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, fontFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, fontFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Font 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, fontFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving System files
	//printf("Move System files\n");
	for(int i=0; i < system_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, systemFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, systemFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/System 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, systemFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Setting files
	//printf("Move Setting files\n");
	for(int i=0; i < settings_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, settingsFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, settingsFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Setting_Files 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, settingsFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Encoded files
	//printf("Move Encoded files\n");
	for(int i=0; i < endcoded_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, endcodedFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, endcodedFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Encoded_Files 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, endcodedFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Compressed files
	//printf("Move Compressed files\n");
	for(int i=0; i < compressed_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, compressedFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, compressedFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Compressed 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, compressedFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Disk Image files
	//printf("Move Disk Image files\n");
	for(int i=0; i < diskImage_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, diskImageFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, diskImageFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Disk_Images 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, diskImageFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Developer files
	//printf("Move Developer files\n");
	for(int i=0; i < developer_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, developerFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, developerFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Developer_Files 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, developerFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Backup files
	//printf("Move Backup files\n");
	for(int i=0; i < backupFiles_SIZE; i++){
		strcpy(tempStr, "[ -f /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, backupFiles[i]);
		strcat(tempStr, " ] && ");
		strcat(tempStr, "mv /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/*.");
		strcat(tempStr, backupFiles[i]);
		strcat(tempStr, " /home/");
		strcat(tempStr, userName);
		strcat(tempStr, "/storage/Backups 2>/dev/null");
		strcat(tempStr, " || echo 'skipping ext:'");
		strcat(tempStr, backupFiles[i]);
		strcat(tempStr, " > /dev/null");
		system(tempStr);
	}
	////////////////////////////////////////////
	//moving Misc files
	//printf("Move Misc files\n");
	strcpy(tempStr, "mv /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/*.*");
	strcat(tempStr, " /home/");
	strcat(tempStr, userName);
	strcat(tempStr, "/storage/Misc");
	strcat(tempStr, " 2>/dev/null");
	system(tempStr);
	
	printf("File Sorting Complete\n");
	
	return 0;
}















