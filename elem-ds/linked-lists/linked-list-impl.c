#include "list.h"
#include <stdio.h>
#include <stdlib.h>

link freeList;


// initialize N nodes on the linked list
void initNodes(int N){
    int i;
    freeList = malloc((N+1)*sizeof( *freeList));
    for (i = 0; i < N; i++)
        freeList[i].next = &freeList[i+1];
    freeList[N].next = NULL;
}


// create a new node with value i
link newNode(int i){
    link x = deleteNext(freeList);
    x->item = i;
    x->next = x;
    return x;
}


// free the pointer of a node
void freeNode(link x){
    insertNext(freeList, x);
}


// insert a node after link t
void insertNext(link x, link t){
    t->next = x->next;
    x->next = t;
}


// delete the node after link x (return the deleted node)
 link deleteNext(link x){
    link t = x->next;
    x->next = t->next;
    return t;
}


// return the node after x
link Next(link x){
    return x->next;
}

// return the item corresponding to link x
int Item(link x){
    return x->item;
}
