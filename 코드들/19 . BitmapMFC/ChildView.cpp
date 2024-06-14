
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "BitmapMFC1.h"
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
	ON_WM_ERASEBKGND()
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
	CRect rect;
	GetClientRect(rect);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap memBMP;
	memBMP.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(memBMP);

	memDC.Rectangle(rect);

	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP2);

	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);

	int w = bmpInfo.bmWidth;
	int h = bmpInfo.bmHeight;

	// RAM --> VRAM (BLOCK Transfer - blt)
	CDC bmpDC;
	bmpDC.CreateCompatibleDC(&dc);
	bmpDC.SelectObject(bmp);

	//dc.BitBlt(100, 100, w, h, &memDC, 0, 0, SRCCOPY);

	memDC.StretchBlt(0,0,rect.Width(), rect.Height(), 
		          &bmpDC, 0, 0, w, h, SRCCOPY);

	for (int x = 0; x < 256; x++)
		for (int y = 0; y < 256; y++)
			memDC.SetPixel(x, y, RGB(x, 0, y));

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

/*
	CBrush brush(&bmp);
	dc.SelectObject(brush);

	CRect rect;
	GetClientRect(rect);
	dc.Rectangle(0, 0, bmpInfo.bmWidth+100, bmpInfo.bmHeight+100);
*/
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return true;
	//return CWnd::OnEraseBkgnd(pDC);
}
