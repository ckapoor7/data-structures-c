/*
 * A program to simulate coin flips (or more formally,
 * a bunch of Bernoulli trials).
 * We carry out a coinf flip N times (and expect to get N/2 heads).
 * The experiment is run M times (N, M being command line arguments).
 * An array 'f' is used to keep a note of the frequency of occurence
 * of 'i' heads.
 * A histogram is printed (one asterisk = 10 occurences) to analyze
 * the results.
 */

#include <stdio.h>
#include <stdlib.h>


// Flip a coin
int heads(){
    return rand() < RAND_MAX/2;
}


int main(int argc, char *argv[]){
    int i, j, cnt, N = atoi(argv[1]), M = atoi(argv[2]);
    int *f = malloc((N+1)*sizeof(int));

    // Initialize to 0 frequency
    for (j = 0; j <= N; j++)
        f[j] = 0;

    for (i = 0; i < M; i++, f[cnt]++)
        for (cnt = 0, j = 0; j <= N; j++)
            if (heads())
                cnt++;

    for (j = 0; j <= N; j++){
        printf("%2d ", j);
        for (i = 0; i < f[j]; i+=10)// Print a '*' after every 10 occurences
            printf("*");
        printf("\n");
    }

    return 0;
}
