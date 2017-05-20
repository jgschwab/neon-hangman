/**
 * @file hangman.c
 * A simple hangman terminal application.
 * Minimum terminal window size for game
 * display is 60 units wide by 22 tall.
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

int main(void){

  printf("\n\n\e[94m\u2554");
  for(int i = 0; i < WIDTH - 2; i++){
    printf("\u2550");
  }
  printf("\u2557");
  
  
  printf("\n\u2551                 \e[93mWelcome to \e[1m\e[95mNEON "
         "HANGMAN\e[0m                  \e[94m\u2551\n"
         "\u2551\e[33m Choose a theme...or \e[4mcombine\e[24m multiple themes "
         "by stringing \e[94m\u2551\n"
         "\u2551\e[33m together multiple theme character codes"
         " ( EX : \"26B5\" ). \e[94m\u2551\n"
         "\u2551\e[33m I will read the first space-delimited string you give me"
         " \e[94m\u2551\n\u2551\e[33m "
         "and ignore any characters that aren't valid theme codes."
         " \e[94m\u2551\n\u255F");
  
  for(int i = 0; i < WIDTH - 2; i++){
    printf("\u2500");
  }
  printf("\u2562\n");
         
  printf("\u2551 \e[32mLANGUAGE-BASED THEMES               "
         "MISCELLANEOUS THEMES \e[94m\u2551\n\u2551 \e[0m"
         "[0] - easy words                    [7] - animals"
         "        \e[94m\u2551\n\u2551 \e[0m"
         "[1] - harder words                  [8] - astronomy"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[2] - common words                  [9] - anatomy"
         "        \e[94m\u2551\n\u2551 \e[0m"
         "[3] - compound words                [A] - computers"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[4] - verbs                         [B] - countries"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[5] - nouns                         [C] - elements"
         "       \e[94m\u2551\n\u2551 \e[0m"
         "[6] - adjectives                    [D] - landforms"
         "      \e[94m\u2551\n");  
         
  printf("\u255A");       
  for(int i = 0; i < WIDTH - 2; i++){
    printf("\u2550");
  }
  printf("\u255D\n\e[91mTheme code: \e[0m\e[1m");
  
  char options[BUFFER_SIZE];
  scanf("%s", options);
  if(strlen(options) > 13){
    printf("Your theme string is too long");
    exit(1);
  }
  
  system("echo \"\" > lists/customList.txt"); //clears file
  bool pickedTheme = false;
  
  printf("Word list includes:\n\e[92m");
  if(strpbrk(options, "0")){
    system("cat lists/easy.txt >> lists/customList.txt");
    printf("easy words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "1")){
    system("cat lists/hard.txt >> lists/customList.txt");
    printf("harder words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "2")){
    system("cat lists/common.txt >> lists/customList.txt");
    printf("common words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "3")){
    system("cat lists/compound.txt >> lists/customList.txt"); 
    printf("compound words\n");
    pickedTheme = true;
  } 
  if(strpbrk(options, "4")){
    system("cat lists/verbs.txt >> lists/customList.txt");
    printf("verbs\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "5")){
    system("cat lists/nouns.txt >> lists/customList.txt");
    printf("nouns\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "6")){
    system("cat lists/adjectives.txt >> lists/customList.txt");
    printf("adjectives\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "7")){
    system("cat lists/animals.txt >> lists/customList.txt");
    printf("animals\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "8")){
    system("cat lists/astronomy.txt >> lists/customList.txt");  
    printf("astronomy words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "9")){
    system("cat lists/anatomy.txt >> lists/customList.txt");  
    printf("anatomy words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "A") || strpbrk(options, "a")){
    system("cat lists/computers.txt >> lists/customList.txt");  
    printf("computer words\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "B") || strpbrk(options, "b")){
    system("cat lists/countries.txt >> lists/customList.txt");  
    printf("countries\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "C") || strpbrk(options, "c")){
    system("cat lists/elements.txt >> lists/customList.txt");
    printf("elements\n");
    pickedTheme = true;
  }
  if(strpbrk(options, "D") || strpbrk(options, "d")){
    system("cat lists/landforms.txt >> lists/customList.txt");
    printf("landforms\n");
    pickedTheme = true;
  }  
  
  if(!pickedTheme)
    printf("Easy words - the default list, since you didn't\n"
           "select at least one list\n");
    
  printf("\n\e[95mStarting Game");
  for(int i = 0; i < 47; i++){
    unsigned int endTime = clock() + (unsigned int)(CLOCKS_PER_SEC * 0.07);
    while((unsigned int)clock() < endTime){}
    printf(".");
    fflush(stdout);
  }
  printf("\n\e[0m");
  
      
  FILE * dict = fopen("lists/customList.txt", "r");
  char word[WIDTH - 3];
  int count = 0;
  while(fscanf(dict, "%s", word) != EOF){
    count++;
  }
  fclose(dict);
  
  Board board;
  
  char ch[BUFFER_SIZE];
  char playAgain[BUFFER_SIZE] = "y";
  int wins = 0;
  int total = 0;
  
  while(tolower(*playAgain) == 'y'){
    dict = fopen("lists/customList.txt", "r");
    srand(time(NULL));
    int r = rand() % count;
    for(int i = 0; i < r; i++){
      fscanf(dict, "%s", word);
    }
    //printf("%s", word);
    fclose(dict);
    board.wrongGuesses = 0;
    strcpy(board.word, word);
    strcpy(board.usedLetters, "");
    printBoard(&board);
    bool won = false;
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
    
    if(won){
      printf("\e[5m\e[1m\e[96mYOU WIN!\e[0m\n");
      wins++;
    }else{
      printf("\e[5m\e[1m\e[91mYOU LOST.\e[0m\n");
      printf("The word was \e[96m%s\e[0m\n", word);
    }
    total++;
    
    printf("Play again (y/n)? ");
    scanf("%s", playAgain);
  }
  
  printf("You won %d out of %d games (%d%%)\n", 
      wins, total, (int)(wins * 100.0 / total));
  
  return EXIT_SUCCESS;
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
  char *nw_corner = "\e[32m\u2554";
  char *ne_corner = "\u2557\e[0m";
  char *sw_corner = "\e[32m\u255A";
  char *se_corner = "\u255D\e[0m";
  char *horz = "\u2550";
  char *vert = "\e[32m\u2551\e[0m";
  char *t_right = "\e[32m\u2560";
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
