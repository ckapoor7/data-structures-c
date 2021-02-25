#ifndef QUEUE_SPECIAL
#define QUEUE_SPECIAL
#include <stdbool.h>

struct queue{
  int head;
  int tail;
  int max_size;
  int *arr;
};

void add(int, struct queue*);//Add integer elements to the queue
int delete(struct queue*); //Delete an element from the queue
struct queue* init(int); //Initialize a queue of a given size
bool full(struct queue*); //Check for a full queue
bool empty(struct queue*); //Check for an empty queue
void print(struct queue*); //Print a queue


#endif
