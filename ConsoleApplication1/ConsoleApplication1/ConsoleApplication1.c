// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/*
	printf("be happy \n");
	printf("my\tfriend");
	*/
	/*
	printf("%d와 %d를 더하면 %d이다 \n",10,20,10+20);
	printf("\n %.1lf %1f", 3.45, 4.5);
	*/
	
	//printf("Be\rHappy!\nBaby");
	
	/*
	printf("%d\n", 12);
	printf("%d\n", 014);
	printf("%d\n", 0xc);
	*/
	
	/*
	printf("%o\n", 12);
	printf("%x\n", 12);
	printf("%d\n", 12);
	*/
	
	/*
	printf("%1lf\n", 1e6);
	printf("%7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);
	*/
	
	/*
	printf("%c \n", 'a');
	printf("%c %s \n", '1', "abcd");
	*/

	/*
	int a,b,c ;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);
	*/
	
	/*
	char ch1 = 'A';
	char ch2 = 65;
	*/

	/*
	short sh = 32767;
	short _sh = 32767;

	int in = 2147483647;
	int _in = 2147483648;
	
	long ln = 2147483647;
	long _ln = 2147483648;
	
	long long lln = 123451234512345;
	long long _lln = 123451234512346;

	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("int형 변수 출력 : %d\n", _in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long형 변수 출력 : %ld\n", _ln);
	printf("long long형 변수 출력 : %lld\n", lln);
	printf("long long형 변수 출력 : %lld\n", _lln);
	*/	

	/*
	float ft = 1.234567890123456789;
	double db = 1.234567890123456789;

	printf("float형 변수의 값: %.20f \n", ft);
	printf("double형 변수의 값: %.20lf \n", db);
	*/
	
	/*
	char fruit[20] = "strawberry";
	printf("딸기 : %s\n", fruit);
	printf("딸기잼 : %s %s\n", fruit,"jam");
	*/
	
	
	/*
	char fruit[25] = "딸기 빙수";
	int price = 20000;
	printf("%s %d \n", fruit , price);
	strcpy(fruit, "돼지바 빙수");
	printf("%s\n", fruit);
	*/

		//변수 고정
	// const int income = 0;

/*
	int kor = 70;
	int eng = 80;
	int mat = 90;

	int sum;
	sum = kor + eng + mat;

	printf("국어 : %d\n", kor);
	printf("영어 : %d\n", eng);
	printf("수학 : %d\n", mat);

	printf("총점 : %d\n", sum);
*/

/*
	int subject[3] = {70,80,90};
	int sum;
	int ad;
	sum = subject[0] + subject[1] + subject[2];
	int count = sizeof(subject) / sizeof(int);

	ad = sum / count;

	printf("국어 : %d\n", subject[0]);
	printf("영어 : %d\n", subject[1]);
	printf("수학 : %d\n", subject[2]);
	printf("총점 : %d\n", sum);
	printf("평균 : %d\n", ad);
*/
	
	/*
	int a;

	scanf_s("%d", &a ,sizeof(int));
	printf("입력된 값 : %d\n", a);
	*/
	/*
	int age;
	double height;

	printf("나이와 키를 입력하세요 : \n");
	scanf_s("%d%lf", &age, &height,sizeof(int), sizeof(int));
	printf("나이는 %d살, 키는 %.1lfcm입니다 \n ", age, height);
	*/

	
	/*
	char grade;
	char name[20];

	printf("학점 입력 : ");
	scanf("%c", &grade);
	printf(" 이름 입력 : ");
	scanf("%s", name);
	printf("%s의 학점은 %c입니다. \n", name,grade);
	
	*/
	
	
	/*char ch;
	printf("문자입력 : ");
	scanf("%c", &ch);
	printf("%c문자의 아스키 코드의 값은 %d입니다.", ch,ch);
	*/
	
	/*
	int a = 5, b = 5;
	int pre, post;
	
	printf("초깃값 a = %d, b = %d\n", a, b);

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("현잿값 a = %d, b = %d\n", a, b);
	printf("전위형:(++a)*3 = %d,  후위형:(b++)*3 = %d \n", pre, post);
	printf("전위형:(++a)*3 = %d \n", pre);
	*/
	
	/*
	int a = 30;
	int res;

	res = (a > 10) && (a < 20);
	printf("(a > 10)&& (a < 20) : %d \n", res);
	res = (a < 10) || (a > 20);
	printf("(a < 10) || (a > 20) : %d \n", res);
	res = !(a >= 10) ;
	printf("!(a >= 10) : %d \n", res);

	int a = 10, b = 20, res;
	a + b;
	printf("%d + %d = %d \n", a, b, a + b);

	res = a + b;
	printf("%d + %d = %d \n", a, b, res);
	*/
	//문제 p97
	/*
	double a = 4.0, b = 1.2;
	printf(" %0.2lf + %0.2lf = %0.2lf \n", a, b, a + b);
	printf(" %0.2lf - %0.2lf = %0.2lf \n", a, b, a - b);
	printf(" %0.2lf * %0.2lf = %0.2lf \n", a, b, a * b);
	printf(" %0.2lf / %0.2lf = %0.2lf \n", a, b, a / b);
*/
	//문제 p99
