#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//����1

int main()
{
	char name[80];
	int age;
	printf("�̸�: ");
	scanf("%s", name);
	printf("����: ");
	scanf("%d", &age);
	printf("%s���� ���̴� %d�� �Դϴ�. ", name, age);

	return 0;
}



