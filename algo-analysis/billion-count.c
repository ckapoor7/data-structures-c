#include <stdio.h>
#include <time.h>

/*
  The idea of this code is to time the execution
  for running a specific function for 'N' iterations,
  to empirically measure algorithmic performance
*/

void count_nums(int N){
    //count till N
    int count = 0;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<N; k++){
                count++;
            }
        }
    }
}

int main(){
    double exec_time = 0;
    clock_t t1, t2, t3;
    t1 = clock();
    t2 = clock();
    t3 = clock();

    //N=10
    printf("Executing with N = 10...\n");
    count_nums(10);
    t1 = clock() - t1;
    exec_time = ((double)t1)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    //N=100
    printf("Executing with N = 100...\n");
    count_nums(100);
    t2 = clock() - t2;
    exec_time = ((double)t2)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    //N=100
    printf("Executing with N = 1000...\n");
    count_nums(1000);
    t3 = clock() - t3;
    exec_time = ((double)t3)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n\n", exec_time);

    return 0;
}
