/*
Author			:	Fowzy Alsaud
Date				: Oct, 1st, 2021
Assignment	:	Mini Project #1
Class				: CMPS 4103	- Dr. Passos 
*/
#include <stdio.h>
#include <unistd.h> //  POSIX

int main(void)
{ // Main is the parent. I'm gonna call it P0
    int n = 0;
    scanf("%d", &n);
    int child1 = fork(); //New child created P1 (1st)
    int child2 = fork(); //New child created P2 (2nd)
    if (child1 > 0 && child2 > 0) // check if this is the parent
    {
        for (int i = (2 * n) / 3; i <= (n * 3) / 3; i++)
            printf(" %d", i);
        printf("    (\"output of the main program\")\n");
    }
    if (child1 != 0 && child2 == 0) // check if this is child #2
    {
        for (int i = (n / 3) + 1; i <= (2 * n) / 3; i++)
            printf(" %d", i);
        printf("    (\"output of the second child\")\n");
    }
    if (child1 == 0 && child2 != 0) // chech if this the first child
    {
        for (int i = 1; i <= n / 3; i++)
            printf(" %d", i);
        printf("    (\"output of first child\")\n");
    }

    return 0;
}