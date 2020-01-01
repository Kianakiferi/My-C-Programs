
// Ex1View.h: CEx1View 类的接口
//

#pragma once
#include "CShape.h"

class CEx1View : public CScrollView
{
protected: // 仅从序列化创建
	CEx1View() noexcept;
	DECLARE_DYNCREATE(CEx1View)

// 特性
public:
	CEx1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CEx1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnMenuSquare();
	afx_msg void OnMenuRectangle();
	afx_msg void OnMenuCircle();
	afx_msg void OnMenuEllipse();
	afx_msg void OnMenuTriangle();
	afx_msg void OnMenuText();
//	afx_msg void OnMenuEdit();
	afx_msg void OnMenuDelete();
	CPoint pnt_overall_Cursor;
	afx_msg void OnMenuProperty();
	void ChangeShapeType(CShape* pShape);
};

#ifndef _DEBUG  // Ex1View.cpp 中的调试版本
inline CEx1Doc* CEx1View::GetDocument() const
   { return reinterpret_cast<CEx1Doc*>(m_pDocument); }
#endif

