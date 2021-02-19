#define _CRT_SECURE_NO_WARNINGS ；

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 


/* 用qsort实现排序 */
void qsort(void* base,      //数组
			size_t num,      //数组大小（多少元素）
			size_t width,     //元素字节大小
			int(*cmp)(const void* e1, const void* e2));  //比较方法确定排序方式  函数指针，e1和 e2 是要比较的两个元素的地址

// 整型数据的比较
int cmp_int(const void* p1, const void* p2)        
{
	return (*(int*)p1 - *(int*)p2);  //要比较的元素是整型，所以用（int *）表示将地址强制类型转换成整型地址，可根据排序对象选择指针类型的转换。
}                                   // 再解引用得到该元素的整型，这里是升序，反过来就是降序

struct Stu
{
	char name[20];
	int age;
};

// 结构体数据的比较
int cmp_stu_age(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
}

int cmp_stu_name(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->name - ((struct Stu*)p2)->name;
}

// 直接用qsort函数实现排序
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

/* 回调函数 模拟实现qsort函数 冒泡排序法 */

void swap(char* buf1, char* buf2, int width)  // 元素交换函数 
{
	int i=0;
	for (i = 0; i < width; i++)        // 两两字节之间比较，将每一对字节都交换，最终实现两元素的交换
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
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)   //强制转换为char* 类型得以单字节跳转 实现两相邻元素进行比较
			{
				// 交换
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
	bubble_sort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_age);    // 可调试进行查看
	bubble_sort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_name);
	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	return 0;
}















