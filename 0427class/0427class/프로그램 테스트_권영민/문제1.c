#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//문제1

int main()
{
	char name[80];
	int age;
	printf("이름: ");
	scanf("%s", name);
	printf("나이: ");
	scanf("%d", &age);
	printf("%s님의 나이는 %d살 입니다. ", name, age);

	return 0;
}



