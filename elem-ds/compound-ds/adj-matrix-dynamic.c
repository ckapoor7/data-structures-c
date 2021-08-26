/*
 * A more flexible version of the adjacency matrix
 * representation, where I take the number of vertices
 * as a command line argument.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i, j, V = atoi(argv[1]);
    int adj[V][V];

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
