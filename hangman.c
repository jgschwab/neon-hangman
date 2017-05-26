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
  system("clear");
  printf("\e[94m\u2554");
  for(int i = 0; i < WIDTH - 2; i++){
    printf("\u2550");
  }
  printf("\u2557");
  
  
  printf("\n\u2551                 Welcome to \e[1m\e[95mNEON "
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
         "[0] - \e[93measy words\e[0m                    [7] - \e[93manimals"
         "        \e[94m\u2551\n\u2551 \e[0m"
         "[1] - \e[93mharder words\e[0m                  [8] - \e[93mastronomy"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[2] - \e[93mcommon words\e[0m                  [9] - \e[93manatomy"
         "        \e[94m\u2551\n\u2551 \e[0m"
         "[3] - \e[93mcompound words\e[0m                [A] - \e[93mcomputers"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[4] - \e[93mverbs\e[0m                         [B] - \e[93mcountries"
         "      \e[94m\u2551\n\u2551 \e[0m"
         "[5] - \e[93mnouns\e[0m                         [C] - \e[93melements"
         "       \e[94m\u2551\n\u2551 \e[0m"
         "[6] - \e[93madjectives\e[0m                    [D] - \e[93mlandforms"
         "      \e[94m\u2551\n");  
         
  printf("\u255A");       
  for(int i = 0; i < WIDTH - 2; i++){
    printf("\u2550");
  }
  printf("\u255D\n\e[91mTheme code: \e[0m\e[1m");
  
  char options[BUFFER_SIZE];
  scanf("%s", options);
  if(strlen(options) > 14){
    printf("Your theme string is too long\n");
    exit(1);
  }
  
  system("echo \"\" > lists/customList.txt"); //clears file
  bool pickedTheme = false;
  
  int i = 0;
  char optionsFiltered[15] = "";
  
  printf("Word list includes:\n\e[93m");
  if(strpbrk(options, "0")){
    system("cat lists/easy.txt >> lists/customList.txt");
    printf("easy words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '0';
  }
  if(strpbrk(options, "1")){
    system("cat lists/hard.txt >> lists/customList.txt");
    printf("harder words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '1';
  }
  if(strpbrk(options, "2")){
    system("cat lists/common.txt >> lists/customList.txt");
    printf("common words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '2';
  }
  if(strpbrk(options, "3")){
    system("cat lists/compound.txt >> lists/customList.txt"); 
    printf("compound words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '3';
  } 
  if(strpbrk(options, "4")){
    system("cat lists/verbs.txt >> lists/customList.txt");
    printf("verbs\n");
    pickedTheme = true;
    optionsFiltered[i++] = '4';
  }
  if(strpbrk(options, "5")){
    system("cat lists/nouns.txt >> lists/customList.txt");
    printf("nouns\n");
    pickedTheme = true;
    optionsFiltered[i++] = '5';
  }
  if(strpbrk(options, "6")){
    system("cat lists/adjectives.txt >> lists/customList.txt");
    printf("adjectives\n");
    pickedTheme = true;
    optionsFiltered[i++] = '6';
  }
  if(strpbrk(options, "7")){
    system("cat lists/animals.txt >> lists/customList.txt");
    printf("animals\n");
    pickedTheme = true;
    optionsFiltered[i++] = '7';
  }
  if(strpbrk(options, "8")){
    system("cat lists/astronomy.txt >> lists/customList.txt");  
    printf("astronomy words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '8';
  }
  if(strpbrk(options, "9")){
    system("cat lists/anatomy.txt >> lists/customList.txt");  
    printf("anatomy words\n");
    pickedTheme = true;
    optionsFiltered[i++] = '9';
  }
  if(strpbrk(options, "A") || strpbrk(options, "a")){
    system("cat lists/computers.txt >> lists/customList.txt");  
    printf("computer words\n");
    pickedTheme = true;
    optionsFiltered[i++] = 'A';
  }
  if(strpbrk(options, "B") || strpbrk(options, "b")){
    system("cat lists/countries.txt >> lists/customList.txt");  
    printf("countries\n");
    pickedTheme = true;
    optionsFiltered[i++] = 'B';
  }
  if(strpbrk(options, "C") || strpbrk(options, "c")){
    system("cat lists/elements.txt >> lists/customList.txt");
    printf("elements\n");
    pickedTheme = true;
    optionsFiltered[i++] = 'C';
  }
  if(strpbrk(options, "D") || strpbrk(options, "d")){
    system("cat lists/landforms.txt >> lists/customList.txt");
    printf("landforms\n");
    pickedTheme = true;
    optionsFiltered[i++] = 'D';
  }  
  
  if(!pickedTheme){
    printf("Easy words - the default list, since you didn't\n"
           "select at least one list\n");
    system("cat lists/easy.txt > lists/customList.txt");
    optionsFiltered[i++] = '0';
  }
  
  optionsFiltered[i] = '\0';
  
  printf("\n\e[95mStarting Game");
  for(int i = 0; i < 47; i++){
    unsigned int endTime = clock() + (unsigned int)(CLOCKS_PER_SEC * 0.05);
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
    printBoard(&board, optionsFiltered);
    bool won = false;
    printf("\e[95mLetter to submit: ");
    while(!won && board.wrongGuesses < 7){
      scanf("%s", ch);
      if(strlen(ch) != 1){
        printBoard(&board, optionsFiltered);
        printf("\e[95mPlease guess ONE letter: ");
        continue;
      }
      char letter[2] = {tolower(ch[0]), '\0'};
      
      if(letter[0] < 'a' || letter[0] > 'z'){
        printBoard(&board, optionsFiltered);
        printf("Not a letter. Try another: ");
        continue;
      }
      
      //Check to see if letter has already been guessed
      if(strpbrk(board.usedLetters, letter)){ 
        printBoard(&board, optionsFiltered);
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
      
      printBoard(&board, optionsFiltered);
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
    while(strcmp(playAgain, "y") && strcmp(playAgain, "n") && 
          strcmp(playAgain, "Y") && strcmp(playAgain, "N") &&
          strcmp(playAgain, "yes") && strcmp(playAgain, "no") &&
          strcmp(playAgain, "Yes") && strcmp(playAgain, "No") &&
          strcmp(playAgain, "YES") && strcmp(playAgain, "NO")){
      printf("yeah, I don't know what that means.\nTry again, buddy (y/n): ");
      scanf("%s", playAgain);
    }
    
  }
  
  printf("You won %d out of %d games (%d%%)\n", 
      wins, total, (int)(wins * 100.0 / total));
  
  return EXIT_SUCCESS;
}


// PRINT THE GAME DISPLAY BOARD
void printBoard(Board *board, char * options){
  system("clear");
  
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
  char *t_down = "\u2566";
  char *t_up = "\u2569";
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
  printf("%s\n%s\e[1m", vert, vert);
  
  for(int i = 0; i < strlen(board->word); i++){
    char ch[2] = {board->word[i], '\0'};
    if(strpbrk(board->usedLetters, ch))
      printf(" \e[96m%c", board->word[i]);
    else
      printf(" \e[0m\e[1m_");
  }
  
  
  for(int i = 0; i < WIDTH - 2 - (2 * strlen(board->word)); i++){
    printf(" ");
  }
  printf("\e[0m%s\n%s", vert, t_right);
  
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
  
  for(int i = 0; i < 19; i++){
    printf("%s", horz);
  }
  printf("%s", t_down);
  for(int i = 0; i < 38; i++){
    printf("%s", horz);
  }
  printf("%s\n%s", t_left, vert);
  
  for(int i = 0; i < 19; i++){
    printf(" ");
  }
  printf("%s", vert);
  // print word list
  char wordLists[] = " Word List(s):";
  printf("%s", wordLists);
  for(int i = 0; i < ((WIDTH - 1) / 3 * 2) - strlen(wordLists); i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  //**************
  printf("   \e[1m_____\e[0m");
  for(int i = 0; i < 11; i++){
    printf(" ");
  }
  printf("%s", vert);
  for(int i = 0; i < 38; i++){
    printf(" ");
  }
  printf("%s\n%s", vert, vert);
  
  //*************
  printf("   \e[1m|   |\e[0m           %s", vert);
  printf(" \e[93m%s\e[0m", getTheme(options[0]));
  if(strlen(options) > 1){
    for(int i = 0; i < 18 - strlen(getTheme(options[0])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[1]));
    for(int i = 0; i < 18 - strlen(getTheme(options[1])); i++){
      printf(" ");
    }
  }
  else{
    for(int i = 0; i < 37 - strlen(getTheme(options[0])); i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, vert);
  
  //**********
  printf("   \e[1m|   ");
  if(board->wrongGuesses > 0)
    printf("O           \e[0m%s", vert);
  else
    printf("            \e[0m%s", vert);
  if(strlen(options) > 2){
    printf(" \e[93m%s\e[0m", getTheme(options[2]));
  }
  
  if(strlen(options) > 3){
    for(int i = 0; i < 18 - strlen(getTheme(options[2])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[3]));
    for(int i = 0; i < 18 - strlen(getTheme(options[3])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 3){
    for(int i = 0; i < 37 - strlen(getTheme(options[2])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|  ");
  if(board->wrongGuesses > 1)
    if(board->wrongGuesses > 2)
      if(board->wrongGuesses > 3)
        printf("/|\\          \e[0m%s", vert);
      else
        printf("/|           \e[0m%s", vert);
    else
      printf("/            \e[0m%s", vert);
  else
    printf("             \e[0m%s", vert);
  printf("\e[0m");
  if(strlen(options) > 4){
    printf(" \e[93m%s\e[0m", getTheme(options[4]));
  }
  
  if(strlen(options) > 5){
    for(int i = 0; i < 18 - strlen(getTheme(options[4])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[5]));
    for(int i = 0; i < 18 - strlen(getTheme(options[5])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 5){
    for(int i = 0; i < 37 - strlen(getTheme(options[4])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, vert);
  
  
  printf("   \e[1m|   ");
  if(board->wrongGuesses > 4)
    printf("|           \e[0m%s", vert);
  else
    printf("            \e[0m%s", vert);
    
    
  if(strlen(options) > 6){
    printf(" \e[93m%s\e[0m", getTheme(options[6]));
  }
  
  if(strlen(options) > 7){
    for(int i = 0; i < 18 - strlen(getTheme(options[6])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[7]));
    for(int i = 0; i < 18 - strlen(getTheme(options[7])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 7){
    for(int i = 0; i < 37 - strlen(getTheme(options[6])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, vert);
  
  printf("   \e[1m|  ");
  if(board->wrongGuesses > 5)
    if(board->wrongGuesses > 6)
      printf("/ \\          \e[0m%s", vert);
    else
      printf("/            \e[0m%s", vert);
  else
    printf("             \e[0m%s", vert);
  
  if(strlen(options) > 8){
    printf(" \e[93m%s\e[0m", getTheme(options[8]));
  }
  if(strlen(options) > 9){
    for(int i = 0; i < 18 - strlen(getTheme(options[8])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[9]));
    for(int i = 0; i < 18 - strlen(getTheme(options[9])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 9){
    for(int i = 0; i < 37 - strlen(getTheme(options[8])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, vert);
  
  
  printf("   \e[1m|               \e[0m%s", vert);
  
  if(strlen(options) > 10){
    printf(" \e[93m%s\e[0m", getTheme(options[10]));
  }
  if(strlen(options) > 11){
    for(int i = 0; i < 18 - strlen(getTheme(options[10])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[11]));
    for(int i = 0; i < 18 - strlen(getTheme(options[11])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 11){
    for(int i = 0; i < 37 - strlen(getTheme(options[10])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  
  printf("%s\n%s", vert, vert);
  
  printf(" \e[1m__|____\e[0m           %s", vert);
  if(strlen(options) > 12){
    printf(" \e[93m%s\e[0m", getTheme(options[12]));
  }
  if(strlen(options) > 13){
    for(int i = 0; i < 18 - strlen(getTheme(options[12])); i++){
      printf(" ");
    }
    printf(" \e[93m%s\e[0m", getTheme(options[13]));
    for(int i = 0; i < 18 - strlen(getTheme(options[13])); i++){
      printf(" ");
    }
  }else if(strlen(options) == 13){
    for(int i = 0; i < 37 - strlen(getTheme(options[12])); i++){
      printf(" ");
    }
  }else{
    for(int i = 0; i < 38; i++){
      printf(" ");
    }
  }
  printf("%s\n%s", vert, sw_corner);
  
  for(int i = 0; i < 19; i++){
    printf("%s", horz);
  }
  printf("%s", t_up);
  for(int i = 0; i < 38; i++){
    printf("%s", horz);
  }
  
  printf("%s\n", se_corner);
}

char * getTheme(char code){
  switch(code){
    case '0':
      return "easy";
    case '1':
      return "harder";
    case '2':
      return "common";
    case '3':
      return "compound";
    case '4':
      return "verbs";
    case '5':
      return "nouns";
    case '6':
      return "adjectives";
    case '7':
      return "animals";
    case '8':
      return "astronomy";
    case '9':
      return "anatomy";
    case 65:
      return "computers";
    case 66:
      return "countries";
    case 67:
      return "elements";
    case 68:
      return "landforms";
    default:
      return "\e[91m::ERROR::\e[0m";
  }
}
