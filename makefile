all: sadshell.o
	gcc -o sadshell sadshell.o

sadshell.o: sadshell.c sadshell.h
	gcc -c -g sadshell.c

run: all
	./sadshell < commands

clean:
	rm sadshell
	rm *~
	rm *.o

