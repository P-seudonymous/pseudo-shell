// gcc shell.c ../lib/linenoise.h -o shell
#include <stdio.h>
#include <string.h>
#include "../lib/linenoise.h"
#include <stdlib.h>

#define PROMPT "$ "
#define HISTORY_LEN 1024

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
  while((line=linenoise(PROMPT)) != NULL){
    if(strcmp(line, "exit") == 0){
      exit(1);
    }else{
    fprintf(stdout, "%s\n", line);
    linenoiseHistoryAdd(line);
    linenoiseFree(line);
    }
  }








}

