n#include "sadshell.h"

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
    char ** cmds = fix_char( input,";" );
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
      args = parse_args(strip(cmds[i]));
      
      //cd command
      if( !((strcmp(args[0],"cd"))) ){
	if(args[1])
	  chdir(args[1]);
	else //if only cd then go to home dir
	  chdir(getenv("HOME"));
	i++;
	continue;
      }
            
      int status = fork();
      if(!status){ //child
	//printf("\nTesting %s", input);
	
	//if( strstr(args[1], "|") && args[2])
	//piping(args[0], args[2]);
	
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

/* ================char ** fix_char()=================
   Inputs:
   char * line
   char special
   Returns:
   A 2-D array of chars where each index contains a command

   If line has a given special character, it separates the commands by tthat character. Takes in the string read from input, and returns a 2d array with a separate command in each index.
*/
char ** fix_char(char * line, char * special ){
  char **retval = malloc(256*sizeof(char*));
  int i = 0;
  line = strsep(&line, "\n");
  if(!strstr(line,special)){
    retval[0] = line;
    return retval;
  }
  while( line ){
    retval[i] = strip(strsep( &line, special ));
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

/* ================void piping()=================
   Inputs:
   char * cmd1
   char * cmd2
   Returns:
   none
 
   This function takes in the string containing first pipe command and second pipe command. It takes the outputs of the first command as the inputs for the second command.
*/
void piping( char * cmd1, char * cmd2){
  int newfd, oldfd, tmpfd;

  //printf("cmd1: %s\ncmd2: %s\n", cmd1, cmd2);
  FILE * file = popen(cmd1,"r");
  tmpfd = dup(STDIN_FILENO);
  oldfd = dup2(fileno(file), STDIN_FILENO);
  char ** newcmd = malloc(256*sizeof(char*));
  newcmd = parse_args(cmd2);
  execvp(newcmd[0],newcmd);
  dup2(tmpfd,oldfd);
  pclose(file);
  free(newcmd);
}
   
