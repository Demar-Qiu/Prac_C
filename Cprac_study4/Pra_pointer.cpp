#define _CRT_SECURE_NO_WARNINGS��

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*  ����ָ��  */
/*-2021-2-17-*/

// ����ָ��ʵ�ֽ����ĺ���
void interch(int* u, int* v);

int main_a()
{
	int x = 5, y = 10;
	printf("�����x=%d,y=%d\n",x,y);
	interch(&x, &y);               // �ѵ�ַ��������,����Ӧ����Ϊָ��
	printf("���ڣ�x=%d,y=%d\n", x, y);    
	return 0;
}

void interch(int* u, int* v)
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}


/* ָ���ַ */
int main_b()      // ָ��+1��ָ���ֵ��������ָ���������͵Ĵ�С�����ֽ�Ϊ��λ��
{
	short dates[4];
	short* pti = dates;
	int index;
	double bills[4];
	double* ptf = bills;

	printf("%20s %10s\n", "short", "double");
	for (index = 0; index < 4; index++)
	{
		printf("pointers+%d:%10p %10p\n", index, pti + index, ptf + index);        // short 2�ֽڣ�double 8�ֽ�
	}
	return 0;
}


/* ���顢ָ�������*/
#define MONTHS 12
int main_c()
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;

	for (i = 0; i < MONTHS; i++)
	{
		printf("For 2021, Month %2d has %d days.\n", i + 1, *(days + i));   // ����days[i]
	}
	return 0;
}


/* ������Ԫ��֮�� */
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
	printf("The size of ar is %zd bytes.\n", sizeof ar);  // ָ���С4 or 8�ֽڣ�������4��x86��32λƽ̨��
	return total;
}

int  sum_0(int* start, int* end)    //������ָ����Ϊ����,һͷһβ
{
	int total = 0;
	while (start < end)
	{
		total += *start;
		start++;                     // ָ��ָ����һ��Ԫ��
	}
	return total;
}

/* �ַ���ָ�� */
int main_e()
{
	char der[] = "abcdef";
	char* pc = der;         // der���׵�ַ��a������ָ��pc
    const char* p = "abcdef"; // p ָ��"abcdef"���׵�ַ
	printf("%s\n", der);
	printf("%s\n", pc);     
	printf("%s\n", p);         // ���ж�������ַ���"abcdef"
	printf("%c\n", *p);      // ��� a   
	return 0;
}

/* �����ָ���ʾ�ַ��� */
int main_f()
{
	char arr1[] = "abcde";
	char arr2[] = "abcde";
	const char* p1 = "abcde";  // ָ��ָ������ݲ��ܱ��޸�
	const char* p2 = "abcde";    
	/*if (arr1 == arr2)
		printf("������\n");
	else
		printf("������\n");*/    // ���Ϊ ������   ��ʼ��ʱ�ַ����������������У�����Ŀռ䶼���¿��ٵ�

	if (p1 == p2)
		printf("������\n");
	else
		printf("������\n");     // ���Ϊ ������   �ַ����ĵ�ַ��ֱ�ӿ���ָ���У�p1��p2����ָ���ַ����׵�ַ��������ͬ

	return 0;                   
}


/* ָ������ */
int main_g()
{
	int* pax[4];   // �������ָ������飨���麬4��ָ��Ԫ�أ�ÿ��ָ��ָ��int�͵�ֵ�� 
	char* par[5];   //����ַ�ָ������飨���麬5��ָ��Ԫ�أ�ÿ��ָ��ָ��char��ֵ��
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

/* ����ָ�� */             //ָ�������ָ��--�������ĵ�ַ    ͨ�����ڶ�ά����
void print_arr1(int arr1[][5],int,int);
void print_arr2(int(*arr2)[5], int, int);
int main_h()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;      // ����ָ��  pָ��һ���ں�10��int����ֵ������,��arr����ĵ�ַ��&arr��arr��ͬ,��+1ʵ����

	char* att[5];             // ָ�����飬������ÿ��Ԫ����ָ��
	char* (*pa)[5] = &att;   // ����ָ��  paΪָ���ں�5��char * ����ֵ����att�ĵ�ַ����ָ�룬��pa�д����att�������ĵ�ַ
	int kk[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print_arr1(kk, 3, 5);
	printf("-------------\n");
	print_arr2(kk, 3, 5);
	//������kk��ʾ��Ԫ�ص�ַ
	//����ά�������Ԫ���Ƕ�ά����ĵ�һ�У���һά���飩
	//�������ﴫ�ݵ�kk����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
	//����������ָ��������

	return 0;
}
// �������������ʽ
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
// ������ָ�����ʽ
void print_arr2(int(*arr2)[5], int row, int col)
{
	int i = 0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr2 + i) + j));   // �� (*(arr2+i))[j]
		}
		printf("\n");
	}

}


