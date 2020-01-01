#pragma once
//Copyright:FANS Corporation
//Author: Kiana~
//Date: 2019-12/29 1:46PM
//Description: CShapeDlg类
//Version: B0.02

// CShapeDlg 对话框

class CShapeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeDlg)

public:
	CShapeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShapeDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CComboBox m_Combo_Shape_Type;
	int m_int_Combo_ShapeType_Sel;

	CEdit m_Edit_X;
	CEdit m_Edit_Y;
	CEdit m_Edit_W;
	CEdit m_Edit_H;
	CEdit m_Edit_Angle;

	CString m_str_Edit_X;
	CString m_str_Edit_Y;
	CString m_str_Edit_W;
	CString m_str_Edit_H;
	CString m_str_Edit_Angle;

	CEdit m_Edit_Text;
	CString m_str_Edit_Text;
	CStatic m_Static_Text;

	CMFCColorButton m_ColorButton_FillColor;
	COLORREF m_COLREF_ColorButton_FillColor;
	CComboBox m_Combo_FillStyle;
	int m_int_Combo_FillType_Sel;

	CMFCColorButton m_ColorButton_EdgeColor;
	COLORREF m_COLREF_ColorButton_EdgeColor;
	CComboBox m_Combo_EdgeType;
	int m_int_Combo_EdgeType_Sel;

	CEdit m_Edit_Edeg_Thickness;
	CString m_str_Edit_Edge_Thickness;
	void GetShapeData(CShape* pShape);
	void SetShapeData(CShape* pShape);

	afx_msg void OnCbnSelchangeComboboxFillStyle();
	afx_msg void OnCbnSelchangeComboboxEdgeStyle();
	afx_msg void OnEnChangeEditEdgeThickness();
	
	afx_msg void OnCbnSelchangeComboShapeType();
};
