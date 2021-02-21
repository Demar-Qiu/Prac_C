#define _CRT_SECURE_NO_WARNINGS；

#include<stdio.h>
#include<string.h>
#include<math.h>

/* strcpy函数的使用 */          // strcpy(a[], *b) 将第二个参数指向的字符串拷贝到第一个参数指向的数组中
#define WORDS "beast"
#define SIZE 40

int main_1()
{
	const char* orig = WORDS;
	char copy[SIZE] = "Be the best that you can be";
	char* ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);   //ps指向copy的第8个元素，从此处开始打印，空字符'\0'也拷贝在内
	puts(copy);                     // orig拷贝到copy第8个元素开始替换，之前的不变
	puts(ps);

	return 0;
}

/* 实现strcpy库函数的功能 */      // strcpy(a[], *b) 将第二个参数指向的字符串拷贝到第一个参数指向的数组中
void my_strcpy(char* dest,char* src)       // 代码一般 得6分
{
	while (*src != '\0')
	{
		//*dest = *src;
		//src++;
		//dest++;
		*dest++ = *src++;
	}
	*dest = *src;   // 拷贝 '\0 '       
}


void my_strcpy0(char* dest, char* src)    // 代码还可以 得7分 (但不适于空指针NULL)
{ 
	while (*dest++ = *src++)
	{
		;
	}
}

#include<assert.h>
void my_strcpy1(char* dest, char* src)    // 代码ok,得8分   用断言assert
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}

char* my_strcpy2(char* dest, const char* src)    // 满分！ 指明了返回值和 const 类型参数，防止源和目的错乱
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}


int main_0()
{
	char arr1[] = "########";
	char arr2[] = "bit";
	//my_strcpy1(arr1, NULL);
	//printf("%s\n", arr1);
	printf("%s\n", my_strcpy2(arr1,arr2));
	return 0;
}


//调试以下代码（会陷入死循环）why? and how to modify?
int main_2()              
{
	int i=0;
	int tem[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("you are handsome\n");    
		tem[i] = 0;                   // 通过调试发现，&tem[12] 刚好和 &i 一致，且i在高位地址（先定义），当i从0到12时，地址由低到高
	}                                // i为变12时 由于&tem[12]=&i,位于同一内存空间，则两个变量会同时变为0.
	return 0;
}

// 尝试把int i = 0 放在int tem[]后面 //

//int main()
//{
//	int tem[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i <= 12; i++)
//	{
//		printf("you are handsome\n");
//		tem[i] = 0;                   
//	}                               // 不会死循环，但不建议这样
//	return 0;
//}

void fit(char*, unsigned int);
int main_3()
{
	char mesg[] = "Things should be as simple as possible,"
		" but not simpler.";
	puts(mesg);
	fit(mesg, 38);    // 把第39个元素（逗号）替换成'\0'字符
	puts(mesg);     // puts输出字符串会在空字符时停止
	puts("Let's look at some more of the string.");   
	puts(mesg + 39);   // 从第40个字符（空格）开始输出

	return 0;
}

/* 编写缩短字符串长度的函数 */
void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		string[size] = '\0';
}


/* 打印0—100000之间的所有 水仙花数 */
int main_4()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//计算i的位数---n位数
		int n = 1;
		int sum = 0;
		int amp = i;   //需要一个amp来接收i，直接用i会改变值 
		while (amp/=10)
		{
			n++;
		}
		// 计算i的每一位的n次方之和 sum
		amp = i;
		while (amp)
		{
			sum += pow(amp % 10, n);
			amp /= 10;
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}

/* 打印星号组成的菱形 */
int main_5()
{
	int line = 0;
	scanf("%d",&line); //7   首行到中间最长行共有多少行（上半部分）
	// 打印上半部分 
	int i = 0;
	for (i = 0; i < line; i++)
	{
		// 打印空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;
		//打印空格
		for (j = 0; j <=i; j++)
			printf(" ");
		//打印*
		for (j = 0; j <2*(line-1-i)-1 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

/* 喝汽水，1瓶汽水1元，2个空瓶可换一瓶汽水，给20元能买到多少瓶汽水 */

int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	// 买回来的汽水喝掉
	total = money;
	empty = money;
	// 换回来的汽水
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total:%d\n", total);
	return 0;
}
