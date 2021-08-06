/*
 * An implentation of the Sieve of Eratosthenes (again:P),
 * but this time using dynamic memeory allocation (ie-command line
 * arguments)
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i, j, N = atoi(argv[1]);
    int *a = malloc(N*sizeof(int));

    // Check for null pointer
    if (a == NULL){
        printf("Insufficient memory\n");
        return 0;
    }

    // Standard algorithm follows
    for (i = 2; i < N; i++){ // Set all indices to be 1
        a[i] = 1;
    }

    for (i = 2; i < N; i++)
        if (a[i]) // If the number is prime, all its multiples are composite
            for (j = i; j <= N/i; j++)
                a[i*j] = 0;

    for (i = 2; i < N; i++)
        if (a[i]) // Print all prime numbers
            printf("%4d ", i);
    printf("\n");

    return 0;

}
