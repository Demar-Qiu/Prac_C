#define _CRT_SECURE_NO_WARNINGS ��

#include"Three_chess.h"

/* ���̳�ʼ������ */
void Initchess(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

/*  ���̿��ӻ�����  */
void Displaychess(char board[ROW][COL], int row, int col)                       //��ӡ��      |   |   
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
			// ��ӡһ������
			printf(" %c |", board[i][j]);  // Ҳ���ȴ�ӡ %c ,���� if(j<col-1)��ӡ "|"��������ȥ�����ұߵ�����
		}
		printf("\n");
		// ��ӡһ������
		//printf(" %c | %c | %c\n",board[i][0], board[i][1], board[i][2]);   // ȱ�ݣ�ֻ�ܴ�ӡ������,�任ROW��COL���в�ͨ
		// ��ӡ�ָ���
		if(i<(row-1))
			for (j = 0; j < col; j++)
			{
				printf("---");
				printf("|");            // ͬ��ǰ����� if(j<col-1)����ȥ�����ұߵ�����
			}
		printf("\n");
			
	}
}

/* ������庯�� */
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("����ߣ�>>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:(ע�⣺��һ��Ԫ������Ϊ��1��1��) >>");
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
				printf("��λ�ò����£�\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

/* �������庯�� */
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x,y;
	printf("������: >>\n");
	while (1)
	{
		x = rand() % ROW;     //  ����������ɺ�������0~2, ��ʱ���겻��Ƿ�������else���ж�
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// �ж�ƽ�ֵĺ���
int IsFull(char board[ROW][COL], int row, int col)   
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
				return 0;                  // ����1 ��ʾ�������ˣ�0 û��
		}
	}
	return 1;
}


/* �ж�ʤ������ */   // 
char Iswin(char board[ROW][COL], int row, int col)
{
	int i;
	for(i=0;i<row;i++)                   // ������
		if (board[i][0] == board[i][1]&&board[i][1] == board[i][2]&&board[i][1] != ' ')
		{
			return board[i][0];
		}
	for (i = 0; i < col; i++)           // ������
		if (board[0][i] == board[1][i]&& board[1][i] == board[2][i] && board[1][i] != ' ')
		
		{
			return board[1][i];
		}
	if (board[0][0] == board[1][1]&&board[1][1] == board[2][2] && board[1][1] != ' ')  // �����Խ���
	{
		return board[0][0]; 
	}
	if (board[2][0] == board[1][1]&& board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];  
	}  
	if (IsFull(board, ROW, COL) == 1)  // ƽ��            
	{
		return 'Q';
	}
	return 'C';    // ����
}