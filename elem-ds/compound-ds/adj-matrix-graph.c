/*
 * Read a set of edges defining an undirected graph,
 * and use it to build an adjacency matrix representation.
 * We assume a digraph here, and set a[i][j] = a[j][i] = 1
 * if an edge exists between the two, otherwise its set to 0.
 * An input of the form: 'i j' is assumed, where i and j are the
 * connected vertices. The input sequence can be interrupted
 * by entering an invalid character.
 */

#include <stdio.h>
#include <stdlib.h>

#define V 8

int main(){
    int i, j, adj[V][V];

    // completely disconnected graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = 0;

    // each vertex is connected to itself
    for (i = 0; i < V; i++)
        adj[i][i] = 1;

    // make appropriate connections
    while (scanf("%d %d\n", &i, &j) == 2){
        adj[i][j] = 1;
        adj[j][i] = 1;
    }

    printf("Adjacency matrix:\n");

    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
