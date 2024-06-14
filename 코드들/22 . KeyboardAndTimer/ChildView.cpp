
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "KeyboardAndTimer2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_pt = CPoint(100, 100);
	m_dx = 0;
	m_dy = 0;
	m_size = 50;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	dc.Rectangle(m_pt.x - m_size, m_pt.y - m_size, 
		         m_pt.x + m_size, m_pt.y + m_size);



	dc.TextOutW(0, 0, m_str);
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Virtual Key Code 'A'~'Z' '0'~'9' 

	if (nChar == VK_SPACE) {
		CString str;
		str.Format(_T("Key = %d"), nChar);
		MessageBox(str);
	}
	if (nChar == VK_BACK) {
		m_str.Delete(m_str.GetLength() - 1, 1);
		Invalidate();
	}
	switch (nChar) {
	case VK_LEFT:	m_dx = -10;	break;
	case VK_RIGHT:	m_dx = 10; 	break;
	case VK_UP:		m_dy = -10;	break;
	case VK_DOWN:	m_dy = 10;	break;
	default:									break;
	}
	Invalidate();



	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar != VK_BACK) {
		m_str += TCHAR(nChar);
		Invalidate();
	}

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(0, 30, NULL);
	SetTimer(1, 10, NULL);
	
	return 0;
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 0) {
		m_pt.x += m_dx;
		m_pt.y += m_dy;

		if (m_pt.x - m_size < 0) {	m_pt.x = m_size; m_dx = -m_dx;	}
		if (m_pt.y - m_size < 0) { m_pt.y = m_size; m_dy = -m_dy; }

		CRect rect;
		GetClientRect(rect);
		int w = rect.Width();
		int h = rect.Height();

		if (m_pt.x + m_size> w) { 
			m_pt.x = w - m_size; 
			m_dx = -m_dx; 
		}
		if (m_pt.y + m_size > h) {
			m_pt.y = h - m_size;
			m_dy = -m_dy;
		}
		Invalidate();
	}
	else if (nIDEvent == 1) {
		static float time = 0.0f;
		time += 0.1;
		m_size = 50 + 30 * sin(time);
	}



	CWnd::OnTimer(nIDEvent);
}
