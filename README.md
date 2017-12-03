# sadshell
By: Rihui Zheng and Jensen Li

## Features:
- All the commands you can use from execvp (ls, echo, ps, etc.)
- Multiple commands in one line, separated by a " ; ". There can be spaces before or after the colon, it works either way.
- cd command (changes working directory)
- exit (exits program)

## Known Bugs:
- With the semicolon, your command can not be super long (like no echo hjfbvkubvkbfwgwgreg ; echo nfjkrebgkebgkwjgwkg)

## Files and Functions:
sadshell.c
        char * strip(char * line);
        char ** fix_semicolons(char * line );
        char **parse_args( char *);
