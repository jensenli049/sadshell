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

    ================char * strip()=================
    Inputs:
	char * line
   	char special
    Returns:
	A 2-D array of chars where each index contains a command

    If line has a given special character, it separates the commands by tthat character. Takes in the string read from input, and returns a 2d array with a separate command in each index.
        
    ================char ** fix_char()=================
    Inputs:
        char * line
    Returns:
        A 2-D array of chars where each index contains a command
    If line has a semicolon, it separates the commands by semicolons. Takes in the string read from input, and returns a 2d array with a separate command in each index.

    ================char ** parse_args()=================
    Inputs:
        char * line
    Returns:
        A 2-D array where each index contains  separate argument
    This function takes in the string containing the entire command, separates the arguments by spaces, and returns a 2d array with separate arguments in each index.





