
#include <stdio.h>

int main()
{
	//문제 7
	
	/*
	for (int j = 5; j <= 19; j =j+3)
	{
		for (int i = 1; i <= 9; i=+3)
		{

			for (int a = 0; a <= 2; a++)
			{
				printf("%d X %d = %d \n", j + a, i + a, (j + a) * (i + a));


			}
			printf(" -------------------------------------------------- \n");
		}
	}
	*/

	int c = 3;
	int m = 2; //시작
	int n = 9;
	printf("구구단 \n");
	for(int i = m; i< n; i+=3)
	{
		printf("-----------------------------------------------------\n");
		for(int j =1; j<10; j++)
		{
			if (i>8)
			{
				for (int a = i; a < c; a++)
				{
					printf("%d X %d = %d", a, j, a*j);
				}
			}
			else
			{
				for (int a = i; a < (c - 1); a++)
				{
					printf("%d X %d = %d", a, j, a*j);
				}
			}
			/*
			if ((n - 1) % c == 0)
			{
				for (int a = i; a <  c; a++)
				{
					printf("%d X %d = %d", a, j, a*j);
				}
			}
			else
			{
				for (int a = i; a <  (c-1); a++)
				{
					printf("%d X %d = %d", a, j, a*j);
				}
			}
			*/
			
			printf("\n");
		}
		 
		
	}
		
	


	return 0;
}

