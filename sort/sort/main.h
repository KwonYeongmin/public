#pragma once
#pragma once
#include <iostream>
#include <string>
#include<ctime>
#define swap(type,a,b) do {type t=a; a=b;b=t;}while(0)
using namespace std;

void selection_0(int *arr, char *mark, int size);
void selection_1(int *arr, char *mark, int size);
void insertion(int *arr, char * mark, int size);
void bubble_0(int *arr, char * mark, int size);
void bubble_1(int *arr, char * mark, int size);
void bubble_2(int *arr, char * mark, int size);

void shell(int arr[], char mark[], int size);
void shell_1(int arr[], char mark[], int size);

void quick(int arr[], char mark[], int left, int right);

void merge_0(int arr1[], int arr2[], int size1, int size2, char mark[]);
void merge_1(int arr[], char mark[], int size, int left, int right);

int heap(int arr[], char mark[], int size);
void h_sort(int arr[], int size);

void fsort(int arr[], char mark[], int size);

void Print(int *arr, int size);
void init(int arr[]);

class StopWatch
{
public:
	StopWatch() { startTime = clock(); }
	double getStart() { return startTime; }
	double getEnd() { return endTime; }
	void start() { startTime = clock(); }
	void stop() { endTime = clock(); }
	long long getElapsedTime() const { return (endTime - startTime); }
private:
	clock_t startTime;
	clock_t endTime;
};

