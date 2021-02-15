#define _CRT_SECURE_NO_WARNINGS ；
#include"Sao_lei.h"


/* 棋盘初始化函数 */        
void Initboard(char board[ROWS][COLS], int row, int col, char arr)   
{ 
	int i, j;
	for(i=0;i<row;i++)
		for (j = 0; j < col; j++)
		{
			board[i][j] = arr;
		}                           // 或者用memset(board, set, row*col*sizeof(board[0][0]));来实现，给board中的row*col个内存空间初始化为set
}

/* 棋盘打印函数 */
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;

	// 打印列号
	for (i = 0; i <= col; i++)
	{
		printf(" %d  ",i);
	}
	printf("\n");
	for (j = 0; j <row + 1; j++)
	{
		printf("---|");
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf(" %d |", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("   |");
		for (j = 1; j <= col; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
	printf("\n");
}
/*  布置雷函数 */
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;   
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';      // 用字符‘1’来表示雷，原始都是‘0’.      
			count--;
		}
	}
}

// 计算周边雷的个数
int Get_minecount(char mine[ROWS][COLS], int x, int y)     //  字符‘1’-‘0'= 1，‘3’-‘0’= 3
{													// 可先将周围的字符‘1’都加起来，再减去8个‘0’，得到几就是几个雷并返回该值
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]     
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';       
}

// 周边无雷扩展 (运用递归)
void Nomine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//int win = 0;
	int result = Get_minecount(mine, x, y);
	if (result != 0)
	{
		show[x][y] = Get_minecount(mine, x, y) + '0';  // 注意要填充的都是字符形式！ 
		//win++;
	}
	else
	{
		show[x][y] = ' ';

		if ((x - 1) > 0 && (y - 1) > 0 && (show[x - 1][y - 1] == '*'))
			Nomine(mine, show, x - 1, y - 1);

		if ((x - 1) > 0 && (y) > 0 && (show[x - 1][y] == '*'))
			Nomine(mine, show, x - 1, y);

		if ((x - 1) > 0 && (y + 1) > 0 && (show[x - 1][y + 1] == '*'))
			Nomine(mine, show, x - 1, y + 1);

		if ((x) > 0 && (y - 1) > 0 && (show[x][y - 1] == '*'))
			Nomine(mine, show, x, y - 1);

		if ((x) > 0 && (y + 1) > 0 && (show[x][y + 1] == '*'))
			Nomine(mine, show, x, y + 1);

		if ((x + 1) > 0 && (y - 1) > 0 && (show[x + 1][y - 1] == '*'))
			Nomine(mine, show, x + 1, y - 1);

		if ((x + 1) > 0 && (y) > 0 && (show[x + 1][y] == '*'))
			Nomine(mine, show, x + 1, y);

		if ((x + 1) > 0 && (y + 1) > 0 && (show[x + 1][y + 1] == '*'))
			Nomine(mine, show, x + 1, y + 1);
	}
}

/* 扫雷函数 */
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i, j;
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入排查雷的坐标>>>:");
		int win = 0;  // show中剩余 * 的个数（即雷的个数）
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// 坐标合法
			if (mine[x][y] == '1' && show[x][y] == '*')
			{
				show[x][y] = 'S';
				Displayboard(show, row, col);
				printf("很遗憾！你踩雷了！\n");
				Displayboard(mine, row, col);
				break;
			}
			else if (mine[x][y] == '0' && show[x][y] == '*')
			{
				// 计算周围有几个雷
				int result = Get_minecount(mine, x, y);
				if (result != 0)
				{
					show[x][y] = result + '0';  // 注意要填充的都是字符形式！  
					Displayboard(show, row, col);
					//win++;
				}
				else
				{
					Nomine(mine, show, x, y);
					Displayboard(show, row, col);
					//win += 9;
				}
				for (i = 1; i <= row; i++)
				{
					for (j = 1; j <= col; j++)
					{
						if (show[i][j] == '*')
						{
							win++;
						}
						
					}
				}
				//printf("%d\n", win);
				if (win == COUNT)
				{
					printf("恭喜你！扫雷成功！\n");
					Displayboard(mine, row, col);
					break;
				}
			}
		}
		else
		{
			printf("输入坐标不合法，请重新输入！\n");
		}
	}
}
//	if (win ==row*col - COUNT)
//	{
//		printf("恭喜你！扫雷成功！\n");
//		Displayboard(mine, row, col);
//	}
//}