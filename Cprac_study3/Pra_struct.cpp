#define _CRT_SECURE_NO_WARNINGS��

#include<stdio.h>
#include<string.h>
#include<math.h>


struct Stu
{
	char name[20];//����
	int tele[12];//�绰
	char sex[10];//�Ա�
	int age; // ����
}s4,s5,s6;
struct Stu s3;   // ȫ�ֱ�����s3~s6��
int main_a()
{
	//�����ṹ�����(�ֲ�����)
	struct Stu s1;
	struct Stu s2;
	return 0;
}

//�ṹ���������
struct Node
{
	int data; //4
	struct Node* next;   //  4/8
};

//typedef struct Node    // Node����ʡ�ԣ�������
//{
//	int data;
//	struct Node* next;
//}Node;


// ��ʼ��
struct T
{
	double weight;
	short age;
};
struct S
{
	char c;
	struct T st;
	int a;
	double b;
	char aa[20];
};


int main_b()
{
	struct S s = { 'c',{55.6,23},100,3.14,"zhangyuan" };
	printf("%c %lf %d %lf %s\n", s.c,s.st.weight, s.a, s.b, s.aa);
	return 0;
}


//����ṹ���С  
struct S1
{
	char c1;
	int a;
	char c2;
};
struct S2
{
	char c1;
	char c2;
	int a;
};
int main_c()
{
	struct S1 s1 = { 0 };
	printf("%d\n", sizeof(s1));
	struct S2 s2 = { 0 };
	printf("%d\n", sizeof(s2));
	return 0;
}



/* �ṹ�崫�� */
struct M
{
	int a;
	char c;
	double d;
};

void Init(struct M *m)
{
	m->a = 100;
	m->c = 'W';
	m->d = 3.14;
}

void print1(struct M temp)  //�ṹ�崫ֵ
{
	printf("%d %c %f\n", temp.a, temp.c, temp.d);
}

void print2(struct M *temp)  //�ṹ�崫ַ  �������ô�ַ��
{
	printf("%d %c %f\n", temp->a, temp->c, temp->d);
}

int main_d()
{
	struct M m;
	Init(&m);
	print1(m);
	print2(&m);

	return 0;
}


/* λ�� */   // ������λ    ���ṹ��ȣ�λ�ο��Դﵽͬ����Ч�������ԺܺõĽ�ʡ�ռ䣬�����п�ƽ̨��������ڡ�
struct B
{
	int a : 2;       //��ʾ��Ҫ��bitλ
	int b : 5; 
	int c : 10;
	int d : 30;    // һ��47bit,6���ֽڼ��ɣ����пռ�Ҫ��ȥ
};

struct C
{
	char e : 3;
	char f : 4;
	char g : 5;
	char h : 4;

};

int main()
{
	struct B b;            
	printf("%d\n", sizeof(b));
	struct C c = { 0 };
	c.e = 10;                 //���Բ鿴e��f��g��h ���ڴ�
	c.f = 20;
	c.g = 3;
	c.h = 4;
	
	return 0;
}

