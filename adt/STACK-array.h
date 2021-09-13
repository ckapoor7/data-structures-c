#include <stdlib.h>
#include "Item.h"

#ifndef STACK_ARRAY
#define STACK_ARRAY

static Item *s;
static int N;

// initialize a stack of given size
void STACKinit(int maxN){
    s = malloc(maxN * sizeof(Item));
    N = 0;
}

// check for an empty stack
int STACKempty(){
    return N == 0;
}

// push items to the stack
void STACKpush(Item item){
    s[N++] = item;
}

// retrieve(pop) items from the stack
Item STACKpop(){
    return s[--N];
}


#endif
