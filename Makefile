CC=gcc
CFLAGS=-Wall -std=c99 -g

hangman: hangman.o

clean:
	rm -f hangman hangman.o

