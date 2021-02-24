#define _CRT_SECURE_NO_WARNINGS；

#include<stdio.h>
#include<string.h>
#include<math.h>


struct Stu
{
	char name[20];//名字
	int tele[12];//电话
	char sex[10];//性别
	int age; // 年龄
}s4,s5,s6;
struct Stu s3;   // 全局变量（s3~s6）
int main_a()
{
	//创建结构体变量(局部变量)
	struct Stu s1;
	struct Stu s2;
	return 0;
}

//结构体的自引用
struct Node
{
	int data; //4
	struct Node* next;   //  4/8
};

//typedef struct Node    // Node不能省略（匿名）
//{
//	int data;
//	struct Node* next;
//}Node;


// 初始化
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


//计算结构体大小  
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



/* 结构体传参 */
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

void print1(struct M temp)  //结构体传值
{
	printf("%d %c %f\n", temp.a, temp.c, temp.d);
}

void print2(struct M *temp)  //结构体传址  （尽量用传址）
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


/* 位段 */   // 二进制位    跟结构相比，位段可以达到同样的效果，可以很好的节省空间，但是有跨平台的问题存在。
struct B
{
	int a : 2;       //表示需要的bit位
	int b : 5; 
	int c : 10;
	int d : 30;    // 一共47bit,6个字节即可，但有空间要舍去
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
	c.e = 10;                 //调试查看e、f、g、h 的内存
	c.f = 20;
	c.g = 3;
	c.h = 4;
	
	return 0;
}

