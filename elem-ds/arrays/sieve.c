/*
 * A simple program that uses arrays to
 * implement the "Sieve of Eratosthenes" algorithm.
 * The idea is simple: I initialize all array elements a[i]
 * to 1 if 'i' is prime and 0 if it is non-prime. Initially,
 * all elements are set to 1.
 * Note that the runtime efficiency of this algorithm is O(n),
 * as opposed to standard loops which yields O(n^(3/2)).
 */

#include <stdio.h>

#define N 10000

int main(){
    int i, j, a[N];

    for (i = 2; i < N; i++){ // Set all indices to be 1
        a[i] = 1;
    }

    for (i = 2; i < N; i++)
        if (a[i]) // If the number is prime, all its multiples are composite
            for (j = i; j < N/i; j++)
                a[i*j] = 0;

    for (i = 2; i < N; i++)
        if (a[i]) // Print all prime numbers
            printf("%4d ", i);
    printf("\n");

    return 0;
}
