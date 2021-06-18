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
		count++;
		if (data[pd] == abc[px])
		{
			pd++; px++; 
			ck++;
			//출력
			//mark[pd - 1] = '+';
			//print_match(mark, len, px, pd, data, abc);
		}
		else
		{
			px = 0;
			pd -= (ck - 1); ck = 0;
			//출력
			//mark[pd] = '|';
			//print_match(mark, len, px, pd, data, abc);
		}
		print_match(mark, len, px, pd, data, abc);

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
		count++;
		if (data[pd] == abc[px])
		{
			pd++; px++;
			ck++; 
			//출력
			//mark[pd - 1] = '+';
			//print_match(mark, len, px, pd, data, abc);
		}
		else
		{
			if (ck != 0)
			{
				for (m = 0; m < pd+1; m++)
				{
					if (data[ck - 1] == abc[m]) { px = m + 1;break;}
				}
				ck = 0; 
			}
			else { px = 0; pd = pd - px + 1; }
			//출력
			//mark[pd] = '|';
			//print_match(mark,len, px, pd,data,abc);
		}
		print_match(mark, len, px, pd, data, abc);

	}

	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}



int bm_match(const string data, const char* abc, int *cnt)
{

	int len = strlen(abc); //4
	int Len = data.length(); //16
	char *mark = new char[Len];
	int i;
	int p = len - 1;
	int pd = p; int px = p;
	int ck = 0;
	for (i = 0; i < Len; i++) mark[i] = ' ';
	int count = 0;


	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < Len; i++) mark[i] = ' ';
		count++;
		if (data[pd] == abc[px])
		{
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] 
				<<" , ck: "<<ck<< endl;
			*/

			if (px == p || ck!=0) 
			{
				pd--; px--;
			}
			else 
			{
				pd++; px = p;
				ck++;
			}
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px]
				<< " , ck: " << ck << endl;
			mark[pd - 1] = '+';
			int m = len - 1 - px;
			print_match(mark, Len, m, pd, data, abc);*/
		}
		else
		{
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] 
				<< " , ck: " << ck << endl;*/

			if (px == len - 1) 
			{
				px--;
			}
			else if (px==0) 
			{
				px += p; pd += p+1;
			}
			else 
			{
				px--;
			}
			/*mark[pd - 1] = '|';
			int m = len - 1 - px;
			print_match(mark, Len, m, pd, data, abc);
			
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] 
				<< " , ck: " << ck << endl;*/
		}
		print_match(mark, Len, px, pd, data, abc);
	}

	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px-1);
	}
	else return -1;
}


int bm_match_1(const string data, const char* abc, int *cnt)
{

	int len = strlen(abc); //4
	int Len = data.length(); //16
	char *mark = new char[Len];
	int i;
	int p=len-1;
	int pd = p; int px = p;
	int ck = 0;
	int ck2 = 0;
	for (i = 0; i < Len; i++) mark[i] = ' ';
	int count = 0;
	

	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < Len; i++) mark[i] = ' ';
		count++;
		if (data[pd] == abc[px])
		{
			ck++;
			//출력
			//체크해야할 것
			// 1. px가 마지막인지 
			
			 if (ck2 == 2) { px += (len - 1); pd++; }
			 else 
			 {
				if (px == len - 1) 
				{
					pd--; ck2 = 1; 
				}
				else 
				{ ck2 = 2; }
				px--; 
			}			 
		}
		else
		{
			if (px == 0) 
			{ 
				if (ck != 0) { pd += len; ck = 0; }
				else { pd++; }
				 px += (len-1);
			}
			else px--; 
		}
		print_match(mark, Len, px, pd, data, abc);
	}

	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}


int bm_match_0(const string data, const char* abc, int *cnt)
{
	
	int len = strlen(abc); //4
	int Len = data.length(); //16
	char *mark = new char[Len];
	int i;
	int pd = len-1; int px = len-1;
	int ck = 0;
	for (i = 0; i < Len; i++) mark[i] = ' ';
	int count = 0;
	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < Len; i++) mark[i] = ' ';
		count++;
		if (data[pd] == abc[px])
		{
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] << endl;
			mark[pd] = '+';
			print_match(mark, Len, px - len, pd-len, data, abc);
			pd--; px--; ck++;
			//출력
			
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] << endl;*/
		}
		else 
		{
			//출력
			mark[pd] = '|';
			print_match(mark, Len, px - len, pd - len, data, abc);

			if (ck != 0) 
			{
				pd += ck;
				px += ck;
				ck = 0;
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] << endl;*/
			}
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] << endl;*/
			pd += len;
		
			/*
			cout << "data[" << pd << "]: " << data[pd]
				<< " ,abc[" << px << "]: " << abc[px] << endl;*/


		}
		
		//print_match(mark, Len, px, pd, data, abc);
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