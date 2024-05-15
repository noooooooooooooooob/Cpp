#ifndef _MY_RECT_H_
#define _MY_RECT_H_

class MyRect
{
public:
	int m_x, m_y, m_width, m_height;
	static const int m_maxWidth;
	static const int m_maxHeight;

	MyRect(int x, int y, int w = 0, int h = 0);

};

#endif
