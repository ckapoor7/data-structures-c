/*
 * Josephus problem: N people decide to elect a leader
 * by arranging themselves in a circle and eliminating
 * the Mth person in the circle, closing ranks as a person
 * drops out. Find the last person remaining.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node* link; // link of the linked list

struct node{ // node of the linked list
    int item;
    link next;
};

int main(int argc, char *argv[]){
    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    link t = malloc(sizeof *t), x = t;
    t->item = 1; // first person is 1
    t->next = t; // point to the same node

    // create a circular linked list with N items
    for (i = 2; i <= N; i++){
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }

    // find the leader
    while (x != x->next){
        for (i = 1; i < M; i++)
            x = x->next;
        x->next = x->next->next; // remove the Mth node
        N--; // size of the list reduces by 1
    }

    printf("The leader is: %d\n", x->item);

}
