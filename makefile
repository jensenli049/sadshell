all: sadshell.c sadshell.h
	gcc -o sadshell sadshell.c sadshell.h

run: all
	./sadshell < commands

clean:
	rm sadshell
	rm *~
	rm *.o
