#include <iostream>
using namespace std;

#include <string>
class MyShape			// 추상 클래스 (abstract != concrete)
{
public:
	int m_x, m_y;
	MyShape(int x = 0, int y = 0) {
		m_x = x;
		m_y = y;
	}
	virtual ~MyShape() {
		cout << "Shape destroyed" << endl;
	}
	virtual string toString() {
		string out = "(" + to_string(m_x) + "," 
			             + to_string(m_y) + ") ";
		return out;
	}
public:
	// interface 
	virtual void mouseClickStart() {}
	virtual void mouseClickEnd() {}		// 가상 함수
	virtual void draw() = 0;			// 순수 가상 함수
/*
	{
//		cout << "[SHAPE] "<<toString() << endl;
	}
*/
};

class MyRect : public MyShape
{
public:
	int m_w, m_h;
	MyRect(int x, int y, int w, int h) : MyShape(x, y) {
		m_w = w;
		m_h = h;
	}
	~MyRect() {
		cout << "Rect destroyed" << endl;
	}
	virtual string toString() {					// overriding
		string out = MyShape::toString();
		out += " w=" + to_string(m_w) + ", h=" + to_string(m_h);
		return out;
	}
	virtual void draw() {
		//MyShape::draw();
		cout << "[RECT] " << toString() << endl;
	}
};


class MyCircle : public MyShape
{
public:
	int m_r;
	MyCircle(int x, int y, int r) : MyShape(x, y) {
		m_r = r;
	}
	~MyCircle() {
		cout << "Circle destroyed" << endl;
	}
	virtual string toString() {					// overriding
		string out = MyShape::toString();
		out += " r=" + to_string(m_r);
		return out;
	}
	void func() {}

	virtual void draw() {
		func();
		//MyShape::draw();
		cout << "[CIRCLE] " << toString() << endl;
	}

};

int main()
{

	MyShape* arr[3];
	
	arr[0] = new MyCircle(10, 20, 30);
	arr[1] = new MyRect(1, 2, 3, 4);
	arr[2] = new MyCircle(4, 6, 3);

	for (int i = 0; i < 3; i++)
		arr[i]->draw();

	for (int i = 0; i < 3; i++)
		delete arr[i];

	return 0;
}
