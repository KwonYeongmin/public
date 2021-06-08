
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() 
{
	FILE *fp = fopen("a.txt", "r");

	int ch;
	if (fp == EOF) 
	{
		printf("x");
	}
	fclose(fp);
	return 0;
}