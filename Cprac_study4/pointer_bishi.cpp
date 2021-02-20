#define _CRT_SECURE_NO_WARNINGS ；

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 


/*  指针相关笔试题  */

int main_0()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);         // PS:转换成int* 
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;                               //程序的结果是什么？
}





//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
// 已知结构体Test类型的变量大小是20个字节

int main_1()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);  // 就是整型+1
	printf("%p\n", (unsigned int*)p + 0x1);  // 指针类型的+1  实际是+4 
	return 0; 
}

// 以下类题目都要注意画图 画出内存的存储情况
int main_2()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);       // 转换为int整型地址后 +1就是加了一个字节的地址  
	printf("%x,%x", ptr1[-1], *ptr2);    // ptr2 解引用后是int型，是访问4个字节，结果输出为 0x02 00 00 00
	return 0;
}

int main_3()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };  // 因为是（）圆括号，所以是1，3，5
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}


/*int main_4()
{
	int a[5][5];
	int(*p)[4];
	p = a;                // 画出图 ，a强制赋在p指针上，p在a上走4步    注意化成补码
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);     
	return 0;
}   */                             // 结果 ：0xFF FF FF FC      -4



int main_5()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));                   // 第二行首元素地址（6的地址） 强制转换为int *
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));       
	return 0;
}


int main_6()
{
	const char* a[] = { "work","at","alibaba" };
	const char**pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}

// 好好画图分析一下
int main()
{
	const char* c[] = { "ENTER","NEW","POINT","FIRST" };
	const char** cp[] = { c + 3,c + 2,c + 1,c };
	const char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}