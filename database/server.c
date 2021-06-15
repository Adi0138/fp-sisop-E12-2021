// C program to create a folder
// #include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int check;
	char input[] = "DROP DATABASE testing_database";
	char* command = strtok(input, " ");
	char* firstCommand = command;
	command = strtok(NULL, " ");
	char* type = command;
	char database_use[100];

	//create database
	if(strcmp(firstCommand, "CREATE")== 0 && strcmp(type, "DATABASE") == 0){
		// printf("Helo");
		command = strtok(NULL, " ");
		char* dirname = command;
		char directory [100];
		sprintf(directory,"/home/adiperwira/Documents/sisop/fp/database/%s",dirname);
		printf("%s",directory);
		if (command != NULL){
			check = mkdir(directory,0777);

		}
		//check if directory is created or not
		if (!check)
			printf("Directory created\n");
		else {
			printf("Unable to create directory\n");
			exit(1);
		}
	}

	//use database
	else if(strcmp(firstCommand, "USE")== 0 && strcmp(type, "DATABASE") == 0){
		char s[100];

		command = strtok(NULL, " ");
		char* dirname = command;
    	// printing current working directory
    	printf("%s\n", getcwd(s, 100));
	
		sprintf(database_use,"/home/adiperwira/Documents/sisop/fp/database/%s",dirname);
    	// using the command
    	chdir(database_use);
	
    	// printing current working directory
    	printf("%s\n", getcwd(s, 100));
	}
	
	else if (strcmp(firstCommand, "DROP")== 0 && strcmp(type, "DATABASE") == 0){

		command = strtok(NULL, " ");
		char* dirname = command;
		char directory [100];
		sprintf(directory,"/home/adiperwira/Documents/sisop/fp/database/%s",dirname);
		DIR* dir = opendir(directory);

		if (dir) {
		    printf("Directory Exist");
		    rmdir(directory);
		} else if (ENOENT == errno) {
			printf("Directory Doesn't Exist");
		}
	}
	
}
