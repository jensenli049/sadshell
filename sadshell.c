#include "sadshell.h"

int main( int argc, char *argv[] ){
    
    
    char *argv2[3];
    argv2[0] = "ls";
    argv2[1] = "-l";
    argv2[2] = NULL;
    
    execvp(argv2[0], argv2);
    
     
  while(1){
    printf("$ad$hell$ ");
    char input[100];// = (char*)malloc(200*sizeof(char));
    fgets(input, sizeof(input), stdin);
    printf("input: %s\n", input);
      
    if( !((strcmp(input,"exit"))-10) )
      exit(0);

    int status = fork();
    if(!status){ //child
      //printf("\nTesting %s:\n", input);
      char **args = parse_args( input );
      //printf("Parsed args\n");
        
      int i = 0;
        while(args[i]){
          printf("cmd[%d]: %s\n",i, args[i]);
            i++;
        }
        
      execvp(args[0], args);
        
        
        //printf("child exiting\n");
      exit(0);
    }
    else
      wait(&status);
  }
    

  
}


char **parse_args( char * line ){
  char **retval = malloc(50*sizeof(char*));
  int i = 0;
    
  if(!strchr(line,' ')){
    retval[0] = line;
    return retval;
  }
    while( line ){
        retval[i] = strsep( &line," " );
        i++;
    }
    retval[i] = NULL;
  return retval;
}

