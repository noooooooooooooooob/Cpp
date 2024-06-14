#include "MyRect.h"

const int MyRect::m_maxWidth = 100;
const int MyRect::m_maxHeight = 100;

MyRect::MyRect(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}
