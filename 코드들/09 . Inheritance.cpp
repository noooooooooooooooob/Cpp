#include <iostream>
using namespace std;

class MyPos
{
protected:
	int m_x, m_y;
public:

	MyPos()
	{
		m_x = 0;
		m_y = 0;
	}
	MyPos(int x, int y)
	{
//		if(x<0 || y<0 || x>100 || y>100) .. 
		m_x = x;
		m_y = y;
	}
	~MyPos() {};
	void draw()
	{
		cout << "[Position] (" << m_x << "," << m_y << ")" << endl;
	}
	void move(int dx, int dy)
	{
		m_x += dx;
		m_y += dy;
	}
};

class MyColorPos : public MyPos
{
public:
	string m_color;
	MyColorPos() : MyColorPos(0,0,"black")
	{
	}
	MyColorPos(int x, int y, string c) : MyPos(x, y)
	{
		m_color = c;
	}
	~MyColorPos() {};
	void colorDraw()
	{
		cout<<"[ColorPos] ("<<m_x<<","<<m_y<<") c="<<m_color<<endl;
	}
};

void func(MyPos * p, int mode = 0)
{
	if (mode != 0)
	{
		MyColorPos* pp = (MyColorPos*)p;
		pp->colorDraw();
	}
	else p->draw();
}

int main()
{
	MyPos a, b(10, 20);
	MyColorPos c(3,4, "red");
	a.draw();
	b.draw();
	c.draw();
	c.colorDraw();

	MyPos* p = &c;		// upcasting
	p->draw();

	MyPos& r = c;
	r.draw();

	MyColorPos* p1 = (MyColorPos*) p; // downcasting
	p1->colorDraw();

	func(&a);
	func(&c,1);

	return 0;
}
