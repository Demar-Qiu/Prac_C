#define _CRT_SECURE_NO_WARNINGS��

#include<stdio.h>
#include<string.h>
#include<math.h>

/* strcpy������ʹ�� */          // strcpy(a[], *b) ���ڶ�������ָ����ַ�����������һ������ָ���������
#define WORDS "beast"
#define SIZE 40

int main_1()
{
	const char* orig = WORDS;
	char copy[SIZE] = "Be the best that you can be";
	char* ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);   //psָ��copy�ĵ�8��Ԫ�أ��Ӵ˴���ʼ��ӡ�����ַ�'\0'Ҳ��������
	puts(copy);                     // orig������copy��8��Ԫ�ؿ�ʼ�滻��֮ǰ�Ĳ���
	puts(ps);

	return 0;
}

/* ʵ��strcpy�⺯���Ĺ��� */      // strcpy(a[], *b) ���ڶ�������ָ����ַ�����������һ������ָ���������
void my_strcpy(char* dest,char* src)       // ����һ�� ��6��
{
	while (*src != '\0')
	{
		//*dest = *src;
		//src++;
		//dest++;
		*dest++ = *src++;
	}
	*dest = *src;   // ���� '\0 '       
}


void my_strcpy0(char* dest, char* src)    // ���뻹���� ��7�� (�������ڿ�ָ��NULL)
{ 
	while (*dest++ = *src++)
	{
		;
	}
}

#include<assert.h>
void my_strcpy1(char* dest, char* src)    // ����ok,��8��   �ö���assert
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}

char* my_strcpy2(char* dest, const char* src)    // ���֣� ָ���˷���ֵ�� const ���Ͳ�������ֹԴ��Ŀ�Ĵ���
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


//�������´��루��������ѭ����why? and how to modify?
int main_2()              
{
	int i=0;
	int tem[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("you are handsome\n");    
		tem[i] = 0;                   // ͨ�����Է��֣�&tem[12] �պú� &i һ�£���i�ڸ�λ��ַ���ȶ��壩����i��0��12ʱ����ַ�ɵ͵���
	}                                // iΪ��12ʱ ����&tem[12]=&i,λ��ͬһ�ڴ�ռ䣬������������ͬʱ��Ϊ0.
	return 0;
}

// ���԰�int i = 0 ����int tem[]���� //

//int main()
//{
//	int tem[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i <= 12; i++)
//	{
//		printf("you are handsome\n");
//		tem[i] = 0;                   
//	}                               // ������ѭ����������������
//	return 0;
//}

void fit(char*, unsigned int);
int main_3()
{
	char mesg[] = "Things should be as simple as possible,"
		" but not simpler.";
	puts(mesg);
	fit(mesg, 38);    // �ѵ�39��Ԫ�أ����ţ��滻��'\0'�ַ�
	puts(mesg);     // puts����ַ������ڿ��ַ�ʱֹͣ
	puts("Let's look at some more of the string.");   
	puts(mesg + 39);   // �ӵ�40���ַ����ո񣩿�ʼ���

	return 0;
}

/* ��д�����ַ������ȵĺ��� */
void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		string[size] = '\0';
}


/* ��ӡ0��100000֮������� ˮ�ɻ��� */
int main_4()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//����i��λ��---nλ��
		int n = 1;
		int sum = 0;
		int amp = i;   //��Ҫһ��amp������i��ֱ����i��ı�ֵ 
		while (amp/=10)
		{
			n++;
		}
		// ����i��ÿһλ��n�η�֮�� sum
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

/* ��ӡ�Ǻ���ɵ����� */
int main_5()
{
	int line = 0;
	scanf("%d",&line); //7   ���е��м���й��ж����У��ϰ벿�֣�
	// ��ӡ�ϰ벿�� 
	int i = 0;
	for (i = 0; i < line; i++)
	{
		// ��ӡ�ո�
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;
		//��ӡ�ո�
		for (j = 0; j <=i; j++)
			printf(" ");
		//��ӡ*
		for (j = 0; j <2*(line-1-i)-1 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

/* ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ�ɻ�һƿ��ˮ����20Ԫ���򵽶���ƿ��ˮ */

int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	// ���������ˮ�ȵ�
	total = money;
	empty = money;
	// ����������ˮ
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total:%d\n", total);
	return 0;
}
