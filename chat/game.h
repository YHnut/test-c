#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define easy_time 10
#define ROWS ROW+2
#define COLS COL+2

void initboard(char mine[ROWS][COLS], int rows, int cols);
void Displayboard(char mine[ROWS][COLS], int row, int col);
void Setmine(char mine[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int get_count(char mine[ROWS][COLS], int x, int y);
void openboard(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y,int countmine);