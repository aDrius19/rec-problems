#ifndef EXTRA_PROBLEMS_RECURSIVEFUNCTIONS_H
#define EXTRA_PROBLEMS_RECURSIVEFUNCTIONS_H
#define MAX_SQUARES 100
#define ROW_SIZE 5
#define COL_SIZE 6
int H(int n, int x);
void displayH();

void Knight();
void printBoard(int n);
int solveBoard(int r, int c, int value);

void Labyrinth();
void printEscape();
int solveLabyrinth(int row, int col);
#endif //EXTRA_PROBLEMS_RECURSIVEFUNCTIONS_H