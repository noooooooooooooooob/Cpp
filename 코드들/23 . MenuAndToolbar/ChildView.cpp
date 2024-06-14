
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MenuAndToolbar.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(0, 0, 0);
	m_drawMode = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_MYMENU_COMMAND1, &CChildView::OnMymenuCommand1)
	ON_COMMAND(ID_MYMENU_COMMAND2, OnMymenuCommand2)
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_COMMAND(ID_SHAPE_RECT, OnShapeRect)
	ON_COMMAND(ID_SHAPE_CIRCLE, OnShapeCircle)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	ON_BN_CLICKED(101, OnColorRed)
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
	
	CBrush brush(m_color);
	dc.SelectObject(brush);

	if(m_drawMode == 0)
		dc.Rectangle(100, 100, 400, 400);
	else if(m_drawMode == 1)
		dc.Ellipse(100, 100, 400, 400);

}
void CChildView::OnMymenuCommand1()
{
	MessageBox(_T("Command1"));
}
void CChildView::OnMymenuCommand2()
{
	MessageBox(_T("Command2"));
}
void CChildView::OnColorRed()
{
	m_color = RGB(255, 0, 0);
	Invalidate();
}
void CChildView::OnColorGreen()
{
	m_color = RGB(0, 255, 0);
	Invalidate();
}
void CChildView::OnColorBlue()
{
	m_color = RGB(0, 0, 255);
	Invalidate();
}

void CChildView::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_color != RGB(255, 0, 0));
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0));
}


void CChildView::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_color != RGB(0, 255, 0));
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}


void CChildView::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_color != RGB(0, 0, 255));
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}

void CChildView::OnShapeRect() {
	m_drawMode = 0;
	Invalidate();
}
void CChildView::OnShapeCircle() {
	m_drawMode = 1;
	Invalidate();
}


void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
/*
	CMenu menuPopup;

	menuPopup.CreatePopupMenu();
	menuPopup.AppendMenu(MF_STRING, ID_COLOR_RED, _T("Red (&R)"));
	menuPopup.AppendMenu(MF_STRING, ID_COLOR_BLUE, _T("Green (&G)"));
	menuPopup.AppendMenu(MF_STRING, ID_COLOR_GREEN, _T("Blue (&B)"));
	menuPopup.AppendMenuW(MF_SEPARATOR);
	menuPopup.AppendMenu(MF_STRING, ID_SHAPE_RECT, _T("Rect (&R)"));
	menuPopup.AppendMenu(MF_STRING, ID_SHAPE_CIRCLE, _T("Circle (&C)"));
*/
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);

	CMenu* pMenu = menu.GetSubMenu(5);

	pMenu->TrackPopupMenu(
		TPM_LEFTALIGN | TPM_LEFTBUTTON,
		point.x, point.y,
		AfxGetMainWnd());
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_button.Create(_T("Red"), BS_PUSHBUTTON, CRect(10, 10, 200, 60), 
		            this, 101);
	m_button.ShowWindow(true);

	return 0;
}
