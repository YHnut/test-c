#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include "game.h"


void game()
{
	//建立一个模型
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//进行初始化
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	//Displayboard(mine,ROW,COL);
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	Displayboard(mine, ROW, COL);
	Findmine(mine,show,ROW,COL);

}


void menu()
{
	printf("***********************************\n");
	printf("************* 1.PLAY **************\n");
	printf("************* 0.EXIT **************\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input);
	return 0;
}

