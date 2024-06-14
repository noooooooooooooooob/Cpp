#include "MyRect.h"
#include <iostream>
using namespace std;

MyRect::MyRect() : MyRect(0, 0, 0, 0, "black")
{
}
MyRect::MyRect(int x, int y, int w, int h, string c)
{
	cout << "Constructor!!! c=" << c << endl;
	setPos(x, y);
	setSize(w, h);
	m_color = c;
}
MyRect::~MyRect()
{
	cout << "Destructor!!! c=" << m_color << endl;
}

void MyRect::print()
{
	cout << "[Rect] (" << m_x << "," << m_y
		<< ") w=" << m_width << ", h=" << m_height
		<< " color=" << m_color
		<< " area=" << m_area << endl;
}
