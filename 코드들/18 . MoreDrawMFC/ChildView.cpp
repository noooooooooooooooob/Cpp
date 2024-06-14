
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "DrawMoreMFC2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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

typedef float MyFloat;
typedef int * pJUNGSOO;

void CChildView::OnPaint() 
{
	MyFloat f = 10.0f;

	int aaa = 100;
	pJUNGSOO a = &aaa;


	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CPen redPen(PS_SOLID, 3, RGB(255, 0, 0));
	CPen bluePen(PS_DOT, 1, RGB(0, 0, 255));

	CBrush grayBrush(HS_DIAGCROSS, RGB(0, 0, 0));

	dc.SelectObject(redPen);
	
	dc.Rectangle(100, 100, 300, 200);
	dc.Ellipse(100, 100, 300, 200);
	dc.MoveTo(100, 100);
	dc.LineTo(300, 200);
	dc.LineTo(400, 100);
	dc.LineTo(500, 200);

	CRect rect;
	GetClientRect(rect);
	rect.left;		// x1
	rect.top;		// y1
	int w = rect.right;		// x2
	int h = rect.bottom;	// y2
	//dc.Ellipse(rect.left, rect.top, rect.right, rect.bottom);
	//dc.Ellipse(rect);
	int div = 20;
	float dw = w / (float) div;
	float dh = h / (float) div;

	for (int i = 0; i < div; i++)
	{
		dc.MoveTo(0,i*dh);
		dc.LineTo(i*dw,h);
	}

	dc.SelectObject(bluePen);
	dc.SelectObject(grayBrush);

	// ascii : 0~127	1byte (abcd.. 1234 !@#$ )
	// unicode : 2byte~4byte (encoding 숫자 -> 문자: utf-8)

	//std::string
	COLORREF c = RGB(255, 0, 0);
	dc.SetTextColor(c);
	CString str1 = _T("세종대학교");
	dc.TextOutW(0, 0, str1);	// W: Wide Character (uni-code)

	dc.SetTextColor(RGB(0, 0, 255));
	dc.SetBkColor(RGB(0, 255, 0));
	//dc.SetBkMode(TRANSPARENT);
	dc.SetBkMode(OPAQUE);
	dc.SetTextAlign(TA_CENTER);
	CString str2;
	str2.Format(_T("w=%d, h=%d"), w, h);
	//printf("w=%d, h=%d", w, h);
	dc.TextOutW(w/2, h/2, str2);

	CFont font;
	font.CreatePointFont(200,_T("궁서체"));

	dc.SelectObject(font);

	dc.SetTextAlign(TA_LEFT);
	CRect text_rect(50,50,250,150);
	dc.Rectangle(text_rect);
	dc.DrawText(_T("세종대학교"), text_rect, 
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	dc.Rectangle(50, 50, w - 50, h - 50);

	CPoint pts[3] = { CPoint(400,300),
					  CPoint(300,450),
					  CPoint(500,450) };
	CRgn rgn;		// region
	rgn.CreatePolygonRgn(pts, 3, ALTERNATE);  // CPoint *

	dc.SelectStockObject(BLACK_BRUSH);
	dc.PaintRgn(&rgn);
}

