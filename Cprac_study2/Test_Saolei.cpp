#define _CRT_SECURE_NO_WARNINGS ��

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
	// �׵���Ϣ�Ĵ洢
	// 1.���úõ��׵�����
	char mine[ROWS][COLS] = {};       // 11*11

	// 2.�Ų�����׵���Ϣ(���ָ���ҵ�)
	char show[ROWS][COLS] = {};
	// ��ʼ��
	Initboard(mine, ROWS, COLS, '0');    
	Initboard(show, ROWS, COLS, '*');
	// ��ӡ����
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	// ������
	Setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);
	// ɨ��
	Findmine(mine, show, ROW, COL);
}

// ������Ϸ
void Test_Saolei()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��(1 / 0)��>>>");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}


	} while (input);
}


int main()
{
	Test_Saolei();
	return 0;
}