#define _CRT_SECURE_NO_WARNINGS ；

#include<stdio.h>


//根据大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序

int check_sys()  // 存入a，取出 a 中的第一个字节判断，若为01则是小端，00则为大端。   低 01 00 00 00 高地址
{
	int a = 1;
	char* p = (char*)&a;  //目的要拿出一个字节的内容，指针类型决定其访问几个字节，所以这里用char*，这里要强制转换
	/*if (*p == 1)
		return 1;
	else
		return 0;   */
	return *p;
}

int main_a()
{
	int a = 1;
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}




/*  小练习  */

int main_1()     //输出what?      // PS:计算机是用补码进行存储，三者都是11111111
{
	char a = -1;                         
	signed char b = -1;
	unsigned char c = -1;     
	printf("a=%d,b=%d,c=%d", a, b, c);   //涉及整型提升
	return 0;
}



#include <stdio.h>
int main_2()                  // 该题 a=128 结果一样（127+1）
{
	char a = -128;   // 原码 10000000 00000000 00000000 10000000 补码 11111111 11111111 11111111 10000000
	printf("%u\n", a);   // %u 无符号10进制整数  10000000，整型提升后还是补码，无符号数所以原补码相同（就是正数）
	return 0;
}

int main_3()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
	//按照补码的形式进行运算，最后格式化成为有符号整数
	return 0;
}

#include<Windows.h>

int main_4()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)   // i无符号数不可能为负，陷入死循环，由于0-1=-1后其当作无符号数看待时是一超大数
	{
		printf("%u\n", i);
		Sleep(100);
	}

	return 0;
}


int main_5()
{
	char a[1000];     // 由于是char，一个字节八位，-128~127，即从-1到-128，再从127到0
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));   // 到'\0'时停止（不含0），对应就是数字0，所以为255
	return 0;
}



unsigned char i = 0;             // 死循环   i为0~255 恒<=255
int main_6()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

// 综上注意！！无符号数容易导致死循环，使用时要想好！！！


/* 浮点数的存储 */
int main()
{
	int n = 9;
	// 0(S) 00000000(E) 00000000000000000001001(M) 
	float* pFloat = (float*)&n;    // 以浮点数存储n
	printf("n的值为：%d\n", n);  //9
	printf("*pFloat的值为：%f\n", *pFloat);  //(-1)^0*0.00000000000000000001001*2^(1-127)  所以结果为0(%f只是六位精度)

	*pFloat = 9.0;     //存储浮点数9.0    1001.0
	printf("num的值为：%d\n", n);      //  =1.001*2^3    即(-1)^0*1.001*2^3   0 10000010 00100000000000000000000 对应的十进制即为结果
	printf("*pFloat的值为：%f\n", *pFloat);  // 9.0
	return 0;
}



