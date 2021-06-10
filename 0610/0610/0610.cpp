#include<iostream>
#include<string>
#include<cstdlib>
#include <ctime>
#include <cctype>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
using std::string;
const int NUM = 5;
const string wordlist[NUM] = { "apiary" ,"beetle","cereal"};

class Report 
{
private:
	std::string str;
public:
	Report(const std::string s):str(s) {std::cout << "객체가 생성" << std::endl;}
	~Report() { std::cout<<"객체가 삭제"<< std::endl; }
	void comment() { std::cout << str << std::endl; }
};

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review &r1,const Review &r2) 
{
	if (r1.title < r2.title) return true;
	else if (r1.title == r2.title && r1.title < r2.title) return true;
	else return false;
}

bool worseThan(const Review &r1, const Review &r2) 
{
	if (r1.rating < r2.rating) return true;
	else return false;
}

bool FillReview(Review &rr)
{
	std::cout << "책 제목을 입력하시오 (끝내려면 quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit") return false;
	std::cout << "책 등급(0-10)을 입력하십시오: ";
	std::cin >> rr.rating;
	if (!std::cin) return false;
	while (std::cin.get() != '\n') continue;
	return true;
}
void ShowReview(const Review &rr) 
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

void ouput(const std::string &s) { std::cout << s << " "; }


int main() 
{
	using namespace std;


	return 0;

	string s1[4] = { "fine","fish","fashion","fate" };
	string s2[2] = { "busy","bats" };
	string s3[2] = { "silly","singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), ouput);
	cout << endl;

	copy(s2, s2 + 2,back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), ouput);
	cout << endl;
	
	copy(s3, s3 + 2,insert_iterator<vector<string>>(words,words.begin()));
	for_each(words.begin(), words.end(), ouput);
	cout << endl;

	return 0;

	vector<Review> books;
	Review temp;
	while (FillReview(temp)) books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "감사합니다. 당신은 다음과 같이 입력: \n"
			<< "등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "책 제목을 기준으로 정렬: \n" << "등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);
		/*
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
		{
			ShowReview(*pr);
		}*/

		sort(books.begin(), books.end(), worseThan);
		cout << "책 등급을 기준으로 정렬: \n" << "등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "무작위 순서로 다시 배치: \n" << "등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else cout << "프로그램을 종료합니다.";
	
	return 0;

	vector<int> number(NUM);
	for (int i = 0; i < NUM; i++) 
	{
		cout << "input: ";
		cin >> number[i];
	}
	/*
	for (vector<int>::iterator it = number.begin(); it != number.end(); it++) 
	{
		cout << "ouput: ";
		cout << *it << endl;
	}*/
	

	return 0;
	vector<int> rating(NUM);
	vector<string> titles(NUM);
	cout << NUM << "개의 책 제목과 책 등급(0-10)을 입력: \n";
	int i;
	for (i = 0; i < NUM; i++) 
	{
		cout << i + 1 << "번 책의 제목을 입룍하십시오: ";
		getline(cin, titles[i]);
		cout << i + 1 << "번 책의 등급(0-10)을 입력: ";
		cin >> rating[i];
		cin.get();
	}
	cout << "입력결ㄹ과 출력: \n"
		<< "등급\t제목\n";
	for (i = 0; i < NUM; i++) 
	{
		cout << rating[i] << "\t" << titles[i] << endl;
	}

	return 0;
	//string vacation("I wasndered lonely as a cloud");
	//auto_ptr<string> pvac (&vacation); 

	return 0;
	shared_ptr<string> films[5] = 
	{
	shared_ptr<string>(new string("Alowl Balls")),
	shared_ptr<string>(new string("Blowl Balls")),
	shared_ptr<string>(new string("Clowl Balls")),
	shared_ptr<string>(new string("Elowl Balls")),
	shared_ptr<string>(new string("Flowl Balls"))
	};
	shared_ptr<string> pwin;
	pwin = films[2];

	cout << "최고의 조류 영화상 후보\n";
	for (int i = 0; i < 5; i++) cout<<*films[i] << endl;
	cout << "수상자는 " << *pwin << "!\n";
	cin.get();
	return 0;
	{
	//원래
	//	Report *ps= new Report;
	}
	{ 
		std::auto_ptr<Report> ps(new Report("auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("unique_ptr"));
		ps->comment();
	}
	return 0;

	/*
	using namespace std;﻿
	
	srand(time(0));
	char play;
	cout << "play? y/n";
	cin >> play;
	play = tolower(play);
	while(play=='y')
	{
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '_');
		string badchars;
		int guesses = 6;
		cout << "guess : \n"
			<< length << " words \n"
			<< "one time one word \n"
			<< "opportunity: " << guesses << "번 \n";
		cout << "words : " << attempt << endl;
		while (guesses > 0 && attempt != target) 
		{
			char letter;
			cout << "guess(you) : ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) 
			{
				cout << "이미 추측한 문자 입니다. 다시하십시오\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) 
			{
				cout << "incorrect \n";
				--guesses;
				badchars += letter;
			}
			else 
			{
				cout << "correct \n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) 
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "추측하는 단어: " << attempt << endl;
			if (attempt != target) 
			{
				if (badchars.length() > 0) 
				{
					cout << "틀리게 추측한 문자들: " << badchars << endl;
				}
				cout << "틀릴 수 있는 기회: " << guesses << "번 \n";
			}
		}

		if (guesses > 0) 
		{
			cout << "그렇습니다. 그것이 수수께끼 단어입니다.\n";
		}
		else 
		{
			cout << "안타깝습ㄴ디ㅏ.수수께끼 단어는"<<target<<"입니다.\n";
		}
		cout << "replay? y/n";
		cin >> play;
		play = tolower(play);
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;*/
	/*
	ifstream fin;
	fin.open("to_buy.txt");
	if (fin.is_open() == false) 
	{
		cerr << "파일을 열 수 없습니다.\n"; 
		exit(EXIT_FAILURE);
	}

	string item;
	int count = 0;
	getline(fin, item, '\n');
	while (fin) 
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, '\n');
	}
	cout<<endl << "프로그램을 종료합니다.\n";
	fin.close();
	
	return 0;*/
	/*
	string str = "aaaa";
	char info[100];
	cin.getline(info, 100, ':');
	getline(cin,str, ':');
	cout << str << endl;
	return 0;*/
	/*
	string one("Lottery Winner!");
	cout << one << endl;

	string two(20,'$');
	cout << two<< endl;

	string three(one);
	cout << three << endl;

	one += "Oops!";
	cout << one << endl; //one="Lottery Winner!Oops!"

	two="Sorry! Thats was ";
	three[0] = 'P'; //three="Pottery Winner!"
	string four;
	four = two + three; // four="Sorry! Thats was Pottery Winner!"
	cout << four << endl;
	char alls[] = "All's well that ends well";
	cout << "all 20까지 자른거: "<<endl;
	string five(alls, 20); // five="All's well that ends"
	cout << five << "!\n"; //cout="All's well that ends"+"!\n"

	string six(alls + 6, alls + 10); //six="well" alls[6]부터 alls[10]까지 자름
	cout << six << ", ";
	cout << endl;
	string seven(&five[6], &five[10]); //seven="well" five[6]부터 five[10]까지 자름
	cout << seven << "...\n"; //seven="well"
	string eight(four, 7, 16);  //four 7부터 16글자를 자른 것 즉, four[7]~four[23]
	cout << eight << "in motion!" << endl;
	return 0;*/
}