#include <stdio.h>
#define swap(type,a,b)do{type t =a; a=b; b=t;}while(0)
int main() 
{
	char *s1 = "ABCD";
	char *s2 = "DDDD";
	printf("s1 : %s, s2 : %s \n", s1, s2);
	//printf("s1 : %s, s2 : %s \n",s1,s2);
	swap(char*, s1, s2);
	printf("s1 : %s, s2 : %s \n", s1, s2);

	return 0;
}