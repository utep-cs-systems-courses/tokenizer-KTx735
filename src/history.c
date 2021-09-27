#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str)
{
  Item *temp = list->root;
  Item *add = malloc(sizeof(Item));
  add->str = str;

  while (temp->next != NULL)
    {
    temp = temp->next;
  }
  temp->next = add; 
  temp->next->id = temp->id + 1;
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;

  while (temp != 0) { // Traverse whole list
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return "id not found";
}

void print_history(List *list)
{
  Item *temp = list->root->next;

  while (temp != NULL)
    {
    printf("%d.-  %s\n",temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp1 = list->root->next;
  Item *temp2 = list->root->next;

  while (temp1 != NULL)
    {
    temp2 = temp2->next; /* Advance to next Item */
    free(temp1); /* Free previous Item */
    temp1 = temp2; /* Advance to next Item */
  }
  free(list);
}
