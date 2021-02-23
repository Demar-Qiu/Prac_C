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
	puts(copy);                     // orig拷贝到copy第8个元素开始替换，之前的不变,到'\0'停止
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

/* 自定义实现strlen库函数功能 */
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')    // *str
	{
		count++;
		str++;
	}
	return count;
}

/* 自定义实现strstr函数功能 */  //查找 字符串p2是否在p1中
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 =NULL;        //p1中走的指针
	char* s2 =NULL;        //p2中走的指针
	char* cur = (char*)p1;  //当前起始指向（控制起始）
	if (*p2 == '\0')   
	{
		return 0;
	}
	while (*cur)  //当前指向不为‘\0’
	{
		s1 = cur;            //p1中走的指针
		s2 = (char*)p2;      //p2中走的指针
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))  //满足这三个条件才能走下一个
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')              
		{
			return cur;
		}
		cur++;
	}
	return NULL;// 找不到字符串

}

int main_9()
{
	const char* a0 = "abcdefmhg";
	const char* a1 = "def";
	//my_strstr(a0, a1);
	char* ret = my_strstr(a0, a1);
	if (ret == NULL)
		printf("字符串不存在\n");
	else
		printf("%s\n",ret );
	return 0;
}

/* 自定义实现memcpy函数功能 */   //  函数memcpy从source的位置开始向后复制count个字节的数据到destination的内存位置。
                                 //在遇到 '\0' 的时候并不会停下来。
void* my_memcpy(void* dest, const void* src, size_t count)   // 两者类型是任意的
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = (char*)dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest=(char*)dest+1;
		src=(char*)src+1;
	}
	return ret;
}

int main()                             //另外还有一个 memmove函数 
                                       //和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[10] = { 0 };
	// arr1中的数字拷贝到arr2中
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}


//下列代码输出的结果       PS: strlen函数的返回类型是size_t，也就是uint
int main_6()
{
	if (strlen("abc") - strlen("abcdef") > 0)  //无符号数始终大于0
		printf("HAHA\n");
	else
		printf("TOTO\n");
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

int main_7()
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

/* 实现调整奇数偶数顺序，使奇数都在偶数之前 */
void move(int am[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left<right)
	{
		while ((left<right)&& (*(am + left))% 2 == 1)  // 从左边找偶数
		{
			left++;
		}
		while ((left < right) && (*(am + right)) % 2 == 0)  //从右边找奇数
		{
			right--;
		}
		if (left < right)
		{
			int tem = *(am + left);
			*(am + left) = *(am + right);
			*(am + right) = tem;
		}

	}
}

int main_8()
{
	int am[] = { 1,2,3,4,5,6,7,8,9,10 };
	// 1 3 5 7 9 9 7 5 3 1
	int s = sizeof(am) / sizeof(int);
	int i = 0;
	move(am, s);
	for (i = 0; i < s ; i++)
	{
		printf("%d ", am[i]);
	}
	
	return 0;
}


