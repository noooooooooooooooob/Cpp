#include <iostream>
using namespace std;

class MyString
{
private:
	int m_length;
	char* m_pData;
public:
	MyString();
	MyString(const char* in);
	~MyString();

	const char* getStr() { return m_pData; }
	void setStr(const char* in);
	void append(const char* in);
	void append(MyString& in);
	int getStrLength(const char* in);
};

MyString::MyString() : MyString("")
{
//	m_length = 0;
//	m_pData = new char [1];
//  m_pData[0] = '\0';
}
MyString::MyString(const char* in)
{
	cout << "constructor" << endl;
	m_length = getStrLength(in);
	m_pData = new char[m_length + 1];
	for (int i = 0; i < m_length; i++)
		m_pData[i] = in[i];
	m_pData[m_length] = '\0';

}
void MyString::setStr(const char* in)
{
	delete[] m_pData;

	m_length = getStrLength(in);
	m_pData = new char[m_length + 1];
	for (int i = 0; i < m_length; i++)
		m_pData[i] = in[i];
	m_pData[m_length] = '\0';
}

MyString::~MyString()
{
	cout << "destructor" << endl;
	delete[] m_pData;
}
int MyString::getStrLength(const char* in)
{
	int len = 0;
	while (in[len] != '\0') len ++;
	return len;
}
void MyString::append(MyString& in)
{
	append(in.getStr());
}
void MyString::append(const char* in)
{
	int len = getStrLength(in);
	if (len == 0) return;

	int new_length = m_length + len;
	char * new_data = new char[new_length + 1];
	for (int i = 0; i < m_length; i++)
		new_data[i] = m_pData[i];
	for (int i = 0; i < len; i++)
		new_data[i + m_length] = in[i];
	new_data[new_length] = '\0';
	
	delete[] m_pData;
	m_pData = new_data;
}
class MyPos
{
public:
	int m_x, m_y;
	MyPos() {
		m_x = 0;
		m_y = 0;
	}
	MyPos(int x, int y) {
		m_x = x;
		m_y = y;
	}
	float getDistanceFrom(MyPos in);
};

float computeDistance(MyPos a, MyPos b)
{
	return sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x)
		      + (a.m_y - b.m_y) * (a.m_y - b.m_y));
}

float MyPos::getDistanceFrom(MyPos in)
{
	return computeDistance(*this, in);
}


#include <string>

void func(MyString &in)
{
	//MyString aaa;
	cout << "function begins!!!" << endl;
	cout << in.getStr() << endl;
	cout << "function ends!!!" << endl;
}

void swap(int &a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int nn = 10;
	int mm = 20;
	swap(nn, mm);
	cout << nn << " " << mm << endl;

	MyString str1;
	MyString str2("sejong");

	
	str1.setStr("software");
	str2.append("software");
	//str2.append(str1);
	cout << str1.getStr() << endl;
	cout << str2.getStr() << endl;
	
	func(str1);
	//str1 = str2;
	//cout << str1.getStr() << endl;
	//MyString str3 = str1;
	
/*
	string str1;
	string str2("sejong");

	str1 = "software";
//	str2 = str2 + str1;
	str2.append(str1);
	cout << str1.c_str() << endl;
	cout << str2.c_str() << endl;
*/
	MyPos a, b(3, 4);
	cout << computeDistance(a, b) << endl;
	cout << a.getDistanceFrom(b) << endl;
	cout << b.getDistanceFrom(a) << endl;
	//cout << a << endl;
	//MyPos c = a + b;

	return 0;
}
