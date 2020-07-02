//#pragma once
//#include <comdef.h>
//#ifdef _WIN32_WCE
//#error "Windows CE 不支持 CHtmlView。"
//#endif 
#pragma once

#include <afxhtml.h>
#include <comdef.h>
// CBaseHtmlView HTML 视图

class CBaseHtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(CBaseHtmlView)

public:
	CBaseHtmlView();           // 动态创建所使用的受保护的构造函数
	virtual ~CBaseHtmlView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	virtual void PostNcDestroy();
	virtual void OnInitialUpdate(CString url);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	BOOL CreateFromStatic(UINT nID, CWnd* pParent, CString url);
};


