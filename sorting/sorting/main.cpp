#include "main.h"
void hello(int n,int m) 
{
	int x = n + m;
	int y = n - m;
	if (x > 10) { cout << "10"<< endl; hello(x, y); }
	if (x > 12) { cout << "12"<<endl; hello(x, y);}
}


int main()
{

	StopWatch b_timer;
	StopWatch i_timer;
	StopWatch s_timer;
	StopWatch shell_timer;
	StopWatch q_timer;
	StopWatch m_timer;

	//���� ����
	int i;
	int size;
	//cout << "�迭�� ũ�� �Է� : ";
	//cin >> size;
	size = 8;
	int *arr = new int[size];
	//int *arr2 = new int[4];
	int arr1[6] = { 2,5,9,10,14,17 };
	int arr2[4] = { 1,5,8,20 };
	int arr_[10] = { 1,18,5,20,9,10,17,14,8,2 };
	init(arr);

	/*
	//cout << "�迭 �Է�: ";
	//for (i = 0; i < size; i++) cin >> arr[i];
	
	arr[0] = 6; 
	arr[1] = 4; 
	arr[2] = 3; 
	arr[3] = 7; 
	arr[4] = 1; 
	arr[5] = 9; 
	arr[6] = 8;*/


	
	char *mark = new char[size];
	for (i = 0; i < size; i++) mark[i] = ' ';
	/*
	cout << "< merge sort >" << endl;
	m_timer.start();
	//merge_0(arr2, arr1, 4, 6, mark);
	//merge_1(arr_, mark,10);
	m_timer.stop();
	cout << "�ɸ��ð�: " << m_timer.getElapsedTime() << "ms" << endl;
	//cout << "�񱳸� " << cnt << "ȸ �����߽��ϴ�." << endl;
	delete[] arr;
	delete[] mark;

	return 0;*/

	int cnt=0;
	int cnt_swap=0;
	cout << "< quick sort >" << endl;
	q_timer.start();
	//
	//quick(arr, mark, size, size/2 ,0,size-1);
	size = 10; quick(arr_, mark, size, size / 2, 0, size - 1);
	q_timer.stop();
	cout << "�ɸ��ð�: " << q_timer.getElapsedTime() << "ms" << endl;
	//cout << "�񱳸� " << cnt << "ȸ �����߽��ϴ�." << endl;
	delete[] arr;
	delete[] mark;



	return 0;

	cout << "< shell sort >" << endl;
	shell_timer.start();
	shell_1(arr, mark,size);
	//insertion(arr, mark, size);
	shell_timer.stop();
	cout << "�ɸ��ð�: " << shell_timer.getElapsedTime() << "ms" << endl;
	return 0;
		//bubble sorting
	/*
	cout << "< bubble sorting >" << endl;
	b_timer.start();
	//bubble_0(arr, mark, size);
	//bubble_1(arr, mark, size);
	//bubble_2(arr, mark, size);
	b_timer.stop();
	cout << "�ɸ��ð�: " << b_timer.getElapsedTime() << "ms" << endl;
	cout << endl;

	return 0;*/

	
	
	//selectionsorting
	cout << "< selection sorting >" << endl;
	s_timer.start();
	
	//�����Ѱ�
	//selection_0(arr, mark, size);
	//
	selection_1(arr, mark, size);

	s_timer.stop();
	cout << "�ɸ��ð�: " << s_timer.getElapsedTime()<<"ms"<< endl;
	cout << endl;
	return 0;

	//insertionsorting
	cout << "< insertion sorting >" << endl;
	i_timer.start();
//	insertion(arr, mark, size, &cnt, &cnt_swap);
	i_timer.stop();
	cout << "�ɸ��ð�: " << i_timer.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] mark;
	return 0;
	
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
	arr[0] = 12;
	arr[1] = 10;
	arr[2] = 13;
	arr[3] = 9;
	arr[4] = 8;
	arr[5] = 3;
	arr[6] = 5;
	arr[7] = 7;
}