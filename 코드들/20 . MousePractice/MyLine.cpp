#include "pch.h"			// pre-compiled header
#include "MyLine.h"


MyLine::MyLine() {
	m_color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

MyLine::MyLine(CPoint p, CPoint q) {
	m_color = RGB(rand() % 256, rand() % 256, rand() % 256);
	m_p = p;
	m_q = q;
}

void MyLine::draw(CDC * pDC) {
	CPen pen(PS_SOLID, 3, m_color);
	pDC->SelectObject(pen);
	pDC->MoveTo(m_p);
	pDC->LineTo(m_q);


}
