/*
 * This program implements a pushdown-stack, and reads a
 * postfix expression that involves basic arithmetic operations
 * of integers and prints the result of the operation thus
 * performed.
 */


#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK-array.h" // use the array implementation of the pushdown stack
//#include "STACK-ll.h"   // use the linked list implementation of the pushdown stack

int main(int argc, char *argv[]){
    char *a = argv[1];
    int i, N = strlen(a);
    STACKinit(N);

    for (i = 0; i < N; i++){
        if (a[i] == '+')
            STACKpush(STACKpop() + STACKpop());
        if (a[i] == '*')
            STACKpush(STACKpop() * STACKpop());
        if ((a[i] >= '0') && a[i] <= '9')
            STACKpush(0);
        while ((a[i] >= '0') && (a[i] <= '9')) // do something like the 'atoi' library function
           STACKpush(10 * STACKpop() + (a[i++] - '0'));
    }
    printf("%d \n", STACKpop());

    return 0;
}
