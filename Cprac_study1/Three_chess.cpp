#define _CRT_SECURE_NO_WARNINGS ；

#include"Three_chess.h"

/* 棋盘初始化函数 */
void Initchess(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

/*  棋盘可视化函数  */
void Displaychess(char board[ROW][COL], int row, int col)                       //打印出      |   |   
                                                                                //         ---|---|---
	                                                                            //            |   |
	                                                                            //         ---|---|---
	                                                                            //            |   | 
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			// 打印一行数据
			printf(" %c |", board[i][j]);  // 也可先打印 %c ,再用 if(j<col-1)打印 "|"，这样能去掉最右边的竖杠
		}
		printf("\n");
		// 打印一行数据
		//printf(" %c | %c | %c\n",board[i][0], board[i][1], board[i][2]);   // 缺陷：只能打印出三列,变换ROW和COL后行不通
		// 打印分割行
		if(i<(row-1))
			for (j = 0; j < col; j++)
			{
				printf("---");
				printf("|");            // 同样前面加上 if(j<col-1)，可去掉最右边的竖杠
			}
		printf("\n");
			
	}
}

/* 玩家下棋函数 */
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走：>>\n");
	while (1)
	{
		printf("请输入要下的坐标:(注意：第一个元素坐标为（1，1）) >>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置不能下！\n");
			}
		}
		else
		{
			printf("坐标非法！请重新输入！\n");
		}
	}
}

/* 电脑下棋函数 */
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x,y;
	printf("电脑走: >>\n");
	while (1)
	{
		x = rand() % ROW;     //  电脑随机生成横纵坐标0~2, 此时坐标不会非法，无需else再判断
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// 判断平局的函数
int IsFull(char board[ROW][COL], int row, int col)   
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
				return 0;                  // 返回1 表示棋盘满了，0 没满
		}
	}
	return 1;
}


/* 判断胜负函数 */   // 
char Iswin(char board[ROW][COL], int row, int col)
{
	int i;
	for(i=0;i<row;i++)                   // 横三行
		if (board[i][0] == board[i][1]&&board[i][1] == board[i][2]&&board[i][1] != ' ')
		{
			return board[i][0];
		}
	for (i = 0; i < col; i++)           // 竖三列
		if (board[0][i] == board[1][i]&& board[1][i] == board[2][i] && board[1][i] != ' ')
		
		{
			return board[1][i];
		}
	if (board[0][0] == board[1][1]&&board[1][1] == board[2][2] && board[1][1] != ' ')  // 两个对角线
	{
		return board[0][0]; 
	}
	if (board[2][0] == board[1][1]&& board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];  
	}  
	if (IsFull(board, ROW, COL) == 1)  // 平局            
	{
		return 'Q';
	}
	return 'C';    // 继续
}