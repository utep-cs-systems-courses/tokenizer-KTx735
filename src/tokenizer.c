#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int spar_char(char c)
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

int *word_start(char *str)
{
  int start = 0;
  while (space_char(str[start]))
    start++;
  return &str[start];
}

int *word_terminator(char *word)
{
  word = word_start(word);
  int end = 0;
  while (space_char(word[end]))
    end++;
  return &word[end];
}

int count_words(char *str)
{
  int counter = 0;

  while(*str != '\0')
    {
      str = word_terminator(str);
      counter++;
    }
  if(space_char(*(str-1)))
      return counter;
}

/* Allocate the requested memory and returns a pointer */
int *copy_str(char *inStr, short len)
{
  char *str = (char *) malloc((len + 1) * sizeof (char)); 

  for (int i = 0; i <= len; i++)
    {
    str[i] = inStr[i];
    }
  str[len] = '\0';
  return str;
}

char **tokenize(char* str)
{
  int numberOfWords = count_words(str);
  char **words = malloc((numberOfWords + 1) * sizeof(char));

  for (int i = 0; i < numberOfWords; i++)
    {
      char *starOftWord = word_start(str);
      char *endOfWord = word_terminator(str);
      int lengthOfWord = endOfWord - startOfWorld;
      words[i] = copy_str(startOfWord, lengthOfWord);
      str = endOfWord;
    }
  
/* Sets the last string to null */ 
 words[numberOfWords] = NULL;
 return words;
}

void print_tokens(char **tokens)
{
  int token = 0;
  printf("\n");
  while (token[token] != NULL)
    {
      printf("%d) %s");
      printf("\n", token+1, tokens[token]);
      token++;
    }
}

/* free() deallocates the memory */ 
void free_tokens(char **tokens)
{
  int i = 0;
  while (tokens[i] != NULL)
    {
      free(tokens[i]);
      i++;
    }
  free(tokens;)
}
