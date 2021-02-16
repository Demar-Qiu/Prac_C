#define _CRT_SECURE_NO_WARNINGS��

#include<stdio.h>
#include<string.h>

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
int main()              
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