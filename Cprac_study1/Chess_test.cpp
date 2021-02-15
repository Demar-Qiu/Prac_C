#define _CRT_SECURE_NO_WARNINGS ��

/*  ������С��Ϸ  */

#include<stdio.h>
#include"Three_chess.h"

void menu()
{
	printf("**************************************************\n");
	printf("********Please input 1. play  or  0. exit*********\n");
	printf("**************************************************\n");
}


/* ������Ϸ���� */
void Three_chess()
{
	char ret;
	char board[ROW][COL] = {};  // �ַ����飬���������Ϣ
	Initchess(board,ROW,COL);   // ��ʼ������,�ÿո��ʼ��
	Displaychess(board,ROW,COL);    // ��ӡ����
	while (1)
	{
		// �������
		PlayerMove(board,ROW,COL);
		Displaychess(board, ROW, COL);
		//ret = Iswin(board, ROW, COL);
		////printf("%d",ret);
		//if (ret!='C')
		//{
		//	break;               
		//}
		// ��������
		ComputerMove(board, ROW, COL);
		Displaychess(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret!='C')
		{
			break;       
		}
	}
	// �ж�ʤ��
	if (ret == '*')
	{
		printf("��ϲ���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ��\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
}


/*  �����������  */
void Chess_test()
{
	int input;
	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("Please input (1/0)>>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("Game begin!\n");
			Three_chess();
			break;
		}
		case 0:
			printf("Game exit...\n");
		}
	} while (input);
	
}

int main()
{
	Chess_test();
	return 0;
}






