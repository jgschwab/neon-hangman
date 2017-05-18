CC=gcc
CFLAGS=-Wall -std=c99

hangman: hangman.o

clean:
	rm -f hangman hangman.o

