#define _CRT_SECURE_NO_WARNINGS ��

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu()
{
	printf("****************************\n");
	printf("*** 1.add          2.sub ***\n");
	printf("*** 3.mul          4.div ***\n");
	printf("********   0.exit    *******\n");
	printf("****************************\n");
}


int Add_0(int x, int y)
{
	int z = 0;
	return z = x + y;
}

int Sub_0(int x, int y)
{
	return x - y;
}

int Mul_0(int x, int y)
{
	return x * y;
}

int Div_0(int x, int y)
{
	return x / y;
}


//int main()                 // ����ʵ��
//{
//	int input;
//	int x, y;
//	do
//	{
//		menu();
//		printf("Please input>> ");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//		case 1:
//			 //printf("Please input two numbers>> ");
//		     //scanf("%d%d", &x, &y);
//		     //printf("%d\n", Add_0(x, y));
//          Calc(Add)
//			break;
//		case 2:
//			printf("Please input two numbers>> ");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub_0(x, y));
//			break;
//		case 3:
//			printf("Please input two numbers>> ");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul_0(x, y));
//			break;
//		case 4:
//			printf("Please input two numbers>> ");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div_0(x, y));
//			break;
//		case 0:
//			printf("�˳���\n");
//			break;
//		default:
//			printf("������ѡ��\n");
//			break;
//		}
//	} while (input);
//
//
//	return 0;
//}

// ��װcase�п�ʼʱ�ĺ������������෱��
void Calc(int(* pf)(int ,int ))              //������ָ����Ϊ���Σ����ûص�����
{
	int x, y;
	printf("Please input two numbers>> ");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}


int main_v()              //ʹ��ָ������ʵ�� (ת�Ʊ�)
{
	int input;
	int x, y;
	int(*pfArr[5])(int, int) = { 0,Add_0,Sub_0,Mul_0,Div_0 };  // ʹ�ú���ָ������pfArr�����ҵ���Ӧ�ĺ���
	do
	{
		menu();
		printf("Please input>> ");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("Please input two numbers>> ");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfArr[input](x, y));   // �����Ӧ������
		}
		else if(input==0)
		{
			printf("�˳���\n");
		}
		else
			printf("������ѡ��\n");
		
	} while (input);	
	return 0;
}

