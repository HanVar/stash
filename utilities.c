#include"utilities.h"
#include <unistd.h>

void append_command(char **commands, char *command, int *index){
	if(*index+1 == MAX_COMMANDS){
		free(commands[0]);
		for(int i = 1; i < MAX_COMMANDS; i++){
			commands[i-1] = commands[i];
		}
		commands[*index] = command;
	}else{
		commands[*index] = command;
        /*
         * SEGFAULT - EXC_BAD_ACCESS
         */
		(*index)++;
	}
}

int generateIndex(char *user_input){
	if(!strcmp(user_input, "hello")) return 0; // example command
	/*
	 * else if(strcmp(user_input, ...)) return n
	 */
	else return -1;
}

void throwError(char *err){
	perror(err);
	exit(1);
}
