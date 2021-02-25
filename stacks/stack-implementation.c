#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack-array.h"

struct stack* init(int max_size){
  struct stack *stack_ptr = malloc(sizeof(struct stack));//allocate memory for the stack
  stack_ptr->max_size = max_size;
  stack_ptr->top = -1;
  stack_ptr->arr = (int*)malloc(max_size*sizeof(int));//allocate memory for the array
  return stack_ptr;
}

bool full(struct stack* stack_ptr){
  return (stack_ptr->top == stack_ptr->max_size-1);//check for max stack size
}


bool empty(struct stack* stack_ptr){
  return (stack_ptr->top == -1);
}


void push(int item, struct stack* stack_ptr){
  if (full(stack_ptr)){
    printf("Stack is full\n");
    exit(1);
    return;
  }
  stack_ptr->arr[++stack_ptr->top] = item; //put new item at the top of the stack
  //  printf("%d pushed into the stack\n",item); //debug print
}
  
int pop(struct stack* stack_ptr){
  if (empty(stack_ptr)){
    printf("Empty stack\n");
    exit(1);
    return 0;
  }
  /* int elem = stack_ptr->arr[stack_ptr->top--]; */
  /* printf("%d popped from the stack\n",elem);//debug print statement */
  /* return elem; */
  return stack_ptr->arr[stack_ptr->top--];
}

void print_stack(struct stack* stack_ptr){ 
  while(!empty(stack_ptr))
    printf("%d ",pop(stack_ptr));
  printf("\n");
}

struct stack* reverse(struct stack* stack_ptr){
  struct stack* rev_stack = init(stack_ptr->max_size);
  while(!empty(stack_ptr))
    push(pop(stack_ptr),rev_stack);
  free(stack_ptr);
  stack_ptr = rev_stack;
  return stack_ptr;
}


struct stack* delete(int elem,struct stack* stack_ptr){
  struct stack* res_stack = init(stack_ptr->max_size);
  while(!empty(stack_ptr)){
    int x = pop(stack_ptr);
    if(elem!=x)
      push(x,res_stack);
  }
  free(stack_ptr);
  stack_ptr = res_stack;
  return stack_ptr;
}
