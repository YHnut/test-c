#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include "game.h"


void game()
{
	//����һ��ģ��
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//���г�ʼ��
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	//Displayboard(mine,ROW,COL);
	Displayboard(show, ROW, COL);
	//������
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
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}

