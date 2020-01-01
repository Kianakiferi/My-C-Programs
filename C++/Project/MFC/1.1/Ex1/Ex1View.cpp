//Copyright:FANS Corporation
//Author: Kiana~
//Date: 2019-12/29 1:46PM
//Description: CEx1View类的实现
//Version: B0.02

// Ex1View.cpp: CEx1View 类的实现

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex1.h"
#endif

#include <Windows.h>
#include "Ex1Doc.h"
#include "Ex1View.h"

#include "CShape.h"
#include "CShapeDlg.h"
#include "CTestDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx1View

IMPLEMENT_DYNCREATE(CEx1View, CScrollView)

BEGIN_MESSAGE_MAP(CEx1View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDM_SQUARE, &CEx1View::OnMenuSquare)
	ON_COMMAND(IDM_RECTANGLE, &CEx1View::OnMenuRectangle)
	ON_COMMAND(IDM_CIRCLE, &CEx1View::OnMenuCircle)
	ON_COMMAND(IDM_ELLIPSE, &CEx1View::OnMenuEllipse)
	ON_COMMAND(IDTRIANGLE, &CEx1View::OnMenuTriangle)
	ON_COMMAND(IDM_TEXT, &CEx1View::OnMenuText)
	ON_COMMAND(IDM_DELETE, &CEx1View::OnMenuDelete)
	ON_COMMAND(IDM_PROPERTY, &CEx1View::OnMenuProperty)
END_MESSAGE_MAP()

// CEx1View 构造/析构

CEx1View::CEx1View() noexcept
{
	// TODO: 在此处添加构造代码
}

CEx1View::~CEx1View()
{
}

BOOL CEx1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CEx1View 绘图

void CEx1View::OnDraw(CDC* pDC)
{
	//OutputDebugString(L"CView::OnDraw 绘制\n");
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* pShape1 = (CShape*)pDoc->m_Elements[i];
		if (!(pShape1 == NULL))
		{
			pShape1->Draw(pDC);
		}
		else
		{
			//pShape 指针有误
			ASSERT_VALID(pShape1);
		}
	}
}

void CEx1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CEx1View 打印

BOOL CEx1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEx1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEx1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEx1View 诊断

#ifdef _DEBUG
void CEx1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CEx1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CEx1Doc* CEx1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx1Doc)));
	return (CEx1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx1View 消息处理程序

void CEx1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);

	CShape* pShape1;	//CShape类的对象指针

	//OutputDebugString(L"按下 鼠标左键 \n");

	if ((nFlags & MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		//TODO:: 测试代码
		pShape1 = new CSquare(pntLogical.x, pntLogical.y, 100);
		pDoc->m_Elements.Add(pShape1);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
		//OutputDebugString(L"按下 鼠标左键 和 Ctrl键 \n");
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CEx1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);

	CShape* pShape;		//CShape类的对象指针
	CShapeDlg* pShapeDlg = new CShapeDlg(this);	//对话框类的对象指针

	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		pShape = (CShape*)pDoc->m_Elements[i];
		if (pShape->IsMatched(pntLogical))
		{
			int OldShapeType = pShape->GetShapeType();
			pShapeDlg->GetShapeData(pShape);
			//另一种显示对话框的方式
			//pShapeDlg->Create(IDD_SHAPE_DIALOG);
			//pShapeDlg->ShowWindow(SW_SHOWNORMAL);
			if (pShapeDlg->DoModal() == IDOK)
			{
				pShapeDlg->SetShapeData(pShape);
				int NewShapeType = pShape->GetShapeType();

				if(!(NewShapeType = OldShapeType))
				{ 
				ChangeShapeType(pShape);
				}
				pDoc->UpdateAllViews(NULL);
			}
			break;
		}
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}

//鼠标右键菜单
void CEx1View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	//保存 点击鼠标右键时的坐标
	pnt_overall_Cursor = point; 
	ScreenToClient(&pnt_overall_Cursor);

	CMenu popMenu, * pSubMenu;
	popMenu.LoadMenuW(IDR_MENU_MOUSE);
	pSubMenu = popMenu.GetSubMenu(0);	// 取右键菜单的子菜单 

	//ClientToScreen(&point);  //不用转换！这里的point是转换好的

	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

	pSubMenu->Detach();
	pSubMenu->DestroyMenu();
//OutputDebugString(L"弹出右键菜单");
}


void CEx1View::OnMenuSquare()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape1;
	pShape1 = new CSquare(pnt_overall_Cursor.x, pnt_overall_Cursor.y, 150);
	pDoc->m_Elements.Add(pShape1);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CSquare");
}

void CEx1View::OnMenuRectangle()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape;
	pShape = new CRectangle(pnt_overall_Cursor.x, pnt_overall_Cursor.y, 200, 100);
	pDoc->m_Elements.Add(pShape);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CRectangle");
}

void CEx1View::OnMenuCircle()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape;
	pShape = new CCircle(pnt_overall_Cursor.x, pnt_overall_Cursor.y, 80);
	pDoc->m_Elements.Add(pShape);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CCircle");
}

void CEx1View::OnMenuEllipse()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape;	
	pShape = new CEllipse(pnt_overall_Cursor.x, pnt_overall_Cursor.y, 200, 100);
	pDoc->m_Elements.Add(pShape);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CEllipse");
}

void CEx1View::OnMenuTriangle()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape;	
	pShape = new CTriangle(pnt_overall_Cursor.x, pnt_overall_Cursor.y, 200, 173);
	pDoc->m_Elements.Add(pShape);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CTriangle");
}

void CEx1View::OnMenuText()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape;	//Shape类的对象
	pShape = new CText(pnt_overall_Cursor.x, pnt_overall_Cursor.y, -45, L"Hello World!", 16);
	pDoc->m_Elements.Add(pShape);
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	//OutputDebugString(L"插入CText");
}

void CEx1View::OnMenuDelete()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape2;

	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		pShape2 = (CShape*)pDoc->m_Elements[i];
		if (pShape2->IsMatched(pnt_overall_Cursor))
		{
			INT_PTR nMSG;
			nMSG = AfxMessageBox(_T("  您确定要删除嘛?"), MB_YESNO | MB_ICONQUESTION, 0);
			if (nMSG == IDYES)
			{
				//用RemoveAt函数删除Doc类中储存的信息
				pDoc->m_Elements.RemoveAt(i); 
				delete(pShape2);
				pShape2 = NULL;
				pDoc->UpdateAllViews(NULL);
			}
			break;
		}
	}
}


void CEx1View::OnMenuProperty()
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CShape* pShape2;
	CShapeDlg* pShapeDlg = new CShapeDlg(this);

	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		pShape2 = (CShape*)pDoc->m_Elements[i];
		if (pShape2->IsMatched(pnt_overall_Cursor))
		{
			pShapeDlg->GetShapeData(pShape2);
			if (pShapeDlg->DoModal() == IDOK)
			{
				pShapeDlg->SetShapeData(pShape2);
				pDoc->UpdateAllViews(NULL);
			}
			break;
		}
	}
	//OutputDebugString(L"MenuProperty:: 打开CShapeDlg");
}

void CEx1View::ChangeShapeType(CShape* pShape)
{
	// TODO: 在此处添加实现代码.
	int TypeSel = pShape->GetShapeType();
	switch (TypeSel)
	{
	default:
		break;
	}
	
	OutputDebugString(L"ChangeShapeType:: 改变CShape类型\n");
}
