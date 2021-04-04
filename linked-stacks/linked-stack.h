#ifndef LINKED_STACK
#define LINKED_STACK
#include <stdbool.h>


struct node{
  int info; //data in the node
  struct node *next; //pointer to the next node
};
  
struct stack_tag{
  struct node *top;
};

void push(int, struct stack_tag*); //make a new node and push it to the linked stack
struct node *make_node(int); //make a new node and insert item
int pop(struct stack_tag*); //pop a node from the stack and return it
bool empty(struct stack_tag*); //check for an empty stack
void push_node(struct node*, struct stack_tag*); //push a node to the linked stack
void pop_node(struct node**, struct stack_tag*); //pop a node from the linked stack
struct stack_tag *init(struct stack_tag*); //initialize an empty linked stack
void print_stack(struct stack_tag*); //print a given linked stack

#endif
