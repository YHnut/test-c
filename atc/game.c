#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initboard(char mine[ROWS][COLS], int rows, int cols,int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}

void Displayboard(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = easy_time;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x- 1][y + 1] - 8 * '0';
}


void openboard(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y,int countmine)
{
	int a = 0;
	int b = 0;
	for (a = 1; a >=-1; a--)
	{
		for (b = 1; b >= -1; b--)
		{
			if (mine[x + a][y + b] != '1')
			{
				show[x + a][y + b] = ' ';
			}
			else
			{
				int countmine = get_count(mine, x, y);
				show[x][y] = countmine + '0';
			}
		}
	}
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int countmine = 0;
	int win = 0;
	while (win<row*col-easy_time)
	{
		printf("请选择你要排查的坐标:>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				break;
			}
			else
			{
				openboard(mine, show, x, y, countmine);
				for (int a = 1; a >= -1; a--)
				{
					for (int b = 1; b >= -1; b--)
					{
						int X = x + a;
						int Y = y + b;
						openboard(mine, show, X, Y, countmine);
					}
					//openboard(mine, show, x, y, countmine);
				}
				Displayboard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标无效，请重新输入\n");
		}
		if (win == row * col - easy_time)
		{
			printf("恭喜你，排雷成功\n");
			Displayboard(show, ROW, COL);
			break;
		}
	}
}