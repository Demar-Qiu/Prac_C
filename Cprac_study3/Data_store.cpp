#define _CRT_SECURE_NO_WARNINGS ��

#include<stdio.h>


//���ݴ���ֽ����С���ֽ���ĸ�����һ��С�������жϵ�ǰ�������ֽ���

int check_sys()  // ����a��ȡ�� a �еĵ�һ���ֽ��жϣ���Ϊ01����С�ˣ�00��Ϊ��ˡ�   �� 01 00 00 00 �ߵ�ַ
{
	int a = 1;
	char* p = (char*)&a;  //Ŀ��Ҫ�ó�һ���ֽڵ����ݣ�ָ�����;�������ʼ����ֽڣ�����������char*������Ҫǿ��ת��
	/*if (*p == 1)
		return 1;
	else
		return 0;   */
	return *p;
}

int main_a()
{
	int a = 1;
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;
}




/*  С��ϰ  */

int main_1()     //���what?      // PS:��������ò�����д洢�����߶���11111111
{
	char a = -1;                         
	signed char b = -1;
	unsigned char c = -1;     
	printf("a=%d,b=%d,c=%d", a, b, c);   //�漰��������
	return 0;
}



#include <stdio.h>
int main_2()                  // ���� a=128 ���һ����127+1��
{
	char a = -128;   // ԭ�� 10000000 00000000 00000000 10000000 ���� 11111111 11111111 11111111 10000000
	printf("%u\n", a);   // %u �޷���10��������  10000000�������������ǲ��룬�޷���������ԭ������ͬ������������
	return 0;
}

int main_3()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
	//���ղ������ʽ�������㣬����ʽ����Ϊ�з�������
	return 0;
}

#include<Windows.h>

int main_4()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)   // i�޷�����������Ϊ����������ѭ��������0-1=-1���䵱���޷���������ʱ��һ������
	{
		printf("%u\n", i);
		Sleep(100);
	}

	return 0;
}


int main_5()
{
	char a[1000];     // ������char��һ���ֽڰ�λ��-128~127������-1��-128���ٴ�127��0
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));   // ��'\0'ʱֹͣ������0������Ӧ��������0������Ϊ255
	return 0;
}



unsigned char i = 0;             // ��ѭ��   iΪ0~255 ��<=255
int main_6()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

// ����ע�⣡���޷��������׵�����ѭ����ʹ��ʱҪ��ã�����


/* �������Ĵ洢 */
int main()
{
	int n = 9;
	// 0(S) 00000000(E) 00000000000000000001001(M) 
	float* pFloat = (float*)&n;    // �Ը������洢n
	printf("n��ֵΪ��%d\n", n);  //9
	printf("*pFloat��ֵΪ��%f\n", *pFloat);  //(-1)^0*0.00000000000000000001001*2^(1-127)  ���Խ��Ϊ0(%fֻ����λ����)

	*pFloat = 9.0;     //�洢������9.0    1001.0
	printf("num��ֵΪ��%d\n", n);      //  =1.001*2^3    ��(-1)^0*1.001*2^3   0 10000010 00100000000000000000000 ��Ӧ��ʮ���Ƽ�Ϊ���
	printf("*pFloat��ֵΪ��%f\n", *pFloat);  // 9.0
	return 0;
}



