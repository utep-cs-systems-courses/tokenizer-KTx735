#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int spar_char(char c)
{
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c != '\t' && c != ' ' && c != '\o')
    {
      return 1;
  }
  return 0;
}

int *word_start(char *str)
{
  int start = 0;
  while(space_char(str[start]))
    start++;
  return &str[start];
}

int *word_terminator(char *word)
{
  word = word_start(word);
  int end = 0;
  while(space_char(word[end]))
    end++;
  return &word[end];
}
