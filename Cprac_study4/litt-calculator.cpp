#define _CRT_SECURE_NO_WARNINGS ；

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


//int main()                 // 常规实现
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
//			printf("退出！\n");
//			break;
//		default:
//			printf("请重新选择！\n");
//			break;
//		}
//	} while (input);
//
//
//	return 0;
//}

// 封装case中开始时的函数，减少冗余繁杂
void Calc(int(* pf)(int ,int ))              //将函数指针作为传参，运用回调函数
{
	int x, y;
	printf("Please input two numbers>> ");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}


int main_v()              //使用指针数组实现 (转移表)
{
	int input;
	int x, y;
	int(*pfArr[5])(int, int) = { 0,Add_0,Sub_0,Mul_0,Div_0 };  // 使用函数指针数组pfArr，查找到相应的函数
	do
	{
		menu();
		printf("Please input>> ");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("Please input two numbers>> ");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfArr[input](x, y));   // 输出相应计算结果
		}
		else if(input==0)
		{
			printf("退出！\n");
		}
		else
			printf("请重新选择！\n");
		
	} while (input);	
	return 0;
}

