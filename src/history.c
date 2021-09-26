#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *list = malloc(sizeOf(List));
  List ->root = malloc(sizeOf(Item));

  return list;
}

void add_history(List *list, char *str)
{
  Item *temp = list->root;
  Item *add = malloc(sizeOf(Item));
  add->str = str;

  while(temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = add;
  temp->next->id = temp->id +;
}

char *get_history(List *list, int id)
{
  Item *temp = list->root->next;

  while(temp != NULL)
    {
      if (id == temp->id) return temp->str;
      temp = temp->next;
    }
  printf("Returned Null");
  return NULL;
}

void print_history(List *list)
{
  Item *temp = list->root->next;

  while(temp != NULL)
    {
      printf("%d.- %s\n", temp->id, temp->str);
      temp = temp->next;
    }
}

void free_history(List *list)
{
  Item *temp1 = list->root->next;
  Item *temp2 = list->root->next;

  while(temp1 != NULL)
    {
      temp2 = temp2->next;
      free(temp1);
      temp1 = temp2;
    }
  free(list);
}
