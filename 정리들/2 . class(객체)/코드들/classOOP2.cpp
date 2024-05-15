#include <iostream>
using namespace std;

int g_x;

class MyCircle				// class declaration
{
public:						// access modifier
	float m_x, m_y;				// member variables
	float m_r;
	string m_name;

	MyCircle();					// default constructor
	MyCircle(string n);			// constructor overloading
	MyCircle(float x, float y, float r, string n);
	float getArea();			// member functions
	void print();
};

MyCircle::MyCircle() : MyCircle("NoName")			// constructor
								// 반드시, 맨 먼저, 딱 한 번 
{
}

MyCircle::MyCircle(string n) : MyCircle(0,0,1,n)
{
}
MyCircle::MyCircle(float x, float y, float r, string n)
{
	cout << "Constructor!: " <<n<< endl;
	m_x = x;
	m_y = y;
	m_r = r;
	m_name = n;
}



float MyCircle::getArea() 			// member functions
{
	return 3.141592f * m_r * m_r;
}
void MyCircle::print()
{
	cout << "[Circle] (" << m_x << "," << m_y << ") r=" << m_r
		<< " Name:" << m_name 
		<< " Area = " << getArea() << endl;
}

MyCircle g_a("Global Pizza");

int main()
{
	MyCircle a(10,20,10,"Pizza");						// instance, object
	a.print();

	MyCircle b("Wheel");
	b.m_r = 100;
	b.print();

	MyCircle c("NoName");
	c.print();

	return 0;
}


MyCircle g_b("Global Donut");
