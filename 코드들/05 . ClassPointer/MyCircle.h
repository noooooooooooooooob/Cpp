#ifndef _MY_CIRCLE_H_
#define _MY_CIRCLE_H_ 

class MyCircle
{
public:
	int m_x, m_y;
	float m_r;
	float m_area;
	void updateArea();

public:
	MyCircle();
	MyCircle(int x, int y, float r);

	int getX()			{ return m_x; }
	int getY()			{ return m_y; }

	void setX(int x)	{ m_x = x; }
	void setY(int y)	{ m_y = y; }
	void setRadius(float r) { m_r = r; updateArea(); }

	void print();
};

#endif
