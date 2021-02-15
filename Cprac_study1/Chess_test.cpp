#define _CRT_SECURE_NO_WARNINGS ；

/*  三子棋小游戏  */

#include<stdio.h>
#include"Three_chess.h"

void menu()
{
	printf("**************************************************\n");
	printf("********Please input 1. play  or  0. exit*********\n");
	printf("**************************************************\n");
}


/* 下棋游戏函数 */
void Three_chess()
{
	char ret;
	char board[ROW][COL] = {};  // 字符数组，存放棋盘信息
	Initchess(board,ROW,COL);   // 初始化棋盘,用空格初始化
	Displaychess(board,ROW,COL);    // 打印棋盘
	while (1)
	{
		// 玩家下棋
		PlayerMove(board,ROW,COL);
		Displaychess(board, ROW, COL);
		//ret = Iswin(board, ROW, COL);
		////printf("%d",ret);
		//if (ret!='C')
		//{
		//	break;               
		//}
		// 电脑下棋
		ComputerMove(board, ROW, COL);
		Displaychess(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret!='C')
		{
			break;       
		}
	}
	// 判断胜负
	if (ret == '*')
	{
		printf("恭喜你获胜！\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜！\n");
	}
	else
	{
		printf("平局！\n");
	}
}


/*  进行下棋测试  */
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






