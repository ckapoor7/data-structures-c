/*
 * A simple abstraction interface for the union-find
 * algorithm. The underlying structure uses a forest of
 * trees which is represented by two arrays.
 */


#include <stdio.h>
#include <stdlib.h>
#include "UF.h"

int main(int argc, char *argv[]){
    int p, q, N = atoi(argv[1]);
    UFinit(N);
    while (scanf("%d %d", &p, &q) == 2)
        if (!UFfind(p, q)){
            UFunion(p,q);
            printf(" %d %d\n", p, q);
        }
}
