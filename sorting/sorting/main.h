#pragma once
#include <iostream>
#include <string>
#include<ctime>
#define swap(type,a,b){type t=a; a=b;b=t;}
using namespace std;

void selection_0(int *arr, char *mark, int size);
void selection_1(int *arr, char *mark, int size);
void insertion(int *arr, char * mark, int size, int *cnt, int *cnt_swap);
void bubble_0(int *arr, char * mark, int size);
void bubble_1(int *arr, char * mark, int size);
void bubble_2(int *arr, char * mark, int size);
void Print(int *arr, int size);
void shell(int arr[], char makr[], int size);

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

