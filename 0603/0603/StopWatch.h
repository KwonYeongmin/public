#pragma once
class StopWatch
{
public:
	StopWatch();
	double getStart();
	double getEnd();
	void start(double start);
	void stop(double end);
	long long getElapsedTime();
private:
	double startTime;
	double endTime;
};

StopWatch::StopWatch() 
{
	startTime = 0.0;
}
double StopWatch::getStart()
{
	return startTime;
}
double StopWatch::getEnd()
{
	return endTime;
}
void StopWatch::start(double start) 
{
	startTime = start;
}
void StopWatch::stop(double end) 
{
	endTime = end;
}
long long StopWatch::getElapsedTime() 
{
	const long t = 1000.0*(endTime - startTime);
	return t;
}