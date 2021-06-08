#include <iostream>
#include <string>
using namespace std;
/*
int main()
{

	//p154
	string s1 = "oenguin";
	string s2,s3;

	cout << "string객체를 string객체에 대입할 수 있다: s2 = s1 \n";
	s2 = s1;
	cout << "s1 :" << s1 << ",s2: " << s2 << endl;
	cout << "string객체에 c스타일 문자열을 대입할 수 있다. \n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2 : " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다: s3 =s1+s2\n";
	s3 = s1 + s2;
	cout
		<< "s3: " << s3 << endl;
	cout << "string객체들을 추가 할 수 있다. \n";
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

	cout << "고양이과 동물 한 종을 입력하시오";
	cin >> charr1;
	cout << "고양이과 또 다른 동물 한 종을 입력하시오";
	cin >> str1;

	cout << "아래 동물들은 모두 고양이과입니다.\n";
	cout << charr1<<" "<<charr1 <<" "<< str1<< " " <<str2<<" " <<endl;
	cout << charr2 << "에서 세번째 글자: ";
	cout << charr2[2] << endl;
	cout << str2 << "에서 세번째 글자: ";
	cout << str2[2] << endl;

	return 0;

	//p145

	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "이름을 입력하십시오:\n ";
	//cin.getline(name,ArSize);
	cin.get(name,ArSize);
	cout << "좋아하는 디저트를 입력하십시오:\n ";
	//cin.getline(dessert, ArSize);
	cin.get(dessert, ArSize);
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << "님 ! \n";
	return 0;

	//p141
	const int Size=15;
	char name1[Size];
	char name2[Size] ="C++owboy";
	
	cout << "안녕하세요! 저는 " << name2;
	cout << "입니다. 실례지만 성함이? \n ";
	cin >> name1;
	cout << "아, " << name1 << " 씨! 당신의 이름은 ";
	cout << "아, " << strlen(name1) << " 자입니다만 \n";
	cout << " " << sizeof(name1) << "바이트의 크기의 배열에 저장되었습니다. \n";
	cout << "이름이" << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';
	cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
	cout << name2 << endl;
	cout << "당신의 처음 다섯 문자는 다음과 같습니다: ";
	name1[5] = '\0';
	cout << name1 << endl;

	return 0;

	//6번


	return 0;

	//7번
	float amount_e;
	float amount_a;

	cout << "휘발유 소비량 (유럽 스타일) 입력 (100키로당 리터수) : ";
	cin >> amount_e;

	float g = amount_e*100.0 / 3.875;
	
	amount_a = 62.14 / g*100.0 ;
	
	cout << "휘발유 소비량 (미국 스타일)은(갤런당마일수) " << amount_a<<"이다";


	return 0;

	//5번
	long long num;
	long long a_num;
	cout << "세계 인구수를 입력하시오 ";
	cin >> num;
	cout << "미국의 인구수를 입력하시오 ";
	cin >> a_num;
	cout << "세계 인구수에 미국이 차지하는 비중은 " << (double)a_num / (double)num *100<<"이다";


	return 0;
	//4번
	long min_;

	return 0;
	//2번
	int height_inch;
	int height_feet;
	int weight_pound;

	cout << "키(inch)를 입력하세요. ";
	cin >> height_inch;
	cout << "키(feet)를 입력하세요. ";
	cin >> height_feet;
	cout << "몸무게(pound)를 입력하세요. ";
	cin >> weight_pound;
	cout
		<< "BMI : " <<
	(float)weight_pound / 2.2 / ( ((float)height_feet * 12.0 *0.0254) * ((float)height_feet * 12.0 *0.0254) );
	
	return 0;

	//1번

	int height_cm;
	
	cout << "키(cm)를 입력하세요. ";
	cout << "_____ cm";
	cout << "\b\b\b\b\b\b\b\b";
	cin >> height_cm;
	const float height_m = (float)height_cm * 0.01;
	cout << height_m << endl;

	return 0;



	//3번
	int num1;
	int num2;
	int num3;
	cout << "위도를 도, 분, 초 단위로 입력하시오 : " << endl;
	cout << "먼저 도각을 입력하시오 :";
	cin >> num1;
	cout << "다음에, 분각을 입력하시오 :";
	cin >> num2;
	cout << "끝으로, 초각을 입력하시오 :";
	cin >> num3;

	cout << num1 << " , " << num2 << " , " << num3 << " = " << num1 + float(num2) / 60 + float(num3) / 60 / 60 << "도";

	return 0;
}*/
/*
	char ch = 'M';
	int i = ch;
	char ch2;
	int j;

	cout << ch << "의 아스키코드는 " << i << "입니다." << endl << endl;
	cout << "이 코드에 1을 더해보겠습다." << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "의 아스키코드는 " << i << "입니다." << endl<< endl;

	cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
	cout.put(ch);
	cout << endl;
	ch2=cin.get();
	j = ch2;
	cout << j;

	return 0;
}*/