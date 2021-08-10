/*
 * Generate N random integers between 0 and 999, and use
 * it to build a linked list.
 * Rearrange the nodes of the list so that the numbers
 * are in sorted order.
 */


#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int i, N = atoi(argv[1]);
    struct node heada, headb;
    link t, u, x, a = &heada, b;

    // create a linked list of N elements
    for (i = 0, t = a; i < N; i++){
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
    }

    // print the unsorted list
    printf("Unsorted linked list: ");
    for (i = 0; i < N-1; i++){
        printf("%d -> ",a->item);
        a = a->next;
    }
    printf("%d\n", a->item);

    a = &heada;
    b = &headb;
    b->next = NULL;

    // sort the list
    for (t = a->next; t != NULL; t = u){
        u = t->next;
        for (x = b; x->next != NULL; x = x->next)
            if (x->next->item > t->item)
                break;
        t->next = x->next;
        x->next = t;
    }

    printf("Sorted linked list: ");
    // print the sorted list
    for (i = 0; i < N-1; i++){
        printf("%d -> ",b->item);
        b = b->next;
    }
    printf("%d\n", b->item);

    return 0;
}
