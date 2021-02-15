#define _CRT_SECURE_NO_WARNINGS ；

/* Minesweeper game */

#include<stdio.h>
#include"Sao_lei.h"

void menu()
{
	printf("**************************************************\n");
	printf("********Please input 1. play  or  0. exit*********\n");
	printf("**************************************************\n");
}


void Sao_lei()
{
	// 雷的信息的存储
	// 1.布置好的雷的数组
	char mine[ROWS][COLS] = {};       // 11*11

	// 2.排查出的雷的信息(呈现给玩家的)
	char show[ROWS][COLS] = {};
	// 初始化
	Initboard(mine, ROWS, COLS, '0');    
	Initboard(show, ROWS, COLS, '*');
	// 打印棋盘
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	// 布置雷
	Setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);
	// 扫雷
	Findmine(mine, show, ROW, COL);
}

// 进行游戏
void Test_Saolei()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择(1 / 0)：>>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("Game begin!\n");
			Sao_lei();
			break;
		}
		case 0:
			printf("exit...\n");
			break;
		default:
			printf("选择错误！请重新选择！\n");
			break;
		}


	} while (input);
}


int main()
{
	Test_Saolei();
	return 0;
}