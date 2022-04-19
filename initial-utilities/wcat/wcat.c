#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	printf("%s", *argv);
	if(argc == 0){
	   printf("Please provide a filepath or file you want to read from");
           return 1;
	}
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	fp = fopen(argv[1], "r");
	if(fp == NULL){
	return 1;
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
