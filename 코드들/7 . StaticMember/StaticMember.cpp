#include <iostream>
using namespace std;

#include "MyRect.h"

class MyStudent
{
private:
	static int s_curId;
	int m_id;
	string m_name;
	float m_score;
public:

	MyStudent(string n, float score = 0)
	{
		m_id = s_curId;
		m_name = n;
		m_score = score;
		s_curId++;
	}
	static void func() {}
	static void setCurId(int curId)
	{
		//m_name = "";
		//print();
		func();
		s_curId = curId;
	}

	void print()
	{
		static int logNo = 0;
		cout << logNo <<"[" << m_id << "] " << m_name << " s=" << m_score << endl;
		logNo++;
	}

};
int MyStudent::s_curId = 0;



class MyPos
{
public:
	int m_x, m_y;
	string m_color;
	MyPos(int x, int y, string c = "black");
};

MyPos::MyPos(int x, int y, string c) {
	m_x = x;
	m_y = y;
	m_color = c;
}

int add(int a, int b, int c = 0, int d = 0);

int add(int a, int b, int c, int d)
{
	return a + b + c + d;
}

void func(const int& a)
{
	int b = 0;
	b *= a;
}

int a = 10;




class MyMath			// wrapper class
{
public:
	static const float PI;
	static void func1() {};
	static void func2() {};
	static void func3() {};
	static void func4() {};
};
const float MyMath::PI = 3.141592;

void addToSum(int in)
{
	static int sum = 0;

	sum += in;
	cout << "sum = " << sum << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
		addToSum(100);


	MyMath::func1();


	a = 100;
	//MyStudent::s_curId = 940001;
	MyStudent::setCurId(940001);

	MyStudent s1("Kim");
	MyStudent s2("Lee");
	MyStudent s3("Park");
	MyStudent s4("Park");



	s1.print();
	s2.print();
	s3.print();
	s4.print();
	s4.print();
	s4.print();
	s4.print();
	s4.print();
	s4.print();


	int aaa = 10;
	func(10);

	cout << add(10, 20) << endl;
	cout << add(10, 20, 30) << endl;
	cout << add(10, 20, 30, 40) << endl;

	//MyPos p1;
	MyPos p2(10, 20);
	MyPos p3(100, 300, "red");

	return 0;
}
