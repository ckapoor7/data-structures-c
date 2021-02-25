#ifndef QUEUE_COUNTER
#define QUEUE_COUNTER
#include <stdbool.h>

struct queue{
  int count; //count number of entries 
  int head;
  int max_size;
  int tail;
  int *arr;
};

void add(int, struct queue*); //Add integer elements to the queue
int delete(struct queue*); //Delete an element from the queue
struct queue* init(int); //Initialize a queue of a given size
bool full(struct queue*); //Check for a full queue
bool empty(struct queue*); //Check for an empty queue
void print(struct queue*); //Print a queue

#endif
