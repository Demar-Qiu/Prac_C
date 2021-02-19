#define _CRT_SECURE_NO_WARNINGS；

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*  关于指针  */
/*-2021-2-17-*/

// 利用指针实现交换的函数
void interch(int* u, int* v);

int main_a()
{
	int x = 5, y = 10;
	printf("最初：x=%d,y=%d\n",x,y);
	interch(&x, &y);               // 把地址传给函数,所以应声明为指针
	printf("现在：x=%d,y=%d\n", x, y);    
	return 0;
}

void interch(int* u, int* v)
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}


/* 指针地址 */
int main_b()      // 指针+1，指针的值增加它所指向数据类型的大小（以字节为单位）
{
	short dates[4];
	short* pti = dates;
	int index;
	double bills[4];
	double* ptf = bills;

	printf("%20s %10s\n", "short", "double");
	for (index = 0; index < 4; index++)
	{
		printf("pointers+%d:%10p %10p\n", index, pti + index, ptf + index);        // short 2字节，double 8字节
	}
	return 0;
}


/* 数组、指针解引用*/
#define MONTHS 12
int main_c()
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;

	for (i = 0; i < MONTHS; i++)
	{
		printf("For 2021, Month %2d has %d days.\n", i + 1, *(days + i));   // 就是days[i]
	}
	return 0;
}


/* 求数组元素之和 */
//-----------------//
#define SIZE 10
int sum(int* ar, int n);          // int sum(int* ar, int n); = int sum(int ar[],int n); = int sum(int *,int); = int sum(int [], int);
int sum_0(int* start, int* end);
int main_d()
{
	int marble[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer;

	//answer = sum(marble, SIZE);
	answer = sum_0(marble, marble + SIZE);
	printf("The total number of marble is %d.\n", answer);
	printf("The size of marble is %zd bytes.\n", sizeof marble);
	return 0;                
}
int sum(int ar[], int n)   // 
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++)
	{
		total += ar[i];  
	}
	printf("The size of ar is %zd bytes.\n", sizeof ar);  // 指针大小4 or 8字节，这里是4（x86是32位平台）
	return total;
}

int  sum_0(int* start, int* end)    //用两个指针作为传参,一头一尾
{
	int total = 0;
	while (start < end)
	{
		total += *start;
		start++;                     // 指针指向下一个元素
	}
	return total;
}

/* 字符串指针 */
int main_e()
{
	char der[] = "abcdef";
	char* pc = der;         // der的首地址（a）传入指针pc
    const char* p = "abcdef"; // p 指向"abcdef"的首地址
	printf("%s\n", der);
	printf("%s\n", pc);     
	printf("%s\n", p);         // 三行都是输出字符串"abcdef"
	printf("%c\n", *p);      // 输出 a   
	return 0;
}

/* 数组和指针表示字符串 */
int main_f()
{
	char arr1[] = "abcde";
	char arr2[] = "abcde";
	const char* p1 = "abcde";  // 指针指向的内容不能被修改
	const char* p2 = "abcde";    
	/*if (arr1 == arr2)
		printf("哈哈哈\n");
	else
		printf("呜呜呜\n");*/    // 输出为 呜呜呜   初始化时字符串被拷贝到数组中，数组的空间都是新开辟的

	if (p1 == p2)
		printf("哈哈哈\n");
	else
		printf("呜呜呜\n");     // 输出为 哈哈哈   字符串的地址是直接拷到指针中，p1和p2都是指向字符串首地址，所以相同

	return 0;                   
}


/* 指针数组 */
int main_g()
{
	int* pax[4];   // 存放整型指针的数组（数组含4个指针元素，每个指针指向int型的值） 
	char* par[5];   //存放字符指针的数组（数组含5个指针元素，每个指针指向char型值）
	int pax1[] = { 1,2,3,4,5 };
	int pax2[] = { 2,3,4,5,6 };
	int pax3[] = { 3,4,5,6,7 };

	int* pz[] = { pax1,pax2,pax3 };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%2d", *(pz[i] + j));
		printf("\n");
  	}

	return 0;
}

/* 数组指针 */             //指向数组的指针--存放数组的地址    通常用于多维数组
void print_arr1(int arr1[][5],int,int);
void print_arr2(int(*arr2)[5], int, int);
int main_h()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;      // 数组指针  p指向一个内含10个int类型值的数组,即arr数组的地址（&arr与arr不同,可+1实践）

	char* att[5];             // 指针数组，数组中每个元素是指针
	char* (*pa)[5] = &att;   // 数组指针  pa为指向内含5个char * 类型值（即att的地址）的指针，即pa中存放着att这个数组的地址
	int kk[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print_arr1(kk, 3, 5);
	printf("-------------\n");
	print_arr2(kk, 3, 5);
	//数组名kk表示首元素地址
	//但二维数组的首元素是二维数组的第一行（即一维数组）
	//所以这里传递的kk，其实相当于第一行的地址，是一维数组的地址
	//可以用数组指针来接收

	return 0;
}
// 参数是数组的形式
void print_arr1(int arr[3][5], int row, int col)
{
	int i = 0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
// 参数是指针的形式
void print_arr2(int(*arr2)[5], int row, int col)
{
	int i = 0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr2 + i) + j));   // 或 (*(arr2+i))[j]
		}
		printf("\n");
	}

}


