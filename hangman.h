/**
 * @file hangman.h
 * Header file for the hangman program;
 * Defines the Board type and printBoard method.
 *
 * @author Justin Schwab (github.com/jgschwab)
 */

/** The width of the game window */
#define WIDTH 60
/** The number of letters in the alphabet */
#define ALPHABET_SIZE 26
/** 
 * The padding to place above each print
 * of the game screen
 */
#define PADDING 40

/** The default buffer size for input strings */
#define BUFFER_SIZE 256

/**
 * The strcuture definition of a game Board
 */
struct gameBoardTag{
  char word[WIDTH - 3];
  char usedLetters[ALPHABET_SIZE + 1];
  int wrongGuesses;
};
typedef struct gameBoardTag Board;

/**
 * The function that prints the board in its current state.
 * @param board The board to print, by pointer
 */
void printBoard(Board *board, char * options);

char * getTheme(char code);
