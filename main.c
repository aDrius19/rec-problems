#include <stdio.h>
#include "recursiveFunctions.h"
int main()
{
    int ok;
    scanf("%d", &ok);
    printf("\n");
    if (ok == 0) afisH();
        if (ok == 1) Knight();
            else if (ok == 2) Labyrinth();
    return 0;
}
