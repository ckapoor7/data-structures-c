#include "linked-stack.h"
#include <stdio.h>
#include <stdlib.h>


struct stack_tag *init(struct stack_tag *stack_ptr){
  stack_ptr->top = NULL; //initialize the top of the stack to be empty
  return stack_ptr;
}

void push_node(struct node *node_ptr, struct stack_tag *stack_ptr){
  if(node_ptr == NULL){ //error handling 
    printf("Attempt to push a non-existent node\n");
    exit(1);
  }
  else{
    node_ptr->next = stack_ptr->top;
    stack_ptr->top = node_ptr;
  }
}

void pop_node(struct node **node_ptr, struct stack_tag *stack_ptr){
  if(stack_ptr->top == NULL){
    printf("Empty stack\n");
    exit(1);
  }
  else{
    *node_ptr = stack_ptr->top;
    stack_ptr->top = (*node_ptr)->next;
  }
}


struct node *make_node(int data){
  struct node *n;

  if((n = (struct node *)malloc(sizeof(struct node *))) == NULL){
    printf("Exhausted memory\n");
    exit(1);
  }
  else{
  n->info = data;
  n->next = NULL;
  }
  return n;
}


bool empty(struct stack_tag* stack_ptr){
  return (stack_ptr->top==NULL);
}


void push(int data, struct stack_tag* stack_ptr){
  push_node(make_node(data), stack_ptr);
  //printf("Pushed %d\n", data);
}


int pop(struct stack_tag* stack_ptr){
  struct node *n;
  pop_node(&n, stack_ptr); //pop the node
  int res = n->info;
  free(n); //all done with the concerned node
  //printf("Popped %d\n", res);
  return res;
}


int main(){
  struct stack_tag *my_stack = init(my_stack);
  return 0;
}
