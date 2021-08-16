/*
 *Find all occurences of a word (taken as a command 
 line argument) in a text string.  
 */

#include <stdio.h>
#define N 10000

int main(int argc, char *argv[]){
        int i, j, t;
        char a[N], *p = argv[1];

        printf("Enter a text string: ");

        // take the word from the command  line till
        // EOF is encountered
        for (i=0; i<N-1; a[i] = t, i++)
                if((t = getchar()) == EOF)
                        break;

        a[i] = 0; // set the last character to '\0'  
        
        // find the occurence of the given word
        for (i = 0; a[i] != 0; i++){
                // iterate till the end of the sought word
                for (j = 0; p[j] != 0; j++)
                        if (a[i+j] != p[j])
                                break;
                if (p[j] == 0)
                        printf("%d ", i);
        }
        printf("\n");
        return 0;
}
