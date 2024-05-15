#ifndef _MY_RECT_
#define _MY_RECT_  

#include <string>
using namespace std;

class MyPosition
{
public: 
	int m_x, m_y;
};

class MyRect
{
private:
	MyPosition m_pos;
	int m_x, m_y;
	int m_width, m_height;
	int m_area;
	string m_color;
	void updateArea() { m_area = m_width * m_height; }

public:
	MyRect();
	MyRect(int x, int y, int w, int h, string c);
	~MyRect();


	int getX() { return m_x; }		// getter = accessor
	int getY() { return m_y; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	void setPos(int x, int y) { m_x = x; m_y = y; }
	// setter = mutator
	void setSize(int w, int h)
	{
		if (m_width == w && m_height == h) return;
		if (w < 0) w = 0;
		m_width = w;
		if (h < 0) h = 0;
		m_height = h;
		updateArea();
	}

	void print();

};

#endif
