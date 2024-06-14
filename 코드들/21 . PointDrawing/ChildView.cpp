
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MousePractice3.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_RBut = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
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
	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(BLACK_BRUSH);

	POSITION pos = m_pts.GetHeadPosition();
	while (pos != NULL) {
		CPoint pt = m_pts.GetNext(pos);
		dc.Ellipse(pt.x - 2, pt.y - 2, pt.x + 2, pt.y + 2);
	}

	if (m_RBut == true) {
		dc.SelectStockObject(NULL_BRUSH);
		CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
		dc.SelectObject(pen);
		dc.Rectangle(m_p.x, m_p.y, m_q.x, m_q.y);
	}



}
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON) {
		m_pts.AddTail(point);
		Invalidate();
	}
	if (nFlags & MK_RBUTTON) {
		m_q = point;
		Invalidate();
	}
	
	CWnd::OnMouseMove(nFlags, point);
}
void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_RBut = true;
	m_p = point;
	CWnd::OnRButtonDown(nFlags, point);
	SetCapture();
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	m_RBut = false;
	m_q = point;

	POSITION pos = m_pts.GetHeadPosition();
	while (pos != NULL) {
		POSITION cur_pos = pos;
		CPoint pt = m_pts.GetNext(pos);

		if (m_p.x < pt.x && m_q.x > pt.x &&
			m_p.y < pt.y && m_q.y > pt.y) {
			m_pts.RemoveAt(cur_pos);
		}
	}
	Invalidate();

	CWnd::OnRButtonUp(nFlags, point);
	ReleaseCapture();
}
