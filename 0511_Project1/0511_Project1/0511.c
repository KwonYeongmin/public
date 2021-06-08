#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max4(int a, int b, int c, int d);

int max4(int a, int b, int c, int d)
{
	int max;
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	return max;
}
/*
int main() 
{
	int a, b, c, d;

	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("ÃÖ´ñ°ª :%d", max4(a, b, c, d));

	
	
	return 0;
}*/
/*min3(a, b, c);
	printf(" : %d",min3(a,b,c));*/

int min3(int a, int b, int c);
int min3(int a, int b, int c)
{
	int min;
	min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	
	return min;
}