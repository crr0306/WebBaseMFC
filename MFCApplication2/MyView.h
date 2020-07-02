//#pragma once
//#include <comdef.h>
//#ifdef _WIN32_WCE
//#error "Windows CE 不支持 CHtmlView。"
//#endif 
#pragma once

#include <afxhtml.h>
#include <comdef.h>

// MyView HTML 视图

class MyView : public CHtmlView
{
	DECLARE_DYNCREATE(MyView)

public:
	MyView();           // 动态创建所使用的受保护的构造函数
	virtual ~MyView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