/**----  传参和接收参数  ----**/

/* 一维数组传参 */
//void test(int arr[])    
//{}
//void test(int arr[10])
//{}
//void test(int* arr)   
//{}                         // 三者等价（整型数组接收）
//void test2(int* arr[20])   
//{}
//void test2(int** arr)     //二级指针表示指针指向的内存单元中存放的仍然是一个指针,所以需要两次转换
//{}                        //二者等价（指针数组接收）
//
//
///* 二维数组传参 */
//void test_0(int arr[3][5])    // 数组接收
//{}
//void test_0(int arr[][5])             //可以省略行，但列一定不能省略！！！即必须知道每一行多少元素
//{}
//void test_2(int (*arr)[5])    // 指针接收    指针指向内含5个元素的数组，每个元素为int类型值
//{}
//
//
///* 一级指针传参 */   //传 变量地址 或 直接一级指针变量
//
///* 二级指针传参 */
//void test1(int **p)
//{}

//int main_i()
//{ 
//	/* 相应各接收参数  */
//	int arr0[10] = { 0 };   //整型数组
//	int* arr2[20] = { 0 }; //指针数组
//	test(arr0);
//	test2(arr2);
//
//	int arr1[3][5] = { 0 }; 
//	test_0(arr1);             //数组形式
//	test_2(arr1);            //指针形式
//
//	int* ptr;
//	int** pp = &ptr;
//	test1(&ptr);    // 一级指针的地址
//	test1(pp);     // 直接二级指针
//	test1(arr2);    // 指针数组
//}

/* 函数指针 */   //---存放函数的地址
int Add(int x, int y)
{
	int z = 0;
	return z = x + y;
}
int Mul(int x, int y)
{
	return x * y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Div(int x, int y)
{
	return x / y;
}

int main_j()
{
	int a = 10;
	int b = 20;
	int m[10] = { 0 };
	int(*p)[10] = &m;
	printf("%p\n", &Add);    //  &函数名 和 函数名都是函数地址
	printf("%p\n", Add);

	int(*pa)(int, int) = Add;    // 函数地址传给pa，pa指向函数Add    还有如 void (*p)(char* )
	printf("%d\n", (*pa)(2, 3)); //调用指针pa指向的函数即Add  或 pa(2,3) 或 Add(2,3) 都ok
	
	//(* (void (*)( ) )0)( );   --- 先把0强制类型转换成 void(*)( )函数指针类型，0就是一个函数地址，再调用0地址处的该函数
	//void(* signal(int , void(*)(int) ) )(int)  --- signal函数含两个参数（整型和函数指针），返回类型为函数指针，指针指向的函数参数为int,返回void
	                                             //---这是个函数声明
	// signal这个函数可以写成如下这样
	typedef void(*pfun_t)(int);
	pfun_t signal(int, pfun_t);

	/*函数指针数组*/
	int* nn[5];
	// 用一个数组存放四个函数的地址---函数指针数组
	int(*pp[4])(int, int) = { Add,Mul,Sub,Div }; // pp每个元素都是一个函数指针
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n",pp[i](2, 3));   
	}

	return 0;
}

/* 指向函数指针数组的指针 */

int (*pfarr[4])(int, int); // pfarr是一个数组，函数指针的数组，数组4个元素，每个元素是指向函数的指针
int (*(*ppfarr)[4])(int, int) = &pfarr; // ppfarr是一个数组指针，指针指向的数组有4个元素，每个元素类型是函数指针 int(* )(int,int)

/* 回调函数 */
void print(const char* str)    //回调函数是一个通过函数指针调用的函数。
{
	printf("haha:%s", str);
}

void test(void(*p)(const char*))   // 参数为函数指针
{
	printf("test\n");
	p("bit"); 
}
int main_k()
{
	test(print);   //把函数的指针作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，就说这是回调函数  (print）

	return 0;
}

// 综上
// int * arr[10];     指针数组
// int* (*pa)[10]=&arr  数组指针
// int(*pad)(int,int)=Add  函数指针
// int(*pam)[5](int,int)  函数指针数组
//  int (*(*paf)[5])(int,int)=&pam   指向函数指针数组的指针


