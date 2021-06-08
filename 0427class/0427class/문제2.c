#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Calc_Angle(int hour, int min, int sec);
//문제2
/*
int main()
{
	int angle;
	int num[3];
	printf("몇시 몇분 몇초");
	scanf("%d%d%d",&num[0], &num[1], &num[2]);
	angle = Calc_Angle(num[0], num[1], num[2]);
	printf("%d", angle);

	return 0;
}

float Calc_Angle(int hour,int min,int sec) 
{
	float hour_a, min_a;
	min_a = (float)min * 6.0 + ((float)sec / 60.0) * 6.0; 
	hour_a = (float)hour*30.0 + ((float)min_a/60.0) * 6.0 ;
	

	if (hour_a > min_a) { return (hour_a - min_a); }
	if (hour_a < min_a) { return (min_a - hour_a); }
	if (hour_a == min_a) { return 0; }
}

*/

