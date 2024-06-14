#include <iostream>
using namespace std;

#include <string>
class MyShape
{
public:
	int m_x, m_y;
	string m_color;
	MyShape* m_pNext;

	static MyShape* s_pHead;
	static void addData(MyShape * p) {
		if (s_pHead == nullptr) s_pHead = p;
		else
		{
			s_pHead->addTail(p);
		}
	}
	void addTail(MyShape* p) {
		if (m_pNext == nullptr) m_pNext = p;
		else
			m_pNext->addTail(p);
	}

//	MyShape() : MyShape(0,0,"black")
//	{
//	}
	MyShape(int x = 0, int y = 0, string c = "black") {
		m_x = x;
		m_y = y;
		m_color = c;
		m_pNext = nullptr;
	}
	virtual string getString()
	{
		string out = "("+ to_string(m_x) +", "+to_string(m_y)+") c="+m_color;
		return out;
	}
	virtual void draw()
	{
		//cout <<"[SHAPE] ("<<m_x<<","<<m_y<<") c="<<m_color<<endl;
		cout << "[SHAPE] " << getString() << endl;
	}
};

MyShape* MyShape::s_pHead = nullptr;


class MyRect : public MyShape
{
public:
	int m_width, m_height;
	MyRect(int x, int y, int w, int h, string c) : MyShape(x, y, c)
	{
		m_width = w;
		m_height = h;
	}
	string getString()
	{
		string out = MyShape::getString();
		out += " w=" + to_string(m_width)+" h=" + to_string(m_height);
		return out;
	}

	void draw()				// function overriding (      )
							// ~ function overloading ( ߺ )
	{
		cout <<"[RECT] "<<getString()<<endl;
	}
};

class MyCircle : public MyShape
{
public:
	float m_radius;
	MyCircle(int x, int y, float r, string c) : MyShape(x, y, c)
	{
		m_radius = r;
	}
	string getString()
	{
		string out = MyShape::getString();
		out += " r=" + to_string(m_radius);
		return out;
	}
	void draw()
	{
		cout << "[CIRCLE] "<<getString()<<endl;
	}
};

void func(MyShape* p)	// polymorphism (      ) <= dynamic binding
{
	p->draw();
}

int main()
{
	MyShape a;
	MyRect b(10, 20, 3, 4, "red");
	MyCircle c(5, 5, 10, "green");

	a.draw();					// static binding
	b.draw();
	c.draw();

//	a.m_pNext = &b;
//	b.m_pNext = &c;
//	MyShape* pCur = &a;

	MyShape::addData(new MyRect(1, 2, 3, 4, "red"));
	MyShape::addData(new MyCircle(1, 2, 3, "blue"));
	MyShape::addData(new MyRect(10, 20, 30, 4, "white"));
	MyShape::addData(new MyShape(1, 2, "green"));

	MyShape* pCur = MyShape::s_pHead;
	while (pCur != nullptr)
	{
		pCur->draw();
		pCur = pCur->m_pNext;
	}

/*
	MyShape* arr[3];
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;

	for (int i = 0; i < 3; i++)
		arr[i]->draw();
*/
//	MyShape* p = &c;
//	p->draw();

//	func(&a);
//	func(&b);
//	func(&c);

	return 0;
}
