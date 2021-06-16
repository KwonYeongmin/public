#include "main.h"
int bf_match(const string data, const char* abc, int *cnt)
{
	int pd = 0; int px = 0;
	unsigned int m, i;
	int count = 0;
	int len = data.length();
	char *mark = new char[len];
	int ck = 0;
	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < len; i++) mark[i] = ' ';

		if (data[pd] == abc[px])
		{
			pd++; px++; count++;
			ck++;
			//출력
			mark[pd - 1] = '+';
			print_match(mark, len, px, pd, data, abc);
		}
		else
		{
			px = 0;
			pd -= (ck - 1); ck = 0;
			//출력
			mark[pd] = '|';
			print_match(mark, len, px, pd, data, abc);
		}
	}
	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}


int kmp_match(const string data, const char* abc, int *cnt)
{
	int pd = 0; int px = 0;
	unsigned int m, i;
	int count = 0;
	int len = data.length();
	int ck = 0;
	char *mark = new char[len];
	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < len; i++) mark[i] = ' ';

		if (data[pd] == abc[px])
		{
			pd++; px++;
			ck++; count++;
			//출력
			mark[pd - 1] = '+';
			print_match(mark, len, px, pd, data, abc);
		}
		else
		{

			if (ck != 0)
			{
				for (m = 0; m < strlen(abc); m++)
				{
					if (data[ck - 1] == abc[m])
					{
						px = m + 1;
						break;
					}
				}
				ck = 0; //cout << "m+1 : " << m + 1 << " , px: " << px << ", abc[px] : " << abc[px] << endl;
			}
			else { px = 0; pd = pd - px + 1; }
			//출력
			mark[pd] = '|';
			print_match(mark,len, px, pd,data,abc);
		}
	}

	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}

void print_match(char mark[],int len,int px, int pd,string data,const char abc[]) 
{
	std::cout << data << endl;
	for (int i = 0; i < len; i++) std::cout << mark[i];
	std::cout << endl;
	for (int i = 0; i < pd - px; i++) std::cout << " ";
	std::cout << abc << endl;
}