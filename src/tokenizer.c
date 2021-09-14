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
