#define _CRT_SECURE_NO_WARNINGS ��

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 


/*  ָ����ر�����  */

int main_0()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);         // PS:ת����int* 
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;                               //����Ľ����ʲô��
}





//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
// ��֪�ṹ��Test���͵ı�����С��20���ֽ�

int main_1()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);  // ��������+1
	printf("%p\n", (unsigned int*)p + 0x1);  // ָ�����͵�+1  ʵ����+4 
	return 0; 
}

// ��������Ŀ��Ҫע�⻭ͼ �����ڴ�Ĵ洢���
int main_2()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);       // ת��Ϊint���͵�ַ�� +1���Ǽ���һ���ֽڵĵ�ַ  
	printf("%x,%x", ptr1[-1], *ptr2);    // ptr2 �����ú���int�ͣ��Ƿ���4���ֽڣ�������Ϊ 0x02 00 00 00
	return 0;
}

int main_3()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };  // ��Ϊ�ǣ���Բ���ţ�������1��3��5
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}


/*int main_4()
{
	int a[5][5];
	int(*p)[4];
	p = a;                // ����ͼ ��aǿ�Ƹ���pָ���ϣ�p��a����4��    ע�⻯�ɲ���
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);     
	return 0;
}   */                             // ��� ��0xFF FF FF FC      -4



int main_5()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));                   // �ڶ�����Ԫ�ص�ַ��6�ĵ�ַ�� ǿ��ת��Ϊint *
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

// �úû�ͼ����һ��
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