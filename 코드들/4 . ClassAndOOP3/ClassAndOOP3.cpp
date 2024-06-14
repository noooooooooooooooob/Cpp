#include "MyCircle.h"
#include "MyRect.h"

MyRect g_a(3, 4, 1, 1, "g_a");
int main()
{
	MyCircle c(100);
	MyRect a, b(50, 30, 3, 4, "Red");
//	b.setSize(b.getX() - b.getY(), b.getHeight());
	a.print();
	b.print();
	return 0;
}
MyRect g_b(0, 0, 1, 1, "g_b");
