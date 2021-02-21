#define _CRT_SECURE_NO_WARNINGS；

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<assert.h>

/* 冒泡排序法 */
#define SIZE 10      //从大到小比较十个成绩
int main_a(void)
{
	int leo[SIZE] = { 73,68,86,93,80,77,92,61,79,82 };
	int i, j;
	printf("\n**********排序前**********\n");
	for (i = 0; i < 10; i++)
		printf("%d ", leo[i]);

	//for (i = 8; i >= 0; i--)  
	//	for (j = 0; j <= i; j++)
	//		if (leo[j] < leo[j + 1])
	//		{
	//			int temp;
	//			temp = leo[j];
	//			leo[j] = leo[j + 1];
	//			leo[j + 1] = temp;
	//		}
	
	for (i=0;i<9;i++)   // i:比较 9 轮
		for(j=0;j<9-i;j++)   // j：每轮比较 9-i 次
			if (leo[j] < leo[j + 1])  
			{
				int temp;
				temp = leo[j];
				leo[j] = leo[j + 1];
				leo[j + 1] = temp;
			}

	printf("\n**********排序后**********\n");
	for (i = 0; i < 10; i++)
		printf("%d ", leo[i]);

	return 0;
}

/* 通用方法 */
int main_b()
{
	int leo[] = { 73,68,86,93,80,77,92,61,79,82 };
	int i, j, temp;
	int n;
	n = sizeof(leo) / sizeof(int);
	printf("\n**********排序前**********\n");
	for (i = 0; i < n; i++)
		printf("%d ", leo[i]);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (leo[j] < leo[j + 1])
			{
				temp = leo[j];
				leo[j] = leo[j + 1];
				leo[j + 1] = temp;
			}
		}
	}
	printf("\n**********排序后**********\n");
	for (i = 0; i < n; i++)
		printf("%d ", leo[i]);

	return 0;
}


/* 求两数的最大公约数 */
int main_c()
{
	int m, n;
	int buf=0;
	scanf("%d %d",&m,&n);
	while (m % n)
	{
		buf = m % n;
		m = n;
		n = buf;
	}
	printf("最大公约数为：%d\n",n);
	return 0;
}

/* 打印1000-2000年间的闰年 */
int main_d()
{
	int year;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("%d\n", year);
			count++;
		}
	}
	printf("有 %d 个数",count);
	return 0;
}

/* 打印100-200之间的素数 */
// 法一
//int main()
//{
//	int a;
//	for (a = 100; a <= 200; a++)
//	{
//		int i= 0;   
//		int count = 0;
//		for (i = 2; i < a ; i++)          // 试除法：看 2 到 a-1 之间有没有数能够整除 a
//		{
//			if (a % i == 0)
//				break;
//		}
//		if (a == i)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("个数为 count=%d\n", a);
//	return 0;
//}

// 法二（更优化）
int main_e()
{
	int a, i;
	int count = 0;
	for (a = 100; a <= 200; a++)
	{
		for (i=2;i <= sqrt(a);i++)  // 若 a 能拆成 b*c,则b,c中至少有一个小于根号a,只需判断根号a之前的数能否被 a 整除
		{
			if (a % i == 0)
				break;
		}
		if (i > sqrt(a))
		{
			printf("%d\n", a); 
			count++;
		}
	}
	printf("个数为 count=%d\n", count);
	return 0;
}

/* 计算1-1/2+1/3-1/4+1/5-... -1/100*/
int main_f()
{
	int i;
	double sum = 0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += (1.0 / i)*flag;
		flag = -flag;
	}
	printf("结果为：%f", sum);
	return 0;
}

/* 求一组数最大值 */
int main_g()
{
	/*int i,n;
	int arr[6] = {1,2,3,4,5,6};
	n = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}*/

	int i,len=0;                  // 动态分配数组，实现最大数
	int* arr;
	printf("Please input the length of numbers: \n");
	scanf("%d", &len);
	printf("Please input a group of numbers: ");
	arr = (int*)malloc(len * sizeof(int));

	for (i = 0; i < len; i++)
	{
		scanf("%d",&arr[i]);
	}
	int max = arr[0];
	for (i = 1; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("max = %d", max);
	
	return 0;
}

/* 实现逆序输出字符串 */

void reverse(char *str)
{
	assert(str);
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1; 
	while (left<right)
	{
		char temp=*left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

int main_u()
{
	char nixu[256] = { 0 };
	printf("输入字符串：");
	//scanf("%s", nixu);   
	gets_s(nixu);   //读取一行
	reverse(nixu); 
	printf("逆序后：%s\n", nixu);      
	return 0;
}



/* 打印九九乘法表 */
int main_h()
{
	int i,j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j ,i * j);
		}
		printf("\n");
	}

	//for (i = 9; i > 0; i--)
	//{
	//	for (j = 1; j <= i; j++)
	//		printf("%d*%d=%d\t", i, j, i * j);
	//	printf("\n");
	//}
	return 0;
}


