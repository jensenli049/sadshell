#include "sadshell.h"

int main( int argc, char *argv[] ){
  while(1){
    printf("$ad$hell$ ");
    char input[200];// = (char*)malloc(200*sizeof(char));
    fgets(input, sizeof(input), stdin);
    //printf("input: %s", input);
    if( strcmp(input,"exit") )
      exit(0);

    int f = fork();
    if(!f){ //child
      ParseCmd(input);
    }
    
  }
  
}
/*
void ParseCmd(char[]){
  
}

void
*/
