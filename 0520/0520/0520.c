#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void scanning_system();
int int_cmp(const int *a, const int *b);
int bin_search2(const int a[], int n, int key);

void scanning_system_v1();

//p128 Q9
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compr)(const void *, const void *))
{
	int pre, mid, post;
	pre = 0;
	post = nmemb-1;
	
	while (1) 
	{
		mid = (post - pre) / 2 + pre;
		if (pre > post) return 0;
		if((*compr)((int*)))
	}
}



int Bsearch()
{
	int i, nx, ky;
	int *x;
	int *p;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("������ ������ �Է��ϼ��� \n");
	printf("x[0] :");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf("%d", &ky);

	p = (int *)bsearchx(&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void *, const void *)) int_cmp);

	if (p == NULL) puts("�˻��� �����߽��ϴ�.");
	else printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	free(x);
	return 0;
}


int int_cmp(const int *a, const int *b) 
{
	printf("a:%d,b:%d \n", *a, *b);

	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}
/*
int Bsearch() 
{
	int i, nx, ky;
	int *x;
	int *p;
	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("������ ������ �Է��ϼ��� \n");
	printf("x[0] :");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf("%d", &ky);

	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	if (p == NULL) puts("�˻��� �����߽��ϴ�.");
	else printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	free(x);
	return 0;
}
*/


//p115 Q5
int bin_search2(const int a[], int n, int key) 
{
	key = 0;
	while(n>0)
	{
		if (a[n] == a[n - 1]) { key = n - 1; n = n - 1; }
		else break;
	}
	
	return key;
}

int bin_search() 
{

	int *parr;
	char *pscope = { 0 };
	int size;
	int data;


	printf("�������� ���� �Է�:");
	scanf("%d", &size);
	parr = (int*)malloc(sizeof(int)*size);
	pscope = (char*)malloc(sizeof(char)*size);
	printf("�����͸� ������ ������ %d�� �Է� :", size);
	for (int i = 0; i < size; i++) scanf("%d", &parr[i]);
	printf("ã�� ���� ������ :");
	scanf("%d", &data);

	printf("\n");
	printf("  | ");
	for (int i = 0; i < size; i++) { printf("%2d", i); }
	printf("\n----------------------\n");
	printf("  | ");
	int index = size;

	//���� üũ
	index = index / 2;
	for (int i = 0; i < size; i++) pscope[i] = ' ';
	pscope[0] = '<'; pscope[size - 1] = '>'; pscope[index] = '+';
	for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
	printf("\n");

	//�ε���


	while (1)
	{
		printf("%d", index);
		printf(" | ");
		for (int i = 0; i < size; i++) { printf("%2d", parr[i]); }
		printf("\n");
		printf("  | ");

		if (parr[index] == data)
		{
			//�պ��� �˻�
			//;

			printf("%d�� x[%d]�� �ֽ��ϴ�.", data, bin_search2(parr, index, 0));
			break;
		}
		else if (parr[index] > data)
		{
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			pscope[0] = '<'; pscope[index - 1] = '>';
			index = index / 2;
			pscope[index] = '+';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");
			//scanning_system(size, arr, scope,  data,index);

		}
		else if (parr[index] < data) //4 // 7
		{
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			pscope[index + 1] = '<'; pscope[size - 1] = '>';
			index = index + (index / 2) + 1;
			pscope[index] = '+';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");

		}
	}
}



int main() 
{
	scanning_system_v1();
	return 0;
	//p128 Q9
	Bsearch();
	return 0;
	bin_search();
	return 0;
	Bsearch();
	return 0;
}





void scanning_system() 
{
	int *parr;
	char *pscope = { 0 };
	int size;
	int data;


	printf("�������� ���� �Է�:");
	scanf("%d", &size);
	parr = (int*)calloc(size,sizeof(int));
	pscope = (char*)calloc(size,sizeof(char));
	printf("�����͸� ������ ������ %d�� �Է� :",size);
	for(int i=0;i<size;i++) scanf("%d",&parr[i]);
	printf("ã�� ���� ������ :");
	scanf("%d",&data);

	printf("\n");
	printf("  | ");
	for (int i = 0; i < size; i++) { printf("%2d", i); }
	printf("\n----------------------\n");
	printf("  | ");
	int index = size;

	//���� üũ
	index = index / 2;
	for (int i = 0; i < size; i++) pscope[i] = ' ';
	pscope[0] = '<'; pscope[size - 1] = '>'; pscope[index] = '+';
	for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
	printf("\n");

	//�ε���


	while(1)
	{
		printf("%d", index);
		printf(" | ");
		for (int i = 0; i < size; i++) { printf("%2d", parr[i]); }
		printf("\n");
		printf("  | ");

		if (parr[index] == data)
		{
			printf("%d�� x[%d]�� �ֽ��ϴ�.", data, index);
			break;
		}
		else if (parr[index] > data)
		{
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			pscope[0] = '<'; pscope[index - 1] = '>';
			index = index / 2;
			pscope[index] = '+';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");
			//scanning_system(size, arr, scope,  data,index);

		}
		else if (parr[index] < data) //4 // 7
		{
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			pscope[index + 1] = '<'; pscope[size - 1] = '>';
			index = index + (index / 2) + 1;
			pscope[index] = '+';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");

		}
	}
	free(pscope);
	free(parr);
}

void scanning_system_v1()
{
	int *parr;
	char *pscope = { 0 };
	int size;
	int data;


	printf("�������� ���� �Է�:");
	scanf("%d", &size);
	parr = (int*)calloc(size, sizeof(int));
	pscope = (char*)calloc(size, sizeof(char));
	printf("�����͸� ������ ������ %d�� �Է� :", size);
	for (int i = 0; i < size; i++) scanf("%d", &parr[i]);
	printf("ã�� ���� ������ :");
	scanf("%d", &data);

	printf("\n");
	printf("  | ");
	for (int i = 0; i < size; i++) { printf("%2d", i); }
	printf("\n----------------------\n");
	printf("  | ");
	int index = size;

	//���� üũ
	index = index / 2;
	for (int i = 0; i < size; i++) pscope[i] = ' ';
	//pscope[0] = '<'; pscope[size - 1] = '>'; 
	pscope[index] = '*';
	for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
	printf("\n");

	//�ε���


	while (1)
	{
		printf("%d", index);
		printf(" | ");
		for (int i = 0; i < size; i++) { printf("%2d", parr[i]); }
		printf("\n");
		

		if (parr[index] == data)
		{
			printf("%d�� x[%d]�� �ֽ��ϴ�.", data, index);
			break;
		}
		else if (parr[index] > data)
		{
			printf("  | ");
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			//pscope[0] = '<'; pscope[index - 1] = '>';
			index = index / 2;
			pscope[index] = '*';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");
			//scanning_system(size, arr, scope,  data,index);

		}
		else if (parr[index] < data) //4 // 7
		{
			printf("  | ");
			//����, �ε��� �� ����
			for (int i = 0; i < size; i++) pscope[i] = ' ';
			//pscope[index + 1] = '<'; pscope[size - 1] = '>';
			index = index + (index / 2) + 1;
			pscope[index] = '*';
			for (int i = 0; i < size; i++) printf("%2c", pscope[i]);
			printf("\n");

		}
	}

}
