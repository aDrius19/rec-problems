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
void displayH()
{
    int n, x, i;
    printf("For read (x, n) values, we have the Hermite Polynomials:\n>");
    scanf("%d %d", &x, &n);
    for (i = 0; i <= n; i++)
        printf("H[%d] = %d\n", i, H(i, x));
    printf("\n");
}

void Knight() //the knight problem 3.14
{
    int i, j, value;
    printf("Give the dimension of the board:\n>");
    scanf("%d", &value);
    for (i = 0; i < value; i++)
    {
        for (j = 0; j < value; j++)
        {
            solution[i][j] = -1; //umplem boardul cu valori de -1
        }
    }
    if (solveBoard(0,0, value))
        printBoard(value);
    else printf("No solution!\n");
}
void printBoard(int n)
{//printează boardul final
    printf("The knight is moving according to the ascending numbering\n");
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
            return 1;                                      //prima și unica dată vizitate

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
    printf("The initial position is (row, column):\n>");
    scanf("%d %d", &r, &c);
    if (maze[r][c] == 0)
    {
        if (solveLabyrinth(r, c))
            printEscape();
        else printf("No solution!\n");
    }
    else printf("It is a wall!");
}
void printEscape()
{//drumul spre ieșire, printat din 1
    printf("The way to exit the labyrinth: \n");
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
    {                                                                                                               // loc unde poți păși, nu zid
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