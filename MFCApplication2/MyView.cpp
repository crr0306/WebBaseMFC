// MyView.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "MyView.h"


// MyView

IMPLEMENT_DYNCREATE(MyView, CHtmlView)

MyView::MyView()
{

}

MyView::~MyView()
{
}

void MyView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MyView, CHtmlView)
END_MESSAGE_MAP()


// MyView 诊断

#ifdef _DEBUG
void MyView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void MyView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// MyView 消息处理程序
