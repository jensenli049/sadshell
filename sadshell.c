#include "sadshell.h"

int main( int argc, char *argv[] ){
  /*
    char tmp[100] = "ls -a -l\n";
    char **argv2 = parse_args(tmp);/
    execvp(argv2[0], argv2);
  */
     
  while(1){
    printf("$ad$hell$ ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    printf("%s", input);
      
    if( !((strcmp(input,"exit"))-10) )
      exit(0);

    char ** cmds = fix_semicolons( input );
    int i = 0;
    /*
    while(cmds[i]){
      printf("cmd[%d]: %s\n",i, cmds[i]);
      i++;
    }
    */
    while(cmds[i]){
      int status = fork();
      if(!status){ //child
	//printf("\nTesting %s", input);
              
	char ** args = malloc(100*sizeof(char*));
	args = parse_args(cmds[i]);
	execvp(args[0], args);
      
	exit(0);
      }
      else
	wait(&status);
      i++;
    }
  }
}

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
}

char ** fix_semicolons(char * line ){
  char **retval = malloc(50*sizeof(char*));
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

char **parse_args( char * line ){
  char **retval = malloc(50*sizeof(char*));
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

