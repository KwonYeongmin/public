﻿#include "main.h"

int main()
{
	/*
	const char*abc = "abc";
	string data;
	cout << "입력: ";
	cin >> data;

	int j = 0;
	int cnt;
	clock_t start, end;
	start = clock();
	if (bf_match(data, abc, &cnt) == 1)
	{
		cout << endl << abc << "는 " << data << "에 있습니다." << endl;
	}
	end = clock();
	cout << end - start << "ms" << endl;
	return 0;
	*/

	//string data = "abcxdezcabacaadd";
	//string data = "abcxdezcaaddabac";
	//const char*abc = "abbc";string data = "abcxuiom,opyusdfjgkdjgznczmnmdezcaaabbcddklbacshjabacjkl";
	//string data = "abcxdezcaaddabac";
	//string data = "abcxdezcabacabac"; 
	string data = "ababcabcdab"; 

	//const char*abc = "abac";
	const char*abc = "abcd";

	int j = 0;
	int cnt=0;
	clock_t start, end;
	

	cout << endl << "<bm_match>" << endl;
	cnt = 0;
	start = clock();
	int ck3 = bm_match(data, abc, &cnt);
	end = clock();
	if (ck3 != -1)
	{
		cout << abc << "는 " << data << "의 " << ck3 + 1 << "번째에 있습니다. \n";
	}
	else
	{
		cout << abc << "는 " << data << "에 없습니다. \n";
	}
	cout << endl << "<bm_match>" << endl;
	cout << (end - start) << "ms" << endl;
	cout << "비교를 " << cnt << "회 진행" << endl;


		cout<<endl << "<bf_match>" << endl;
	start = clock();
	int ck1 = bf_match(data, abc, &cnt);
	end = clock();
	if (ck1 != -1)
	{
		cout << abc << "는 " << data << "의 " << ck1 << "번째에 있습니다. \n";
	}
	else
	{
		cout << abc << "는 " << data << "에 없습니다. \n";
	}
	
	cout << "<bf_match>" << endl;
	cout << (end - start) << "ms" << endl;
	cout << "비교를 " << cnt << "회 진행" << endl;

	cout << endl << "<kmp match>" << endl;
	cnt = 0;
	start = clock();
	int ck2 = kmp_match(data, abc, &cnt);	
	end = clock();
	if (ck2 != -1)
	{
		cout << abc << "는 " << data << "의 " << ck2 << "번째에 있습니다. \n";
	}
	else
	{
		cout << abc << "는 " << data << "에 없습니다. \n";
	}

	cout << "<kmp match>" << endl;
	cout << (end - start) << "ms" << endl;
	cout << "비교를 " << cnt << "회 진행" << endl;
	
	


	
	return 0;

	

	
	StopWatch b_timer;
	StopWatch i_timer;
	StopWatch s_timer;
	StopWatch shell_timer;
	StopWatch q_timer;
	StopWatch m_timer;
	StopWatch h_timer;
	StopWatch f_timer;

		//변수 선언

	int i;
	
	//arr
	int size=10;
	//cout << "배열의 크기 입력 : ";cin >> size;
	int *arr = new int[size];
	init(arr);
	//for (i = 0; i < size; i++) cin >> arr[i];

	//arr1
	int arr1[12] = { 10,4,5,2,3,8,9,20,14,17,1,7 };
	int size1 = 12;
	//arr2
	int arr2[10] = { 10,9,5,8,3,2,4,6,7,1 };
	int size2 = 10;
	//arr3
	int arr3[11] = { 1,2,3,1,2,4,5,6,5,3,100 };
	int size3 = 11;
	//표시
	char *mark = new char[size];
	for (i = 0; i < size; i++) mark[i] = ' ';



	
		//도수 정렬
	/*
	f_timer.start();
	fsort(arr, mark, size);
	f_timer.stop();
	cout << "걸린시간: " << f_timer.getElapsedTime() << "ms" << endl;
	return 0;
	*/

		//merge 정렬
	/*
	cout << "< merge sort >" << endl;
	m_timer.start();
	//merge_0(arr2, arr1, 4, 6, mark);
	//merge_1(arr_, mark,10);
	m_timer.stop();
	cout << "걸린시간: " << m_timer.getElapsedTime() << "ms" << endl;
	//cout << "비교를 " << cnt << "회 수행했습니다." << endl;
	delete[] arr;
	delete[] mark;

	return 0;*/

	//heap
	/*
	cout << "< heap sort >" << endl;
	//heap(arr, mark,size);
	h_timer.start();
	heap(arr2,mark ,size2 );// compare, SHOW_PROCESS);
	h_timer.stop();
	cout << "걸린시간: " << h_timer.getElapsedTime() << "ms" << endl;
	*/

		//퀵정렬
	/*
	cout << "< quick sort >" << endl;
	q_timer.start();
	//quick(arr1, mark, size1, 0, size1 - 1);
	quick(arr1, mark,  0, size1-1);
	Print(arr1, size1);
	q_timer.stop();
	cout << "걸린시간: " << q_timer.getElapsedTime() << "ms" << endl;
		delete[] mark;
	return 0;*/

	/*
	int cnt=0;
	int cnt_swap=0;
	cout << "< quick sort >" << endl;
	q_timer.start();

	//quick(arr, mark, size, size/2 ,0,size-1);
	size = 10; quick(arr_, mark, size, size / 2, 0, size - 1);
	q_timer.stop();
	cout << "걸린시간: " << q_timer.getElapsedTime() << "ms" << endl;
	delete[] arr;
	delete[] mark;



	return 0;

	cout << "< shell sort >" << endl;
	shell_timer.start();
	shell_1(arr, mark,size);
	//insertion(arr, mark, size);
	shell_timer.stop();
	cout << "걸린시간: " << shell_timer.getElapsedTime() << "ms" << endl;
	return 0;
		//bubble sorting

	cout << "< bubble sorting >" << endl;
	b_timer.start();
	//bubble_0(arr, mark, size);
	//bubble_1(arr, mark, size);
	//bubble_2(arr, mark, size);
	b_timer.stop();
	cout << "걸린시간: " << b_timer.getElapsedTime() << "ms" << endl;
	cout << endl;

	return 0;



	//selectionsorting
	cout << "< selection sorting >" << endl;
	s_timer.start();

	//내가한거
	//selection_0(arr, mark, size);
	//
	selection_1(arr, mark, size);

	s_timer.stop();
	cout << "걸린시간: " << s_timer.getElapsedTime()<<"ms"<< endl;
	cout << endl;
	return 0;

	//insertionsorting
	cout << "< insertion sorting >" << endl;
	i_timer.start();
//	insertion(arr, mark, size, &cnt, &cnt_swap);
	i_timer.stop();
	cout << "걸린시간: " << i_timer.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] mark;
	return 0; */

}


void Print(int *arr, int size)
{
	for (int k = 0; k < size; k++) cout << arr[k] << " ";
	cout << endl;
}
void init(int arr[])
{
	/*
	arr[0] = 5;
	arr[1] = 7;
	arr[2] = 1;
	arr[3] = 4;
	arr[4] = 6;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 9;
	arr[8] = 8;*/
	/*
		arr[0] = 12;
		arr[1] = 10;
		arr[2] = 13;
		arr[3] = 9;
		arr[4] = 8;
		arr[5] = 3;
		arr[6] = 5;
		arr[7] = 7;
		*/

	arr[0] = 10;
	arr[1] = 9;
	arr[2] = 5;
	arr[3] = 8;
	arr[4] = 3;
	arr[5] = 2;
	arr[6] = 4;
	arr[7] = 6;
	arr[8] = 7;
	arr[9] = 1;
}