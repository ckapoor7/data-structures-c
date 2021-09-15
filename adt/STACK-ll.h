/*
 * The pushdown stack is represented by the pointer 'head'
 * which points to the most recently inserted item.
 * For popping the stack, we discard the item at the front
 * of the list which is done by settting 'head' from its
 * corresponding link.
 * Lastly, for pushing a new item, a link is created at the
 * beginning of the stack, and making the pointer 'head' point
 * towards it.
 */

#include <stdlib.h>
#include "Item.h"

#ifndef STACK_LL
#define STACK_LL

typedef struct STACKnode* link;
static link head;
struct STACKnode {
    Item item;
    link next;
};


// Insert a new node
link NEW(Item item, link next){
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

// Initialize an empty stack of a given size
void STACKinit(int maxN){
    head = NULL;
}

// Check for an empty stack
int STACKempty(){
    return head == NULL;
}

// Push an item to the stack
void STACKpush(Item item){
    head = NEW(item, head);
}

// Pop an item from the stack
Item STACKpop(){
    Item item = head->item;
    link t = head->next;
    free(head);
    head = t;
    return item;
}

#endif
