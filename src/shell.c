// gcc shell.c ../lib/linenoise.c -o shell
#include <stdio.h>
#include <string.h>
#include "../lib/linenoise.h"
#include <stdlib.h>

#define PROMPT "$ "
#define HISTORY_LEN 1024
#define MAX_ARGS 1024
#define TOKEN_SEP " \t"

int s_read(char *input, char **args);


int main(){
  
  printf("                          _                _          _  _ \n");
  printf("  _ __  ___ ___  _  _  __| | ___  ___  ___| |_   ___ | || |\n");
  printf(" | '_ \\(_-</ -_)| || |/ _` |/ _ \\|___|(_-<| ' \\ / -_)| || |\n");
  printf(" | .__//__/\\___| \\_,_|\\__,_|\\___/     /__/|_||_|\\___||_||_|\n");
  printf(" |_|                                                        \n");
  printf("\n");
    
  
  if(!linenoiseHistorySetMaxLen(HISTORY_LEN)){
    fprintf(stderr, "could not set linenoise command history.\n");
    exit(1);
  }
  
  char *line;
  char *args[MAX_ARGS];
  while((line=linenoise(PROMPT)) != NULL){
    
    // taking input
    int args_read = s_read(line, args);
    fprintf(stdout, "total args: %d\n", args_read);
    
    //skipping empty lines
    if(args_read==0){
      linenoiseFree(line);
      continue;
    }
    //  todo: evaluate + print 
    linenoiseHistoryAdd(line);
    linenoiseFree(line);
  }
}

int s_read(char *input, char **args){
  int i = 0;
  char *token = strtok(input, TOKEN_SEP);
  while (token != NULL && i < (MAX_ARGS-1)){
    args[i++] = token;
    token = strtok(NULL, TOKEN_SEP);
  }
  args[i] = NULL;
  return i;
}
