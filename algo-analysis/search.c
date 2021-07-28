#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

/*
  A runtime comparison of sequential and binary search
  for large values (order of 10^3-10^6) and huge values
  (order of 10^9).
  Of course, due to practical considerations, I limit the
  size to be much smaller than the ones mentioned above.
*/


int seq_search(int a[], int v, int l, int r){
    /*
      Check whether a number 'v' is among a previously
      set of stored numbers in a[1]...a[r].
      Returns the index where the element is found
      and -1 when the search fails
    */
    int i;
    for (i = 1; i <= r; i++){
        if (v == a[i])
            return i;
    }
    return -1;
}


int bin_search(int a[], int v, int l, int r){
    /*
      Same as the previous function, but with binary
      search
    */
    while (r >= 1){
        int m = (l+r)/2;
        if (v == a[m])
            return m;
        if (v < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}


int gen_rand(int low, int high){
    /*
      Generates random numbers within a specific
      range.
    */
    return (rand() % (low-high+1)) + low;
}


int compare_func (const void *a, const void *b){
    // Function for comparing two integers, which is passed to qsort
    return (*(int*)a - *(int*)b);
}

int main(){
    int large_arr[1000], huge_arr[100000];
    double exec_time = 0;
    clock_t t1, t2, t3, t4;
    t1 = clock();
    t2 = clock();
    t3 = clock();
    t4 = clock();

    // Create a large array with elements from 0-100
    for (int i = 0; i < 1000; i++)
        large_arr[i] = gen_rand(0, 100);

    //Create a huge array with elements from 0-100
    for (int j = 0; j < 100000; j++)
        huge_arr[j] = gen_rand(0, 100);

    // Large sequential search
    printf("Sequential search with 1000 elements...\n");
    seq_search(large_arr, 5, 0, 999);
    t1 = clock() - t1;
    exec_time = ((double)t1)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    // Large binary search
    printf("Binary search with 1000 elements...\n");
    qsort(large_arr, 1000, sizeof(int), compare_func); // Sort for binary search
    bin_search(large_arr, 5, 0, 999);
    t2 = clock() - t2;
    exec_time = ((double)t2)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    // Huge sequential search
    printf("Sequential search with 100000 elements...\n");
    seq_search(huge_arr, 70, 0, 99999);
    t3 = clock() - t3;
    exec_time = ((double)t3)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    // Large binary search
    printf("Binary search with 100000 elements...\n");
    qsort(huge_arr, 100000, sizeof(int), compare_func); // Sort for binary search
    bin_search(huge_arr, 70, 0, 99999);
    t4 = clock() - t4;
    exec_time = ((double)t4)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);


    return 0;
}
