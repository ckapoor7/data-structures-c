#ifndef STACK_ARRAY
#include <stdbool.h>
#define STACK_ARRAY

struct stack{
  int top; //Keep track of number of elements in the stack
  int max_size;
  int *arr;
};

struct stack* init(int); //Intialize the stack for a given size
bool full(struct stack*); //Check for a full stack
bool empty(struct stack*); //Check for an empty stack
void push(int, struct stack*); //Push elements into the stack
int pop(struct stack*); //Pop elements from the stack
void print_stack(struct stack*); //Print all elements of a given stack
struct stack* reverse(struct stack*); //Reverse a stack
struct stack* delete(int,struct stack*); //Delete all occurences of a particular element from a stack, without changing the order of the other elements

#endif
