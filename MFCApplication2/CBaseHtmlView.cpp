// CBaseHtmlView.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CBaseHtmlView.h"


// CBaseHtmlView

IMPLEMENT_DYNCREATE(CBaseHtmlView, CHtmlView)

CBaseHtmlView::CBaseHtmlView()
{

}

CBaseHtmlView::~CBaseHtmlView()
{
}

void CBaseHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBaseHtmlView, CHtmlView)
	ON_WM_DESTROY()
	ON_WM_MOUSEACTIVATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CBaseHtmlView 诊断

#ifdef _DEBUG
void CBaseHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CBaseHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CBaseHtmlView 消息处理程序


void CBaseHtmlView::OnDestroy()
{
	CHtmlView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


void CBaseHtmlView::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	CHtmlView::PostNcDestroy();
}


void CBaseHtmlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	Navigate2(L"http://blog.csdn.net/qq_20828983?viewmode=contents", NULL, NULL); //这里的网站可以任意更换
}


int CBaseHtmlView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CHtmlView::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CBaseHtmlView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	if (::IsWindow(m_wndBrowser.m_hWnd))
	{
		CRect rect;
		GetClientRect(rect);
		LONG lWindows = GetWindowLong(GetParent()->GetSafeHwnd(), GWL_EXSTYLE);
		/*		::AdjustWindowRectEx(rect, GetStyle(), FALSE, WS_CLIPSIBLINGS);*/
		::AdjustWindowRectEx(rect, GetStyle(), FALSE, lWindows);
		m_wndBrowser.SetWindowPos(NULL, rect.left, rect.top, 962, 632, SWP_NOACTIVATE | SWP_NOZORDER);
	}
}
BOOL CBaseHtmlView::CreateFromStatic(UINT nID, CWnd* pParent)
{
	CWnd* pStatic = pParent->GetDlgItem(nID);
	if (pStatic == NULL)
		return FALSE;

	CRect rc;
	pStatic->GetWindowRect(&rc);
	pParent->ScreenToClient(&rc);
	pStatic->DestroyWindow();

	if (!CHtmlView::Create(NULL, NULL, (WS_CHILD | WS_VISIBLE), rc, pParent, nID, NULL))
		return FALSE;

	OnInitialUpdate();  //加载网页或html
	SetSilent(TRUE);//add by wh ,bid pop script dlg  true表示允许界面弹出对话框
	return TRUE;
}