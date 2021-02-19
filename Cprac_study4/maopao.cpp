#define _CRT_SECURE_NO_WARNINGS ��

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 


/* ��qsortʵ������ */
void qsort(void* base,      //����
			size_t num,      //�����С������Ԫ�أ�
			size_t width,     //Ԫ���ֽڴ�С
			int(*cmp)(const void* e1, const void* e2));  //�ȽϷ���ȷ������ʽ  ����ָ�룬e1�� e2 ��Ҫ�Ƚϵ�����Ԫ�صĵ�ַ

// �������ݵıȽ�
int cmp_int(const void* p1, const void* p2)        
{
	return (*(int*)p1 - *(int*)p2);  //Ҫ�Ƚϵ�Ԫ�������ͣ������ã�int *����ʾ����ַǿ������ת�������͵�ַ���ɸ����������ѡ��ָ�����͵�ת����
}                                   // �ٽ����õõ���Ԫ�ص����ͣ����������򣬷��������ǽ���

struct Stu
{
	char name[20];
	int age;
};

// �ṹ�����ݵıȽ�
int cmp_stu_age(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
}

int cmp_stu_name(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->name - ((struct Stu*)p2)->name;
}

// ֱ����qsort����ʵ������
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

/* �ص����� ģ��ʵ��qsort���� ð������ */

void swap(char* buf1, char* buf2, int width)  // Ԫ�ؽ������� 
{
	int i=0;
	for (i = 0; i < width; i++)        // �����ֽ�֮��Ƚϣ���ÿһ���ֽڶ�����������ʵ����Ԫ�صĽ���
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}

}

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)   //ǿ��ת��Ϊchar* ���͵��Ե��ֽ���ת ʵ��������Ԫ�ؽ��бȽ�
			{
				// ����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	struct Stu s[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",15} };

	//bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);
	bubble_sort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_age);    // �ɵ��Խ��в鿴
	bubble_sort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_name);
	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	return 0;
}