/* 有序数组的二分查找 */
int main_i()                                        // 时间复杂度O（log2 N，比从1到sz一个个查找要节省很多时间
{
	int arr[12] = { 2,4,9,10,13,22,39,41,56,77,100,116 };
	int k = 56; 
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;   // 左下标
	int right = sz - 1;  //右下标

	while (left<=right)        // 当查找的该数不在数组中，最后左右下标相同定位在一个数值上，再下一次下标调整会出现左大右小，说明查找不到
	{
		int mid = (left + right) / 2;   // ***！关键易错
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了！下标为：%d\n", mid);
			break;                                //**！莫要忘了！！
		}
		if (left > right)
		{
			printf("找不到！\n");
		}
	}
	return 0;
}

/* 求阶乘 */
//int main()     //法一
//{
//	int i,n;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("ret=%d", ret);
//
//	return 0;
//}

int jiecheng(int n)  // 法二，利用函数递归
{
	int ret ;
	if (n < 0)
	{
		printf("请重新输入！");
	}
	else if (n == 0 || n == 1)
	{
		ret = 1;
	}
	else
	{
		ret =n * jiecheng(n - 1);
	}
	return ret;
}

int main_j()
{
	int m;
	scanf("%d", &m);
	printf("%d的阶乘为：%d", m, jiecheng(m));
	return 0;
}


int main_k()
{
	char arr1[] = "Welcome to JiangXi!!!";
	char arr2[] = "#####################";
	int left = 0;
	int right = strlen(arr1);
	//int right = sizeof(arr1)/sizeof(arr1[0])-2;

	while (left<=right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);  // 休息1s ,需要 Windows.h
		system("cls");   // 系统执行命令
		left++;
		right--;
	}
	return 0;
}

int main_l()   //输入三次密码登录
{
	int i;
	char password[20];
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：>>");
		scanf("%s",password);
		// if (password == "qiulong123")  错误！等号不能比较字符串，用strcmp
		if (strcmp(password,"qiulong123")==0)
		{
			printf("登录成功！\n");
			break;
		}
	}
	if (i == 3)
	{
		printf("三次密码均错误！请退出...");
	}
	return 0;
}

/* 猜数字小游戏 */
void game()
{
	int r,n;
	r = rand()%100+1;  // 产生1-100的随机数
	//printf("%d\n", r);
	while (1)
	{
		printf("Please guess the number>>:\n");
		scanf("%d", &n);
		if (n < r)
		{
			printf("No! Please guess more\n");
		}
		else if (n > r)
		{
			printf("No! Please guess less\n");
		}
		else
		{
			printf("Yes! you are right!\n");
			break;
		}
		
	}
	printf("The final result is %d\n", r);
}

int main_m()
{
	int m;
	srand((unsigned int)time(NULL));   // 产生随机种子      

	do
	{
		printf("*****************开始游戏********************\n");
		printf("Please input 1 or 0\n");
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit the game...\n");   
			break;
		default:
			printf("Error!\n");
			break;
		}
	} while(m);
	return 0;
}

/* 让电脑系统在一分钟内关机，可作为某种病毒 */
int main_n()                         //将该编译后的exe应用程序通过sc命令行的方式添加到Windows系统服务中,自动启动即可
{
	char input[20];
	system("shutdown -s -t 60");  // 执行60s后关机的系统命令
	/*while (1)
	{
		printf("请注意，电脑即将在一分钟后关机，如果输入：我是猪，则取消关机\n请输入>>");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}*/
again:
	printf("请注意，电脑即将在一分钟后关机，如果输入：我是猪，则取消关机\n请输入>>");  
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
		goto again;
	return 0;
}