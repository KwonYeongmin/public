#include <iostream>
#include <string>
using namespace std;
/*
int main()
{

	//p154
	string s1 = "oenguin";
	string s2,s3;

	cout << "string��ü�� string��ü�� ������ �� �ִ�: s2 = s1 \n";
	s2 = s1;
	cout << "s1 :" << s1 << ",s2: " << s2 << endl;
	cout << "string��ü�� c��Ÿ�� ���ڿ��� ������ �� �ִ�. \n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2 : " << s2 << endl;
	cout << "string ��ü���� ������ �� �ִ�: s3 =s1+s2\n";
	s3 = s1 + s2;
	cout
		<< "s3: " << s3 << endl;
	cout << "string��ü���� �߰� �� �� �ִ�. \n";
	s1 += s2;
	cout << "s+=s2 --> s1" << s1 << endl;
	s2 += "For a day";
	cout << "s2+=\"for a day\" --> s2=" << s2 << endl;

	return 0;

	//p151

	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "����̰� ���� �� ���� �Է��Ͻÿ�";
	cin >> charr1;
	cout << "����̰� �� �ٸ� ���� �� ���� �Է��Ͻÿ�";
	cin >> str1;

	cout << "�Ʒ� �������� ��� ����̰��Դϴ�.\n";
	cout << charr1<<" "<<charr1 <<" "<< str1<< " " <<str2<<" " <<endl;
	cout << charr2 << "���� ����° ����: ";
	cout << charr2[2] << endl;
	cout << str2 << "���� ����° ����: ";
	cout << str2[2] << endl;

	return 0;

	//p145

	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "�̸��� �Է��Ͻʽÿ�:\n ";
	//cin.getline(name,ArSize);
	cin.get(name,ArSize);
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n ";
	//cin.getline(dessert, ArSize);
	cin.get(dessert, ArSize);
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "�� ! \n";
	return 0;

	//p141
	const int Size=15;
	char name1[Size];
	char name2[Size] ="C++owboy";
	
	cout << "�ȳ��ϼ���! ���� " << name2;
	cout << "�Դϴ�. �Ƿ����� ������? \n ";
	cin >> name1;
	cout << "��, " << name1 << " ��! ����� �̸��� ";
	cout << "��, " << strlen(name1) << " ���Դϴٸ� \n";
	cout << " " << sizeof(name1) << "����Ʈ�� ũ���� �迭�� ����Ǿ����ϴ�. \n";
	cout << "�̸���" << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: ";
	cout << name2 << endl;
	cout << "����� ó�� �ټ� ���ڴ� ������ �����ϴ�: ";
	name1[5] = '\0';
	cout << name1 << endl;

	return 0;

	//6��


	return 0;

	//7��
	float amount_e;
	float amount_a;

	cout << "�ֹ��� �Һ� (���� ��Ÿ��) �Է� (100Ű�δ� ���ͼ�) : ";
	cin >> amount_e;

	float g = amount_e*100.0 / 3.875;
	
	amount_a = 62.14 / g*100.0 ;
	
	cout << "�ֹ��� �Һ� (�̱� ��Ÿ��)��(�����縶�ϼ�) " << amount_a<<"�̴�";


	return 0;

	//5��
	long long num;
	long long a_num;
	cout << "���� �α����� �Է��Ͻÿ� ";
	cin >> num;
	cout << "�̱��� �α����� �Է��Ͻÿ� ";
	cin >> a_num;
	cout << "���� �α����� �̱��� �����ϴ� ������ " << (double)a_num / (double)num *100<<"�̴�";


	return 0;
	//4��
	long min_;

	return 0;
	//2��
	int height_inch;
	int height_feet;
	int weight_pound;

	cout << "Ű(inch)�� �Է��ϼ���. ";
	cin >> height_inch;
	cout << "Ű(feet)�� �Է��ϼ���. ";
	cin >> height_feet;
	cout << "������(pound)�� �Է��ϼ���. ";
	cin >> weight_pound;
	cout
		<< "BMI : " <<
	(float)weight_pound / 2.2 / ( ((float)height_feet * 12.0 *0.0254) * ((float)height_feet * 12.0 *0.0254) );
	
	return 0;

	//1��

	int height_cm;
	
	cout << "Ű(cm)�� �Է��ϼ���. ";
	cout << "_____ cm";
	cout << "\b\b\b\b\b\b\b\b";
	cin >> height_cm;
	const float height_m = (float)height_cm * 0.01;
	cout << height_m << endl;

	return 0;



	//3��
	int num1;
	int num2;
	int num3;
	cout << "������ ��, ��, �� ������ �Է��Ͻÿ� : " << endl;
	cout << "���� ������ �Է��Ͻÿ� :";
	cin >> num1;
	cout << "������, �а��� �Է��Ͻÿ� :";
	cin >> num2;
	cout << "������, �ʰ��� �Է��Ͻÿ� :";
	cin >> num3;

	cout << num1 << " , " << num2 << " , " << num3 << " = " << num1 + float(num2) / 60 + float(num3) / 60 / 60 << "��";

	return 0;
}*/
/*
	char ch = 'M';
	int i = ch;
	char ch2;
	int j;

	cout << ch << "�� �ƽ�Ű�ڵ�� " << i << "�Դϴ�." << endl << endl;
	cout << "�� �ڵ忡 1�� ���غ��ڽ���." << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "�� �ƽ�Ű�ڵ�� " << i << "�Դϴ�." << endl<< endl;

	cout << "cout.put(ch)�� ����Ͽ� char�� ���� ch�� ȭ�鿡 ���: ";
	cout.put(ch);
	cout << endl;
	ch2=cin.get();
	j = ch2;
	cout << j;

	return 0;
}*/