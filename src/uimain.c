#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char input[100];
  char sentence[100];
  List *history = init_history();
  char **words;

  int programExec = 1;
  
  printf("Project 1: Tokenizer");
  printf("\nMenu:");

  while(programExec){

  printf("\nType the number or letter symbol\n");
  printf("1. Write sentence for history:\n");
  printf("2. See history\n");
  printf("!. Followed by a number to recall certain history\n");
  printf("q. to quit\n");

  printf("Selection: ");
  /* Enter input*/
  scanf("%s", input);

  if (input[0] == '1')
    {
    printf("Input your sentence:\n$");
    printf("\n $  ");
    scanf("\n");
    scanf("%[^\n]", sentence);
    add_history(history, sentence);
    printf("\nSentence added to history\n");
    }
  else if (input[0] == '2')
    {
    print_history(history);
    }
  else if (input[0] == '!')
    {
    char *hist = get_history(history,atoi(input+1));
    char **tokens = tokenize(hist);
    
    printf("Retrieved history: %s\n", hist);
    printf("Retrieved history tokenized:\n");
    print_tokens(tokens);
    free_tokens(tokens);
  }
  else if (input[0] == 'q')
    {
      printf("Program Ended\n");
      free_history(history);
      return 0;
    }
  else
    {
      printf("\nInsert valid option\n");
    }
  }
}


