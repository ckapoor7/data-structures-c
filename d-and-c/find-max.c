/*
 * divide and conquer algorithm to find the maximum element of
 * a general data type (an array is considered here)
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a[], int l, int r){
    int u, v;
    int m = (l+r)/2;
    if (l==r)
        return a[l];
    u = max(a, l, m);
    v = max(a, m+1, r);
    if (u > v)
        return u;
    else
        return v;
}

int main(int argc, char *argv[]){
    int arr[] = {4, 3, 9, 1, 8, 101, 32, 6};
    int max_val = max(arr, 0, 7);
    printf("The maximum value is %d\n", max_val);

    return 0;
}
