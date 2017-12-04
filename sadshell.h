#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

char * strip(char * line);
char ** fix_char(char * line, char *special );
char **parse_args( char *);
int pipe_chr( char * chr );
void piping( char * line, int schr );
