#include "MyCircle.h"
//#include <cstdlib>

void func()
{
	MyCircle* p = new MyCircle[100];		// memory leak
	delete[] p;
}

MyCircle * func2(int r)
{
	MyCircle* p = new MyCircle(0, 0, r);
	return p;
}


#include <iostream>

int main()
{
	func();
	func();
	func();

	int ia[3];		// static

	int* ip = nullptr;
	delete ip;
	delete ip;
	delete ip;
	delete ip;
	delete ip;
	delete ip;

	char* ch = new char('a');
	delete ch;

	MyCircle* cp = new MyCircle(3,3,3);
	cp->print();
	delete cp;

	int* iarr = new int[10];
	delete [] iarr;
	
	//MyCircle* carr = (MyCircle *)malloc(32);
	MyCircle* carr = new MyCircle[3];
	//free(carr);
	delete [] carr;

	int ** mm = new int*[20];
	for (int j = 0; j < 20; j++)
		mm[j] = new int[30];

	for (int j = 0; j < 20; j++)
		delete[] mm[j];
	delete[] mm;

	int n = 10;
	//MyCircle* darr[n];
	MyCircle** darr = new MyCircle * [n];
	for (int i = 0; i < 10; i++)
		darr[i] = new MyCircle(i, i, i);

	for (int i = 0; i < 10; i++)
		darr[i]->print();

	for (int i = 0; i < 10; i++)
		delete darr[i];
	delete[] darr;



	int* pp = nullptr;

	MyCircle a(0,0,1);
	MyCircle b(10, 20, 100);
	a.print();
	b.print();

	MyCircle* p = &a;
	(*p).m_x = 100;
	p->m_x = 100;
	(*p).print();
	p->print();
	
	return 0;
}
