#include "sadshell.h"

int main( int argc, char *argv[] ){
    
  while(1){
    printf("$ad$hell$ ");
    char input[100];// = (char*)malloc(200*sizeof(char));
    fgets(input, sizeof(input), stdin);
    printf("input: %s", input);
      
      
      printf("Difference from 'exit': %d\n", strcmp(input,"exit"));
      if( !(strcmp(input,"exit"))-10 ){
          //printf("Difference from 'exit': %d\n", strcmp(input,"exit"));
          exit(0);
      }
    int f = fork();
    if(!f){ //child
        //printf("\nTesting %s:\n", input);
        char **args = parse_args( input );
        //printf("Parsed args\n");
      int i = 0;
      while(args[i])
          printf("cmd[%d]: %s",i++, args[i]);
    }
  }
  
}


char **parse_args( char * line ){
    char **retval = malloc(50*sizeof(char*));
    int i = 0;
    
    if(!strchr(line,' ')){
        printf("There is no space!\n");
        retval[0] = line;
        return retval;
    }
    while( line ){
        //printf("%s\n", line);
        retval[i++] = strsep( &line," " );
        //printf("%s\n", retval[i-1]);
    }
    return retval;
}