/**----  ���κͽ��ղ���  ----**/

/* һά���鴫�� */
//void test(int arr[])    
//{}
//void test(int arr[10])
//{}
//void test(int* arr)   
//{}                         // ���ߵȼۣ�����������գ�
//void test2(int* arr[20])   
//{}
//void test2(int** arr)     //����ָ���ʾָ��ָ����ڴ浥Ԫ�д�ŵ���Ȼ��һ��ָ��,������Ҫ����ת��
//{}                        //���ߵȼۣ�ָ��������գ�
//
//
///* ��ά���鴫�� */
//void test_0(int arr[3][5])    // �������
//{}
//void test_0(int arr[][5])             //����ʡ���У�����һ������ʡ�ԣ�����������֪��ÿһ�ж���Ԫ��
//{}
//void test_2(int (*arr)[5])    // ָ�����    ָ��ָ���ں�5��Ԫ�ص����飬ÿ��Ԫ��Ϊint����ֵ
//{}
//
//
///* һ��ָ�봫�� */   //�� ������ַ �� ֱ��һ��ָ�����
//
///* ����ָ�봫�� */
//void test1(int **p)
//{}

//int main_i()
//{ 
//	/* ��Ӧ�����ղ���  */
//	int arr0[10] = { 0 };   //��������
//	int* arr2[20] = { 0 }; //ָ������
//	test(arr0);
//	test2(arr2);
//
//	int arr1[3][5] = { 0 }; 
//	test_0(arr1);             //������ʽ
//	test_2(arr1);            //ָ����ʽ
//
//	int* ptr;
//	int** pp = &ptr;
//	test1(&ptr);    // һ��ָ��ĵ�ַ
//	test1(pp);     // ֱ�Ӷ���ָ��
//	test1(arr2);    // ָ������
//}

/* ����ָ�� */   //---��ź����ĵ�ַ
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
	printf("%p\n", &Add);    //  &������ �� ���������Ǻ�����ַ
	printf("%p\n", Add);

	int(*pa)(int, int) = Add;    // ������ַ����pa��paָ����Add    ������ void (*p)(char* )
	printf("%d\n", (*pa)(2, 3)); //����ָ��paָ��ĺ�����Add  �� pa(2,3) �� Add(2,3) ��ok
	
	//(* (void (*)( ) )0)( );   --- �Ȱ�0ǿ������ת���� void(*)( )����ָ�����ͣ�0����һ��������ַ���ٵ���0��ַ���ĸú���
	//void(* signal(int , void(*)(int) ) )(int)  --- signal�������������������ͺͺ���ָ�룩����������Ϊ����ָ�룬ָ��ָ��ĺ�������Ϊint,����void
	                                             //---���Ǹ���������
	// signal�����������д����������
	typedef void(*pfun_t)(int);
	pfun_t signal(int, pfun_t);

	/*����ָ������*/
	int* nn[5];
	// ��һ���������ĸ������ĵ�ַ---����ָ������
	int(*pp[4])(int, int) = { Add,Mul,Sub,Div }; // ppÿ��Ԫ�ض���һ������ָ��
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n",pp[i](2, 3));   
	}

	return 0;
}

/* ָ����ָ�������ָ�� */

int (*pfarr[4])(int, int); // pfarr��һ�����飬����ָ������飬����4��Ԫ�أ�ÿ��Ԫ����ָ������ָ��
int (*(*ppfarr)[4])(int, int) = &pfarr; // ppfarr��һ������ָ�룬ָ��ָ���������4��Ԫ�أ�ÿ��Ԫ�������Ǻ���ָ�� int(* )(int,int)

/* �ص����� */
void print(const char* str)    //�ص�������һ��ͨ������ָ����õĺ�����
{
	printf("haha:%s", str);
}

void test(void(*p)(const char*))   // ����Ϊ����ָ��
{
	printf("test\n");
	p("bit"); 
}
int main_k()
{
	test(print);   //�Ѻ�����ָ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ����˵���ǻص�����  (print��

	return 0;
}

// ����
// int * arr[10];     ָ������
// int* (*pa)[10]=&arr  ����ָ��
// int(*pad)(int,int)=Add  ����ָ��
// int(*pam)[5](int,int)  ����ָ������
//  int (*(*paf)[5])(int,int)=&pam   ָ����ָ�������ָ��


