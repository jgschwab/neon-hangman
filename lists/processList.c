#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  printf("input file: ");
  char fileName[100];
  scanf("%s", fileName);
  FILE * in = fopen(fileName, "r");
  printf("output file: ");
  scanf("%s", fileName);
  FILE * out = fopen(fileName, "w");
  char wordIn[100];
  while(fscanf(in, "%s", wordIn) != EOF){
    char wordOut[100];
    int len = strlen(wordIn);
    if(len > 2){
      int i;
      for(i = 0; i < len; i++){
        if(wordIn[i] == '-'){
          i = 0;
          break;
        }
        wordOut[i] = tolower(wordIn[i]);
      }
      wordOut[i] = '\0';
      fprintf(out, "%s\n", wordOut);
    }
  }
  fclose(in);
  fclose(out);
  return 0;
}
