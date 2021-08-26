/*
 * Construct an adjacency list (linked list) for
 * a graph with the specified connections.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node{
    int v;
    link next;
};

link NEW(int v, link next){
    link x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}

int main(int argc, char *argv[]){
    int i, j, V = atoi(argv[1]);
    link adj[V]; // array of linked lists

    // completely disconnected graph
    for (i = 0; i < V; i++)
        adj[i] = NULL;

    // make appropriate connections
    while (scanf("%d %d\n", &i, &j) == 2){
        adj[i] = NEW(j, adj[i]);
        adj[j] = NEW(i, adj[j]);
    }

    printf("Adjacency list:\n");

    for (i = 0; i < V; i++){
        printf("%d: ", i);
        link current = adj[i];
        while(current != NULL){
            printf("%d ", current->v);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}
