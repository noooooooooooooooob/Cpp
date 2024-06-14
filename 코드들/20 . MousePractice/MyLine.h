#ifndef _MY_LINE_H_
#define _MY_LINE_H_


class MyLine
{
public:
	CPoint m_p, m_q;
	COLORREF m_color;
	MyLine();
	MyLine(CPoint p, CPoint q);
	void draw(CDC* pDC);
};


#endif
