#include <stdio.h>
#include "recursiveFunctions.h"
int solution[MAX_SQUARES][MAX_SQUARES];
int maze[ROW_SIZE][COL_SIZE] = {
        {0,1,0,1,1,1},
        {0,0,0,0,0,0},
        {1,0,1,0,1,1},
        {0,0,1,0,0,0},
        {1,0,0,1,1,0}
};
int H(int n, int x) //problema 3.2
{
    if (n < 0) return -1;
    if (n == 0) return 1;
    if (n == 1) return 2 * x;
    if (n >= 2) return 2 * x * H(n - 1, x) - 2 * (n - 1) * H(n - 2, x);
}
void afisH()
{
    int n, x;
    for (x = 5, n = 0; n <= 6; n++)
        printf("H[%d] = %d\n", n, H(n, x));
}

void Knight() //the knight problem 3.14
{
    int i, j, value;
    scanf("%d", &value);
    printf("The board is of dimension: %d\n", value);//umplem boardul cu valori de -1
    for (i = 0; i < value; i++)
    {
        for (j = 0; j < value; j++)
        {
            solution[i][j] = -1;
        }
    }

    if (solveBoard(0,0, value))
        printBoard(value);
    else
        printf("No solution!\n");
}

void printBoard(int n)
{//printează boardul final
    printf("The knight is moving in this order: \n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", solution[i][j]);
        }
        printf("\n\n");
    }
}

int solveBoard(int row, int col, int value)
{   
    static int n = 0;
    if (n == (value * value) - 1)
    {
        solution[row][col] = n; //dacă ajunge n-ul să aibă ultima valoare din înmulțire
        return 1;
    }

    if (row >= 0 && col >= 0 && row < value && col < value && solution[row][col] == -1) //verficări pentru a putea vizita prima dată poziția respectivă și doar o singură dată
    {
        solution[row][col] = n;
        n++;
        if (solveBoard(row + 2, col + 1, value)) //apeluri recursive pentru a determina pozițiile posibile ale calului și a adăuga o valuare la acele poziții
                                                            //prima și unica dată vizitate
            return 1;

        if (solveBoard(row + 1, col + 2, value))
            return 1;

        if (solveBoard(row - 1, col + 2, value))
            return 1;

        if (solveBoard(row - 2, col + 1, value))
            return 1;

        if (solveBoard(row - 2, col - 1, value))
            return 1;

        if (solveBoard(row - 1, col - 2, value))
            return 1;

        if (solveBoard(row + 1, col - 2, value))
            return 1;

        if (solveBoard(row + 2, col - 1, value))
            return 1;
        //backtracking pentru a găsi alte path-uri pentru a acoperi cât mai multe poziții
    }
    return 0;
}

void Labyrinth() //the labyrinth problem 3.13
{
    int i, j, r, c;
    for (i = 0; i < ROW_SIZE; i++)
    {
        for(j = 0; j < COL_SIZE; j++)
        {
            solution[i][j] = 0; //inițializarea matricei cu drumul spre ieșire cu 0
        }
    }
    scanf("%d %d", &r, &c);
    printf("The initial position is: %d, %d\n", r, c);
    if (maze[r][c] == 0)
    {if (solveLabyrinth(r, c))
            printEscape();
        else
            printf("No solution!\n");
    }
    else printf("It is a wall!");


}

void printEscape()
{//drumul spre ieșire, printat din 1
    printf("The way to exit: \n");
    int i, j;
    for (i = 0;i < ROW_SIZE; i++)
    {
        for (j = 0; j < COL_SIZE; j++)
        {
            printf("%d\t", solution[i][j]);
        }
        printf("\n\n");
    }
}

int solveLabyrinth(int row, int col)
{
    
    if ((row == ROW_SIZE - 1) && (col == COL_SIZE - 1)) //ultima poziție va fi tot timpul unu, pe acolo e ieșirea
    {
        solution[row][col] = 1;
        return 1;
    }
    
    if (row >= 0 && col >= 0 && row < ROW_SIZE && col < COL_SIZE && solution[row][col] == 0 && maze[row][col] == 0) //verificări pentru a trece o singură dată print-un loc și a fi tot timpul pe
        // loc unde poți păși, nu zid
    {
        solution[row][col] = 1; //adăugare pentru a construi drumul din 1 spre ieșire dintr-o poziție dată
        if (solveLabyrinth(row + 1, col)) //apeluri recursive pentru a nu da de zid și backtracking pentru a găsi drumul până la ieșire, dacă dăm doar de ziduri
            return 1;

        if (solveLabyrinth(row, col + 1))
            return 1;

        if (solveLabyrinth(row - 1, col))
            return 1;

        if (solveLabyrinth(row, col - 1))
            return 1;
        solution[row][col] = 0;
        return 0;
    }
    return 0;

}
