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
	MyString(const MyString& in);
	MyString & operator=(const MyString& in);

	~MyString();

	const char* getStr() { return m_pData; }
	char & getCharAt(int index) { 
		//if (index < 0 || index>m_length - 1)
		return m_pData[index]; 
	}

	void setStr(const char* in);
	void append(const char* in);
	void append(const MyString& in);
	int getStrLength(const char* in);
};

MyString::MyString() : MyString("")
{
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
MyString::MyString(const MyString& in)
{
	cout << "copy construtor" << endl;
	m_pData = nullptr;
	*this = in;
}
MyString & MyString::operator=(const MyString& in)
{
	cout << "assignment operator" << endl;
	delete[] m_pData;

	m_length = in.m_length;
	m_pData = new char[m_length + 1];
	for (int i = 0; i < m_length; i++)
		m_pData[i] = in.m_pData[i];
	m_pData[m_length] = '\0';
	
	return *this;
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
	while (in[len] != '\0') len++;
	return len;
}
void MyString::append(const MyString & in)
{
	int len = in.m_length;
	if (len == 0) return;

	int new_length = m_length + len;
	char* new_data = new char[new_length + 1];
	for (int i = 0; i < m_length; i++)
		new_data[i] = m_pData[i];
	for (int i = 0; i < len; i++)
		new_data[i + m_length] = in.m_pData[i];
	new_data[new_length] = '\0';

	delete[] m_pData;
	m_pData = new_data;
}
void MyString::append(const char* in)
{
	int len = getStrLength(in);
	if (len == 0) return;

	int new_length = m_length + len;
	char* new_data = new char[new_length + 1];
	for (int i = 0; i < m_length; i++)
		new_data[i] = m_pData[i];
	for (int i = 0; i < len; i++)
		new_data[i + m_length] = in[i];
	new_data[new_length] = '\0';

	delete[] m_pData;
	m_pData = new_data;
}

int g_a = 10;
int & getA()
{
	return g_a;
}

void func(MyString & in)
// MyString in = str3
{
	cout << in.getStr() << endl;
}


int main()
{

	int & b = getA();
	b = 100;
	cout << b << endl;

	MyString str1;
	MyString str2("sejong");

	str1.setStr("software");
	str2.append(str1);
	cout << str1.getStr() << endl;
	cout << str2.getStr() << endl;

	str2.getCharAt(0) = 'S';

	//MyString str3(str1);
	MyString str3 = str1;			// copy
	//cout << str3.getStr() << endl;
	func(str3);

	str3 = str2 = str1;
//	str3.operater=(str1);			// assignment operator

	return 0;
}
