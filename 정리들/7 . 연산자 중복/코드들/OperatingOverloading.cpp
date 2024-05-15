#include <iostream>
using namespace std;

class MyVec
{
private:
	float m_x, m_y, m_z;
public:
	MyVec(float x = 0, float y = 0, float z = 0)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	float getX() { return m_x; }
	float getY() { return m_y; }
	float getZ() { return m_z; }
	void print()
	{
		cout << "(" << m_x << "," << m_y << "," << m_z << ")" << endl;
	}
	MyVec operator-(const MyVec & b);
	MyVec operator*(const float a);
	MyVec & operator+=(const MyVec& b);
	bool operator==(const MyVec& b);
	MyVec& operator++();
	MyVec operator++(int aaa);


	friend MyVec operator*(const float b, const MyVec& a);
	friend float getDistance(const MyVec &a,const MyVec &b);
	friend MyVec operator+(const MyVec &a, const MyVec &b);
	friend ostream& operator<<(ostream& o, const MyVec& a);
};

float getDistance(const MyVec& a, const MyVec& b)
{
	return sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x)
		+ (a.m_y - b.m_y) * (a.m_y - b.m_y)
		+ (a.m_z - b.m_z) * (a.m_z - b.m_z));
}

// operator (연산자) 
// ex: assignment operator : =
// MyVec b = a;			// copy constructor
// b = a;					// assignment operator
// 3가지 종류의 연산자
// - 피연산자가 1개인 경우 (Unrary operator) : a++, ++a 
// - 피연산자가 2개인 경우 (binary operator) : a+b, a*b, a/b, a==b, a>b 
// - 피연산자가 3개인 경우 (trinary operator): (a>b)?a:b; 


//int operator+(int a, int b);
//float operator+(float a, float b);			// overloading
// a + b --> operator+(a,b)
MyVec operator+(const MyVec &a, const MyVec &b)		// operator overloading
{
	MyVec out;
	out.m_x = a.m_x + b.m_x;
	out.m_y = a.m_y + b.m_y;
	out.m_z = a.m_z + b.m_z;
	return out;
}
// a - b --> a.operator-(b)
MyVec MyVec::operator-(const MyVec & b)		// operator overloading
{
	MyVec out;
	out.m_x = m_x - b.m_x;
	out.m_y = m_y - b.m_y;
	out.m_z = m_z - b.m_z;
	return out;
}
MyVec& MyVec::operator+=(const MyVec& b)		// operator overloading
{
	m_x += b.m_x;
	m_y += b.m_y;
	m_z += b.m_z;
	return *this;
}


MyVec MyVec::operator*(const float b)		// operator overloading
{
	MyVec out;
	out.m_x = m_x * b;
	out.m_y = m_y * b;
	out.m_z = m_z * b;
	return out;
}
bool MyVec::operator==(const MyVec& b)
{
	return (m_x == b.m_x && m_y == b.m_y && m_z == b.m_z);
}


MyVec operator*(const float b, const MyVec & a)		// operator overloading
{
	MyVec out;
	out.m_x = a.m_x * b;
	out.m_y = a.m_y * b;
	out.m_z = a.m_z * b;
	return out;
}

MyVec& MyVec::operator++()
{
	cout << "++a" << endl;
	m_x++;
	m_y++;
	m_z++;
	return *this;
}
MyVec MyVec::operator++(int aaa)
{
	cout << "a++" << endl;
	MyVec out = *this;
	m_x++;
	m_y++;
	m_z++;
	return out;
}


ostream & operator<<(ostream& o, const MyVec& a)
{
	o << "(" << a.m_x << "," << a.m_y << "," << a.m_z << ")";
	return o;
}

int main()
{
	MyVec a(3, 4, 5);
	MyVec b(1, 1, 1);
	MyVec c = a + b;		// c = operator+(a,b)
	MyVec d = a - b;		// d = a.operator-(b)
	MyVec e = a * 10;		// e = a.operator*(10)
	MyVec f = 3 * a + b;	// f = operator*(3, a)
	//	a.multi(3).add(b);
	e = f += b;				// f.operator+=(b)

	cout << c <<endl;
	cout << d << endl;
	cout << e << endl;
	cout << a+b << endl;

	c += a;
	++a;					// a.operator++()
	a++;					// a.operator++(int a)
	
	if (c == a) cout << "equal!" << endl;
	cout << a << b << c << d << e << f << endl;


	return 0;
}
