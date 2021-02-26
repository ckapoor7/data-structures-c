#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue-counter.h"

void add(int item, struct queue* queue_ptr){
  if(full(queue_ptr)){
    printf("Queue is full\n");
    exit(1);
  }
  else{
    queue_ptr->count++; //increase count for number of elements
    queue_ptr->tail = (queue_ptr->tail+1)%(queue_ptr->max_size); //ciruclar queue
    queue_ptr->arr[queue_ptr->tail] = item;
    /* printf("Element added:%d\n",item); //Debug print statement*/
  }
}

int delete(struct queue* queue_ptr){
  if (empty(queue_ptr)){
    printf("Empty queue\n");
    exit(1);
    return 0;
  }
  else{
    queue_ptr->count--; //number of elements reduces since we have deleted one
    int elem = queue_ptr->arr[queue_ptr->head];
    queue_ptr->head = (queue_ptr->head+1)%(queue_ptr->max_size);
    /*printf("Deleted element: %d\n",elem); //Debug print statement*/
    return elem;
  }
}

struct queue* init (int max_size){
  struct queue *queue_ptr = malloc(sizeof(struct queue)); //allocate memory for the queue
  queue_ptr->max_size = max_size;
  queue_ptr->count = 0; 
  queue_ptr->head = 0;
  queue_ptr->tail = -1;
  queue_ptr->arr = (int*)malloc(max_size*sizeof(int)); //allocate memory for the array
  return queue_ptr;
}

bool full(struct queue* queue_ptr){
  return queue_ptr->count >= queue_ptr->max_size;
}

bool empty(struct queue* queue_ptr){
  return queue_ptr->count <= 0;
}

void print(struct queue* queue_ptr){
  while(queue_ptr->head<=queue_ptr->tail)
    printf("%d ",queue_ptr->arr[queue_ptr->head++]);
  printf("\n");
}
