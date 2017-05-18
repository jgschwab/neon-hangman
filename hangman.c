/**
 * @file hangman.c
 * A simple hangman terminal application.
 * For best graphical performance, adjust 
 * terminal window to 60 wide by 20 tall.
 *
 * @author Justin Schwab (github.com/jgschwab)
 */
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "hangman.h"

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("usage: ./hangman <dictionaryFile>\n");
    exit(1);
  }
  
  FILE * dict = fopen(argv[1], "r");
  if(!dict){
    printf("File doesn't exist\n");
  }
  
  char word[WIDTH - 3];
  int count = 0;
  
  while(fscanf(dict, "%s", word) != EOF){
    count++;
  }
  fclose(dict);
  
  dict = fopen(argv[1], "r");
  srand(time(NULL));
  int r = rand() % count;
  for(int i = 0; i < r; i++){
    fscanf(dict, "%s", word);
  }
  
  printf("%s", word);
  fclose(dict);
  
  Board board;
  board.wrongGuesses = 0;
  strcpy(board.word, word);
  strcpy(board.usedLetters, "");
  printBoard(&board);
  bool won = false;
  char ch[100];
  printf("\e[95mLetter to submit: ");
  
  while(!won && board.wrongGuesses < 7){
    scanf("%s", ch);
    if(strlen(ch) != 1){
      printBoard(&board);
      printf("\e[95mPlease guess ONE letter: ");
      continue;
    }
    char letter[2] = {tolower(ch[0]), '\0'};
    
    //Check to see if letter has already been guessed
    if(strpbrk(board.usedLetters, letter)){ 
      printBoard(&board);
      printf("\e[95mLetter already guessed. Try another: ");
      continue;
    }
    
    //Check if letter is in word or not
    if(!strpbrk(board.word, letter)){
      board.wrongGuesses++;
    }
    //Append letter to guessed letters
    strcat(board.usedLetters, letter);
    
    won = true;
    for(int i = 0; i < strlen(board.word); i++){
      letter[0] = board.word[i];
      letter[1] = '\0';
      if(!strpbrk(board.usedLetters, letter))
        won = false;
    }
    
    printBoard(&board);
    printf("\e[95mLetter to submit: ");
  }
  if(won)
    printf("\e[5m\e[1m\e[96mYOU WIN!\e[0m\n");
  else{
    printf("\e[5m\e[1m\e[91mYOU LOST.\e[0m\n");
    printf("The word was \e[96m%s\e[0m\n", word);
  }
  return 0;
}


void printBoard(Board *board){
  for(int i = 0; i < PADDING; i++){
    printf("\n");
  }
  
  for(int i = 0; i < WIDTH / 2 - 6; i++){
    printf(" ");
  }
  printf("\e[1m\e[95m%s\e[0m\n", "~ N E O N ~");
  for(int i = 0; i < WIDTH / 2 - 9; i++){
    printf(" ");
  }
  printf("\e[1m\e[95m%s\e[0m\n", "~ H A N G M A N ~");
  char *nw_corner = "\e[92m\u2554";
  char *ne_corner = "\u2557\e[0m";
  char *sw_corner = "\e[92m\u255A";
  char *se_corner = "\u255D\e[0m";
  char *horz = "\u2550";
  char *vert = "\e[92m\u2551\e[0m";
  char *t_right = "\e[92m\u2560";
  char *t_left = "\u2563\e[0m";
  printf("%s", nw_corner);
  for(int i = 0; i < WIDTH - 2; i++){
    printf("%s", horz);
  }
  printf("%s\n%s", ne_corner, vert);
  
  printf(" Word \u21B4");
  for(int i = 0; i < WIDTH - 9; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  for(int i = 0; i < strlen(board->word); i++){
    char ch[2] = {board->word[i], '\0'};
    if(strpbrk(board->usedLetters, ch))
      printf(" \e[96m%c\e[0m", board->word[i]);
    else
      printf(" _");
  }
  for(int i = 0; i < WIDTH - 2 - (2 * strlen(board->word)); i++){
    printf(" ");
  }
  printf("%s\n%s", vert, t_right);
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf("%s", horz);
  }
  printf("%s\n%s Used:\e[91m", t_left, vert);
  
  for(int i = 0; i < strlen(board->usedLetters); i++){
    printf(" %c", board->usedLetters[i]);
  }
  printf("\e[0m");
  
  for(int i = 0; i < WIDTH - 8 - (2 * strlen(board->usedLetters)); i++){
    printf(" ");
  }
  printf("%s\n%s", vert, t_right);
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf("%s", horz);
  }
  printf("%s\n%s", t_left, vert);
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m_____\e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|   |\e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|   ");
  if(board->wrongGuesses > 0)
    printf("O");
  else
    printf(" ");
  printf("\e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|  ");
  if(board->wrongGuesses > 1)
    if(board->wrongGuesses > 2)
      if(board->wrongGuesses > 3)
        printf("/|\\");
      else
        printf("/| ");
    else
      printf("/  ");
  else
    printf("   ");
  printf("\e[0m");
  for(int i = 0; i < WIDTH - 11; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|   ");
  if(board->wrongGuesses > 4)
    printf("|");
  else
    printf(" ");
  printf("\e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|  ");
  if(board->wrongGuesses > 5)
    if(board->wrongGuesses > 6)
      printf("/ \\");
    else
      printf("/  ");
  else
    printf("   ");
  printf("\e[0m");
  for(int i = 0; i < WIDTH - 11; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|    \e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  printf(" \e[1m__|____\e[0m");
  for(int i = 0; i < WIDTH - 10; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, sw_corner);
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf("%s", horz);
  }
  printf("%s\n", se_corner);
}
