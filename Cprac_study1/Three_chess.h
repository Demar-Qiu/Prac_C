#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

void Initchess(char board[ROW][COL], int row, int col);
void Displaychess(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);


