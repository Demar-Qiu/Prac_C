#define _CRT_SECURE_NO_WARNINGS ��

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<errno.h>


/* ��̬�����ڴ� */

int main()
{
	// ���ڴ�����10�����͵Ŀռ�
	int* p = (int*)malloc(10 * sizeof(int));    // calloc��������ʹ�ò���(10,sizeof(int)),���ٺ��ʼ���ڴ�ռ�ÿ��Ԫ��Ϊ0
	if (p == NULL)
	{
		printf("%s\n",strerror(errno));   // ��ӡ������
	}
	else
	{
		// ����ʹ�ÿռ�
		int i = 0;
		for (i = 0; i < 10; i++)
			*(p + i) = i;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	// ����̬����Ŀռ䲻��ʹ��ʱ����������ϵͳ
	free(p);
	p = NULL;
	                                               
	return 0;
}

// ����realloc������������̬���ٵ��ڴ�
















