﻿
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[30] = "0";
	FILE *fip = fopen("a.txt", "a");
	if (fip == EOF)
	{
		printf("X");
		return 1;
	}
	strcpy(str,"\n hi my name is min");
	int i = 0;
	while (str[i] != 0)
	{
		fputc(str[i], fip);
		i++;
		fputc(10, fip);
	}

	fclose(fip);

	return 0;
}

