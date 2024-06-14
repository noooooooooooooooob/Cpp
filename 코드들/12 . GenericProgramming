#include <iostream>
using namespace std;

template <class T>
class MyArray {
private:
	T* m_pData;
	int m_size;
public:
	MyArray(int n) {
		//if(n<0)..
		m_size = n;
		m_pData = new T [m_size];
	}
	~MyArray() {
		delete[] m_pData;
	}
	MyArray(const MyArray& in) {			// copy constructor
		m_size = in.m_size;
		m_pData = new T[m_size];
		for (int i = 0; i < m_size; i++)
			m_pData[i] = in.m_pData[i];
	}
	MyArray & operator= (const MyArray& in) {
		if (this == &in) return *this;
		delete[] m_pData;
		m_size = in.m_size;
		m_pData = new T [m_size];
		for (int i = 0; i < m_size; i++)
			m_pData[i] = in.m_pData[i];
	}
	T & at(int index) { 
		//if (index <0 || index>m_size - 1) exit(-1);
		return m_pData[index]; 
	}
	int getSize() { return m_size; }
	T& operator[](int index) {return m_pData[index];}
};

template <class T>
T getBigger(T a, T b)
{
	if (a > b) return a;
	else return b;
}

template <class T>
void mySwap(T & a, T & b)		
{
	T temp = a;
	a = b;
	b = temp;
}

#include <vector>				// Standard Template Library
#include <list>

int main()
{
	std::vector<int> va;
	for (int i = 0; i < 10; i++)
		va.push_back(i * 3);

//	for (int i = 0; i < va.size(); i++)
//		cout << va[i] << endl;

	for (int e : va) {					// for-each
		cout << e << endl;
	}


	MyArray<int> arr(10);
	for (int i = 0; i < arr.getSize(); i++)
		arr.at(i) = i * 2;

	for (int i = 0; i < arr.getSize(); i++)
		cout << arr[i] << endl;

	MyArray<string> brr(3);		// copy constructor
	brr[0] = "sejong";
	brr[1] = "software";
	brr[2] = "c++";
	for (int i = 0; i < brr.getSize(); i++)
		cout << brr[i] << endl;

//	arr = brr;


	int a = 10;
	int b = 20;
	float c = 1.3f;
	float d = 4.3f;
	mySwap(a, b);
	mySwap(c, d);
	cout << "a=" << a<<endl;
	cout << std::max(a, b) << endl;
	cout << std::max(c, d) << endl;

	return 0;
}
