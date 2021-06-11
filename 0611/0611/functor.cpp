/*
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T &t) :cutoff(t) {}
	bool operator()(const T &v) { return v > cutoff; }
};
void outint(int n) { std::cout << n <<" "; }

int main() 
{
	using std::list;
	using std::cout;
	using std::endl;


	return 0;

	TooBig<int>f100(188);
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "원래의 리스트:\n";
	for_each(yadayada.begin(),yadayada.end(),outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	
	yadayada.remove_if(TooBig<int>(50)); // 'f100'=60보다 크면 다 remove
	etcetera.remove_if(TooBig<int>(200));  //200보다 크면 다 remove
	cout << "정비된 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}*/