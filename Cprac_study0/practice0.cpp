#define _CRT_SECURE_NO_WARNINGS��

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>

/* ð������ */
#define SIZE 10      //�Ӵ�С�Ƚ�ʮ���ɼ�
int main_a(void)
{
	int leo[SIZE] = { 73,68,86,93,80,77,92,61,79,82 };
	int i, j;
	printf("\n**********����ǰ**********\n");
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
	
	for (i=0;i<9;i++)   // i:�Ƚ� 9 ��
		for(j=0;j<9-i;j++)   // j��ÿ�ֱȽ� 9-i ��
			if (leo[j] < leo[j + 1])  
			{
				int temp;
				temp = leo[j];
				leo[j] = leo[j + 1];
				leo[j + 1] = temp;
			}

	printf("\n**********�����**********\n");
	for (i = 0; i < 10; i++)
		printf("%d ", leo[i]);

	return 0;
}

/* ͨ�÷��� */
int main_b()
{
	int leo[] = { 73,68,86,93,80,77,92,61,79,82 };
	int i, j, temp;
	int n;
	n = sizeof(leo) / sizeof(int);
	printf("\n**********����ǰ**********\n");
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
	printf("\n**********�����**********\n");
	for (i = 0; i < n; i++)
		printf("%d ", leo[i]);

	return 0;
}



/* �����������Լ�� */
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
	printf("���Լ��Ϊ��%d\n",n);
	return 0;
}

/* ��ӡ1000-2000�������� */
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
	printf("�� %d ����",count);
	return 0;
}

/* ��ӡ100-200֮������� */
// ��һ
//int main()
//{
//	int a;
//	for (a = 100; a <= 200; a++)
//	{
//		int i= 0;   
//		int count = 0;
//		for (i = 2; i < a ; i++)          // �Գ������� 2 �� a-1 ֮����û�����ܹ����� a
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
//	printf("����Ϊ count=%d\n", a);
//	return 0;
//}

// ���������Ż���
int main_e()
{
	int a, i;
	int count = 0;
	for (a = 100; a <= 200; a++)
	{
		for (i=2;i <= sqrt(a);i++)  // �� a �ܲ�� b*c,��b,c��������һ��С�ڸ���a,ֻ���жϸ���a֮ǰ�����ܷ� a ����
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
	printf("����Ϊ count=%d\n", count);
	return 0;
}

/* ����1-1/2+1/3-1/4+1/5-... -1/100*/
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
	printf("���Ϊ��%f", sum);
	return 0;
}

/* ��һ�������ֵ */
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

	int i,len=0;                  // ��̬�������飬ʵ�������
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

/* ��ӡ�žų˷��� */
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


/* ��������Ķ��ֲ��� */
int main_i()                                        // ʱ�临�Ӷ�O��log2 N���ȴ�1��szһ��������Ҫ��ʡ�ܶ�ʱ��
{
	int arr[12] = { 2,4,9,10,13,22,39,41,56,77,100,116 };
	int k = 56; 
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;   // ���±�
	int right = sz - 1;  //���±�

	while (left<=right)        // �����ҵĸ������������У���������±���ͬ��λ��һ����ֵ�ϣ�����һ���±��������������С��˵�����Ҳ���
	{
		int mid = (left + right) / 2;   // ***���ؼ��״�
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
			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
			break;                                //**��ĪҪ���ˣ���
		}
		if (left > right)
		{
			printf("�Ҳ�����\n");
		}
	}
	return 0;
}

/* ��׳� */
//int main()     //��һ
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

int jiecheng(int n)  // ���������ú����ݹ�
{
	int ret ;
	if (n < 0)
	{
		printf("���������룡");
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
	printf("%d�Ľ׳�Ϊ��%d", m, jiecheng(m));
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
		Sleep(1000);  // ��Ϣ1s ,��Ҫ Windows.h
		system("cls");   // ϵͳִ������
		left++;
		right--;
	}
	return 0;
}

int main_l()   //�������������¼
{
	int i;
	char password[20];
	for (i = 0; i < 3; i++)
	{
		printf("���������룺>>");
		scanf("%s",password);
		// if (password == "qiulong123")  ���󣡵ȺŲ��ܱȽ��ַ�������strcmp
		if (strcmp(password,"qiulong123")==0)
		{
			printf("��¼�ɹ���\n");
			break;
		}
	}
	if (i == 3)
	{
		printf("����������������˳�...");
	}
	return 0;
}

/* ������С��Ϸ */
void game()
{
	int r,n;
	r = rand()%100+1;  // ����1-100�������
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
	srand((unsigned int)time(NULL));   // �����������      

	do
	{
		printf("*****************��ʼ��Ϸ********************\n");
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

/* �õ���ϵͳ��һ�����ڹػ�������Ϊĳ�ֲ��� */
int main_n()                         //���ñ�����exeӦ�ó���ͨ��sc�����еķ�ʽ��ӵ�Windowsϵͳ������,�Զ���������
{
	char input[20];
	system("shutdown -s -t 60");  // ִ��60s��ػ���ϵͳ����
	/*while (1)
	{
		printf("��ע�⣬���Լ�����һ���Ӻ�ػ���������룺��������ȡ���ػ�\n������>>");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
	}*/
again:
	printf("��ע�⣬���Լ�����һ���Ӻ�ػ���������룺��������ȡ���ػ�\n������>>");  
	scanf("%s", input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
	}
	else
		goto again;
	return 0;
}