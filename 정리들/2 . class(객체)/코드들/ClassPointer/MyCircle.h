#include "MyCircle.h"


MyCircle::MyCircle() : MyCircle(0,0,1)
{
}
MyCircle::MyCircle(int x, int y, float r)
{
	setX(x);
	setY(y);
	setRadius(r);
}

#include <iostream>
using namespace std;
void MyCircle::print()
{
	cout << "[Circle] (" << getX() << "," << getY()
		 << ") r=" << m_r << " area=" << m_area << endl;
}
void MyCircle::updateArea()
{
	m_area = 3.141592 * m_r * m_r;
}
