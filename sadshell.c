#include "sadshell.h"

int main( int argc, char *argv[] ){
  /*
    char tmp[100] = "ls -a -l\n";
    char **argv2 = parse_args(tmp);/
    execvp(argv2[0], argv2);
  */
    
    // if input is not 'exit', continue running
  while(1){
    printf("$ad$hell$ ");
    char input[256];
      
      //waits for input
    fgets(input, sizeof(input), stdin);
    printf("%s", input);

      //exits shell
    if( !((strcmp(input,"exit"))-10) )
      exit(0);
      
      //separates comands by ';'
    char ** cmds = fix_semicolons( input );
    int i = 0;
    if( !((strcmp(input,"exit"))-10) )
      exit(0);
    /*
      while(cmds[i]){
      printf("cmd[%d]: %s\n",i, cmds[i]);
      i++;
      }
    */
      
      //separate the args into a 2d array
    while(cmds[i]){
      char ** args = malloc(256*sizeof(char*));
      args = parse_args(cmds[i]);
      
        //cd command
      if( !((strcmp(args[0],"cd"))) ){
          int q = chdir(args[1]);
          i++;
          continue;
      }
      
      int status = fork();
      if(!status){ //child
	//printf("\nTesting %s", input);
	execvp(args[0], args);
	
	exit(0);
      }
      else{
	wait(&status);
      }
      i++;
    }
  }
}


/* ================char * strip()=================
 Inputs:
    char * line
 Returns:
    New string with unnecessary spaces removed
 
    Gets rid of all unnecessary spaces (extra spaces before and after the command and semicolons) in the string line.
 */
char * strip(char * line){
  char * temp = (char*)malloc(sizeof(line));
  if( (strncmp(line, " ", 1) == 0))
    strncpy(temp, line + 1, strlen(line) - 1);
  else if((strncmp(line + strlen(line)-1, " ", 1) == 0))
    strncpy(temp, line, strlen(line) - 1);
  else{
    int i = 0;
    while (*line)
      *(temp + (i++)) = *(line++);
    return temp;
  }
  strcpy(temp,strip(temp));
    return temp;
}

/* ================char ** fix_semicolons()=================
 Inputs:
    char * line
 Returns:
    A 2-D array of chars where each index contains a command

    If line has a semicolon, it separates the commands by semicolons. Takes in the string read from input, and returns a 2d array with a separate command in each index.
 */
char ** fix_semicolons(char * line ){
  char **retval = malloc(256*sizeof(char*));
  int i = 0;
  line = strsep(&line, "\n");
  if(!strchr(line,';')){
    retval[0] = line;
    return retval;
  }
  while( line ){
    retval[i] = strip(strsep( &line,";" ));
    i++;
  }
  retval[i] = NULL;
  return retval;
}

/* ================char ** parse_args()=================
 Inputs:
    char * line
 Returns:
    A 2-D array where each index contains  separate argument
 
    This function takes in the string containing the entire command, separates the arguments by spaces, and returns a 2d array with separate arguments in each index.
 */
char **parse_args( char * line ){
  char **retval = malloc(256*sizeof(char*));
  int i = 0;
  line = strsep(&line, "\n");
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

