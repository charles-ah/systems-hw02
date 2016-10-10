#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node *n)
{
  //printf("printing\n");
  if(n)
    {
      printf("%d ",n->i);
      print_list(n->next);
    }
  else
    printf("\n");
} 

struct node* insert_front(struct node *first, int data)
{
  //struct node x;
  struct node *newFirst = (struct node*)malloc(sizeof(struct node));
  
  //newFirst = &x;
  newFirst->i=data;
  newFirst->next = first;
  //printf("%d\n",(newFirst->next)->i);
  return newFirst;
}

struct node* free_list(struct node* first)
{
  if(first)
    {
      //printf("%d \n",n->i);
      struct node *n = first->next;
      free(first);
      free_list(n);
    }
  else
    //free(first);
    printf("new first after freeing memory: %p\n",first);
    return first;
}

int main()
{
  //struct node x;
  struct node *s = (struct node*) malloc(sizeof(struct node));
  //s=&x;
  s->i=2;
  s->next=0;
  printf("ok\n");
  struct node *s1;
  s=insert_front(s,3);
  s=insert_front(s,4);
  s=insert_front(s,5);
  //printf("%d\n",(s1->next)->i);
  printf("list after adding ints 3,4,5 in that order: ");
  print_list(s);
  free_list(s);
  return 0;
}
