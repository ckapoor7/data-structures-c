/*
Print the prime factors of a given number in descending order using a stack interface
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "stack-array.h"

struct stack* prime(int num){
  struct stack* factors = init(INT_MAX); //arbitrarily large stack size    
  for (int i=2; num!=1; i++){
    while (num%i==0){
      push(i,factors);
      num /= i;      
    }
  }
  return factors;
}

int main(){
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  print_stack(prime(n));
  return 0;
}