/*
	double kor = 3.0, eng = 5.0, mat = 4.0;
	double credits;
	int res;
	double kScore = 3.8, eScore = 4.4, mScore = 3.9;
	double grade;

	credits = kor + eng + mat;
	grade = (kScore + eScore + mScore) / 3.0;
	res = ((credits >= 10) && (grade > 4.0));
	printf("%d",res);
	*/	 
	quiz();
	
	return 0;
}

int quiz()
{
//문제1
	/*
	double number1;
	double number2;
	double number3;

	printf("실수 입력 1 (e표기법): ");
	scanf("%0.2le", &number1);
	printf("입력된 실수 :%lf ",number1);

	printf("실수 입력 2 (e표기법): ");
	scanf("%0.2le", &number2);
	printf("입력된 실수 :%lf ", number2);


	printf("실수 입력 3 (e표기법): ");
	scanf("%0.4le", &number3);
	printf("입력된 실수 :%lf ", number3);
*/


	//문제2
	//한자리 숫자인 경우에 앞에 0을 붙여 출력
	/*
	int sec;
	
	int hour;
	int minute;
	int second;
	
	printf("입력 : ");
	scanf("%d", &sec);
	minute = (sec / 60) % 60 ;
	hour = (sec / 60) / 60;
	second = sec % 60;
	printf("출력 : %d 초는 %d시간 %d분 %d초 입니다.", sec,hour,minute,second );
	*/
	

	//문제3
	//세과목의 점수 하나하나 입력받기
	//총점을 구하기
	/*int nInput;
	double dTotal;
	
	printf("첫번째 과목의 점수 입력 : ");
	scanf("%d", &nInput);
	dTotal = nInput + nInput;
	
	printf("두번째 과목의 점수 입력 : ");
	scanf("%d", &nInput);
	dTotal = nInput + nInput;

	printf("세번째 과목의 점수 입력 : ");
	scanf("%d", &nInput);
	dTotal = nInput + nInput;

	
	printf("세 과목의 점수가 : %0.2lf \n",dTotal);
	printf("평균 : %0.2lf", dTotal / 3.0);
	*/
	
	//문제4
	/*사용자로부터 정수 3개를 입력받아서 각 a,b,c에 저장하고 조건 연산자를 사용하여
	이들 변수 중 가장 큰 값을 출력하는 프로그램을 작성하라.
	

	int a, b, c;
	int res1, res2, res3;

	printf("첫번째 정수를 입력하시오");
	scanf("%d", &a);
	printf("두번째 정수를 입력하시오");
	scanf("%d", &b);
	printf("세번째 정수를 입력하시오");
	scanf("%d", &c);
	*/

	//문제5
	/*인간 수명이 100년이라고 가정하고, 담배를 하루에 M개피를 피면 
	수명이 20분이 단축된다. 어떤 사람이 성인이 된 후 N년간 담배를 피웠다면 
	수명은 얼마나 단축되었고 몇살까지 살 수 있는가?
	(N =20 결과값을 가지고 서로 비교)
	*/
	int die_count_min;
	int live_count_min;
	int n = 20;
	int m = 1;
	int hour, min, hour_, min_, day_, day;

	live_count_min = (100 * 365 * 24 * 60) - ((n*m) * 365 * 20);
	die_count_min = (n*m) * 365 * 20;
	
	hour = (live_count_min / 60) % 24;
	hour_ = (die_count_min / 60) % 24;
	
	day = (live_count_min / 60) / 24;
	day_ = (die_count_min / 60) / 24;
	
	min = live_count_min % 60;
	min_ = die_count_min % 60;

	printf("단축된 수명: %d 일 , %d 시간,  %d 분 \n",day_,hour_,min_);
	printf("수명 :%d 일 , %d 시간, %d 분", day, hour, min);
	/*
	
*/

}
