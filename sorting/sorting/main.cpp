#include "main.h"
int main()
{
	StopWatch b_timer;
	StopWatch i_timer;
	StopWatch s_timer;

	//변수 선언
	int i;
	int size;
	cout << "배열의 크기 입력: ";
	cin >> size;
	int *arr = new int[size];
	//cout << "배열 입력: ";
	//for (i = 0; i < size; i++) cin >> arr[i];
	/*
	arr[0] = 6; 
	arr[1] = 4; 
	arr[2] = 3; 
	arr[3] = 7; 
	arr[4] = 1; 
	arr[5] = 9; 
	arr[6] = 8;*/
	arr[0] = 8;
	arr[1] = 1;
	arr[2] = 4;
	arr[3] = 2;
	arr[4] = 7;
	arr[5] = 6;
	arr[6] = 3;
	arr[7] = 5;
	char *mark = new char[size];
	for (i = 0; i < size; i++) mark[i] = ' ';
	int cnt=0;
	int cnt_swap=0;
	cout << "< shell sorting >" << endl;
	shell(arr, mark,size);
	return 0;
		//bubble sorting
	/*
	cout << "< bubble sorting >" << endl;
	b_timer.start();
	//bubble_0(arr, mark, size);
	//bubble_1(arr, mark, size);
	//bubble_2(arr, mark, size);
	b_timer.stop();
	cout << "걸린시간: " << b_timer.getElapsedTime() << "ms" << endl;
	cout << endl;

	return 0;*/

	
	
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
	insertion(arr, mark, size, &cnt, &cnt_swap);
	i_timer.stop();
	cout << "걸린시간: " << i_timer.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] mark;
	return 0;
	
}


void Print(int *arr, int size)
{
	for (int k = 0; k < size; k++) cout << arr[k] << " ";
	cout << endl;
}