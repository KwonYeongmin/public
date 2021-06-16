#include <iostream>
/*
void swapr(int &a, int &b) 
{
	int temp;
	temp = a; a = b; b = temp;	
}

void swapp(int *a, int *b)
{
	int temp; temp = *a; *a = *b; *b = temp;
}

void swapv(int a, int b)
{
	int temp; temp = a;a = b;b = temp;
}

int main() 
{
	using namespace std;

	int jeno = 22;
	int mark = 23;
	cout << endl<<"<기본 값>" << endl;
	cout << "jeno의 나이: " << jeno << "살" ;
	cout << " , mark의 나이: " << mark << "살" << endl;

	cout << "<참조 이용>" << endl;
	swapr(jeno, mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;
	jeno = 22; mark = 23;
	cout << "<포인터 이용>" << endl;
	swapp(&jeno, &mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;
	jeno = 22; mark = 23;
	cout << "<값으로 전달 이용>" << endl;
	swapv(jeno, mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;

	return 0;

	int rats = 101;
	int & rodents = rats;
	int *p = &rats;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents<<endl;

	int bunnies = 50;
	p = &bunnies;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents << endl;

	rodents = bunnies;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents << endl;
	return 0;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << " , rats = " << rats;
	cout << " , rodents = " << rodents << endl;

	cout << "bunnies의 주소 = " << (unsigned long)&bunnies;
	cout << "rats의 주소 = " << (unsigned long)&rats;
	cout << " , rodents의 주소 = " << (unsigned long)&rodents << endl;
	return 0;
	/*
	int rats = 101;
	int value = rats;
	int *pointer = &rats;
	int & reference = rats;
	cout << "rats = " << rats;
	cout << " , value = " << value;
	cout << " , *pointer = " << *pointer;
	cout << ", reference = " << reference << endl;
	reference++;
	cout << "rats = " << rats;
	cout << " , value = " << value;
	cout << " , *pointer = " << *pointer;
	cout << ", reference = " << reference << endl;

	cout << "rats의 주소 = " << (unsigned long)&rats;
	cout << " , value의 주소 = " << (unsigned long)&value<<endl;
	cout << "pointer의 값 = " << (unsigned long)pointer;
	cout << ", reference의 주소 = " << (unsigned long)&reference << endl;
	
	return 0;
}*/