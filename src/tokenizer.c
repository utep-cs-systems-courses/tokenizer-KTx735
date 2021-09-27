#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if (c != '\t' && c != ' ' && c != '\0')
    {
      return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  int start = 0;
  while (space_char(str[start]))
    start++;
  return &str[start];
}

char *word_terminator(char *word){
  word = word_start(word);
  int end = 0;
  while (non_space_char(word[end]))
    end++;
  return &word[end];
}

int count_words(char *str){
  int counter = 0;

  while(*str != '\0')
    {
      str = word_terminator(str);
      counter++;
    }
  if(space_char(*(str-1)))
      return counter -1;
  return counter;
}

char *copy_str(char *inStr, short len){
  char *str = malloc((len+1) * sizeof(char));
  int i;
  
  for (i = 0; i < len; i++) {
    str[i] = inStr[i];
  }
  str[i] = '\0';
  return str;
}

char **tokenize(char* str)
{
  int numWords = count_words(str);
  char **tokens = malloc((numWords+1) * sizeof(char *));
  char *p = str;
  int i;
  
  for (i = 0; i < numWords; i++) {
    p = word_start(p);
    int length = word_length(p);
    tokens[i] = copy_str(p, length);
    p = word_terminator(p);
  }
  tokens[i] = 0;
  return tokens;
}

int word_length(char *str)
{
  int length = 0;
  int i;
  
  for (i = 0; *(str+i) != '\0'; i++) {
    if (non_space_char(*(str+i))) {
      length += 1;
    }
    else {
      break;
    }
  }
  return length;
}

void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s\n",tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  int i;
  
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
