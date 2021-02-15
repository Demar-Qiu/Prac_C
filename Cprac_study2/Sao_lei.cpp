#define _CRT_SECURE_NO_WARNINGS ��
#include"Sao_lei.h"


/* ���̳�ʼ������ */        
void Initboard(char board[ROWS][COLS], int row, int col, char arr)   
{ 
	int i, j;
	for(i=0;i<row;i++)
		for (j = 0; j < col; j++)
		{
			board[i][j] = arr;
		}                           // ������memset(board, set, row*col*sizeof(board[0][0]));��ʵ�֣���board�е�row*col���ڴ�ռ��ʼ��Ϊset
}

/* ���̴�ӡ���� */
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;

	// ��ӡ�к�
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
/*  �����׺��� */
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;   
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';      // ���ַ���1������ʾ�ף�ԭʼ���ǡ�0��.      
			count--;
		}
	}
}

// �����ܱ��׵ĸ���
int Get_minecount(char mine[ROWS][COLS], int x, int y)     //  �ַ���1��-��0'= 1����3��-��0��= 3
{													// ���Ƚ���Χ���ַ���1�������������ټ�ȥ8����0�����õ������Ǽ����ײ����ظ�ֵ
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]     
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';       
}

// �ܱ�������չ (���õݹ�)
void Nomine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//int win = 0;
	int result = Get_minecount(mine, x, y);
	if (result != 0)
	{
		show[x][y] = Get_minecount(mine, x, y) + '0';  // ע��Ҫ���Ķ����ַ���ʽ�� 
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

/* ɨ�׺��� */
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i, j;
	int x = 0, y = 0;
	while (1)
	{
		printf("�������Ų��׵�����>>>:");
		int win = 0;  // show��ʣ�� * �ĸ��������׵ĸ�����
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// ����Ϸ�
			if (mine[x][y] == '1' && show[x][y] == '*')
			{
				show[x][y] = 'S';
				Displayboard(show, row, col);
				printf("���ź���������ˣ�\n");
				Displayboard(mine, row, col);
				break;
			}
			else if (mine[x][y] == '0' && show[x][y] == '*')
			{
				// ������Χ�м�����
				int result = Get_minecount(mine, x, y);
				if (result != 0)
				{
					show[x][y] = result + '0';  // ע��Ҫ���Ķ����ַ���ʽ��  
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
					printf("��ϲ�㣡ɨ�׳ɹ���\n");
					Displayboard(mine, row, col);
					break;
				}
			}
		}
		else
		{
			printf("�������겻�Ϸ������������룡\n");
		}
	}
}
//	if (win ==row*col - COUNT)
//	{
//		printf("��ϲ�㣡ɨ�׳ɹ���\n");
//		Displayboard(mine, row, col);
//	}
//}