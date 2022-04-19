#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFromFile(char* filePath){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	fp = fopen(filePath, "r");
	if(fp == NULL){
		exit(1);
	}
	while((read = getline(&line, &len, fp)) != -1){
		printf("%s", line);
	}
	fclose(fp);
	if(line){
		free(line);
	}
	return 0;
}
int main(int argc, char *argv[]){
	/*

	1. Iterate through all commands after 1 and 
	read all of the files. 
	2. output all of that data.

	*/

	if(argc == 0){
	   printf("Please provide a filepath or file you want to read from");
           exit(1);
	}
	for(int i = 1;i < argc;i++){
		readFromFile(atoi(argv[i]));
	}
	exit(0);
}
