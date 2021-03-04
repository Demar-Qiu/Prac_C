#define _CRT_SECURE_NO_WARNINGS ；

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<errno.h>


/* 动态分配内存 */

int main()
{
	// 向内存申请10个整型的空间
	int* p = (int*)malloc(10 * sizeof(int));    // calloc与其区别，使用参数(10,sizeof(int)),开辟后初始化内存空间每个元素为0
	if (p == NULL)
	{
		printf("%s\n",strerror(errno));   // 打印错误码
	}
	else
	{
		// 正常使用空间
		int i = 0;
		for (i = 0; i < 10; i++)
			*(p + i) = i;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	// 当动态申请的空间不再使用时，还给操作系统
	free(p);
	p = NULL;
	                                               
	return 0;
}

// 还有realloc，用来调整动态开辟的内存
















