enum State {PROBLEM_NUMBER, SOLUTIONS};
#include <stdio.h>
#include "recursiveFunctions.h"
int main()
{
    int ok, Cases = 1, state = 0;
    char c;
    while (Cases)
    {
        switch (state)
        {
            case PROBLEM_NUMBER:
                {
                printf("Give the number of the problem:\n"
                       "1 - Hermite Polynomials, 2 - Knight's Path and 3 - Labyrinth escape\n>");//choose the problem you want to be shown
                scanf("%d", &ok);
                printf("\n");
                state++;
                break;
                }
            case SOLUTIONS:
                {
                    if (ok == 1) displayH();
                    if (ok == 2) Knight();
                    if (ok == 3) Labyrinth();// the solutions of all the problems
                    printf("Go back? [y/n]\n>");//going back to see the result of the other problems with the key "y" and "n" if you want to terminate the process
                    scanf("%s", &c);
                    if (c == 'y') {state--; printf("\n");}
                    else Cases = 0;
                    break;
                }
        }
    }
    return 0;
}