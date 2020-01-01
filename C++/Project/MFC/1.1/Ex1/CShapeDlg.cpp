//Copyright:FANS Corporation
//Author: Kiana~
//Date: 2019-12/29 9:46PM
//Description: CShapeDlg类的实现
//Version: B0.02

// CShapeDlg.cpp: 实现文件

#include "pch.h"
#include "Ex1.h"
#include "CShape.h"
#include "CShapeDlg.h"
#include "afxdialogex.h"

// CShapeDlg 对话框

IMPLEMENT_DYNAMIC(CShapeDlg, CDialogEx)

CShapeDlg::CShapeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPE_DIALOG, pParent)
	, m_str_Edit_X(_T("0.0"))
	, m_str_Edit_Y(_T("0.0"))
	, m_str_Edit_H(_T("0.0"))
	, m_str_Edit_W(_T("0.0"))
	, m_str_Edit_Angle(_T(""))
	, m_str_Edit_Edge_Thickness(_T(""))

	, m_str_Edit_Text(_T(""))
{
	m_int_Combo_ShapeType_Sel = 0;
	m_int_Combo_FillType_Sel = 0;
	m_int_Combo_EdgeType_Sel = 0;
	m_COLREF_ColorButton_FillColor = RGB(244, 143, 177);
	m_COLREF_ColorButton_EdgeColor = RGB(0, 0, 0);
}

CShapeDlg::~CShapeDlg()
{
}

void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SHAPE_TYPE, m_Combo_Shape_Type);

	DDX_Control(pDX, IDC_EDIT_X, m_Edit_X);
	DDX_Control(pDX, IDC_EDIT_Y, m_Edit_Y);
	DDX_Control(pDX, IDC_EDIT_H, m_Edit_H);
	DDX_Control(pDX, IDC_EDIT_W, m_Edit_W);
	DDX_Control(pDX, IDC_EDIT_ANGLE, m_Edit_Angle);

	DDX_Text(pDX, IDC_EDIT_X, m_str_Edit_X);
	DDX_Text(pDX, IDC_EDIT_Y, m_str_Edit_Y);
	DDX_Text(pDX, IDC_EDIT_H, m_str_Edit_H);
	DDX_Text(pDX, IDC_EDIT_W, m_str_Edit_W);
	DDX_Text(pDX, IDC_EDIT_ANGLE, m_str_Edit_Angle);

	DDX_Control(pDX, IDC_MFCCOLORBUTTON_FILLCOLOR, m_ColorButton_FillColor);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON_FILLCOLOR, m_COLREF_ColorButton_FillColor);
	DDX_Control(pDX, IDC_COMBOBOX_FILL_STYLE, m_Combo_FillStyle);

	DDX_Control(pDX, IDC_MFCCOLORBUTTON_EDGE_COLOR, m_ColorButton_EdgeColor);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON_EDGE_COLOR, m_COLREF_ColorButton_EdgeColor);
	DDX_Control(pDX, IDC_COMBOBOX_EDGE_STYLE, m_Combo_EdgeType);
	DDX_Control(pDX, IDC_EDIT_EDGE_WIDTH, m_Edit_Edeg_Thickness);
	DDX_Text(pDX, IDC_EDIT_EDGE_WIDTH, m_str_Edit_Edge_Thickness);

	DDX_Control(pDX, IDC_EDIT_TEXT, m_Edit_Text);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_str_Edit_Text);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_Static_Text);
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialogEx)

	ON_CBN_SELCHANGE(IDC_COMBOBOX_FILL_STYLE, &CShapeDlg::OnCbnSelchangeComboboxFillStyle)
	ON_CBN_SELCHANGE(IDC_COMBOBOX_EDGE_STYLE, &CShapeDlg::OnCbnSelchangeComboboxEdgeStyle)
	ON_EN_CHANGE(IDC_EDIT_EDGE_THICKNESS, &CShapeDlg::OnEnChangeEditEdgeThickness)

	ON_CBN_SELCHANGE(IDC_COMBO_SHAPE_TYPE, &CShapeDlg::OnCbnSelchangeComboShapeType)
END_MESSAGE_MAP()

// CShapeDlg 消息处理程序

BOOL CShapeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//为控件们赋值
	m_Combo_Shape_Type.InsertString(0, _T("未知的"));
	m_Combo_Shape_Type.InsertString(1, _T("正方形"));
	m_Combo_Shape_Type.InsertString(2, _T("矩形"));
	m_Combo_Shape_Type.InsertString(3, _T("圆形"));
	m_Combo_Shape_Type.InsertString(4, _T("椭圆形"));
	m_Combo_Shape_Type.InsertString(5, _T("正三角形"));
	m_Combo_Shape_Type.InsertString(6, _T("文字"));
	m_Combo_Shape_Type.SetCurSel(m_int_Combo_ShapeType_Sel);

	m_Edit_X.SetWindowTextW(m_str_Edit_X);
	m_Edit_Y.SetWindowTextW(m_str_Edit_Y);
	m_Edit_W.SetWindowTextW(m_str_Edit_W);
	m_Edit_H.SetWindowTextW(m_str_Edit_H);
	m_Edit_Angle.SetWindowTextW(m_str_Edit_Angle);

	if (m_int_Combo_ShapeType_Sel == 6)
	{
		m_Static_Text.EnableWindow(TRUE);
		m_Edit_Text.ShowWindow(TRUE);

		m_ColorButton_FillColor.EnableWindow(FALSE);
		m_Combo_FillStyle.EnableWindow(FALSE);
	}
	else
	{
		m_Static_Text.EnableWindow(FALSE);
	}
	m_ColorButton_FillColor.SetColor(m_COLREF_ColorButton_FillColor);

	m_Combo_FillStyle.InsertString(0, _T("HS_HORIZONTAL"));
	m_Combo_FillStyle.InsertString(1, _T("HS_VERTICAL"));
	m_Combo_FillStyle.InsertString(2, _T("HS_FDIAGONAL"));
	m_Combo_FillStyle.InsertString(3, _T("HS_BDIAGONAL"));
	m_Combo_FillStyle.InsertString(4, _T("HS_CROSS"));
	m_Combo_FillStyle.InsertString(5, _T("HS_DIAGCROSS"));
	m_Combo_FillStyle.InsertString(6, _T("BS_SOLID"));
	m_Combo_FillStyle.InsertString(7, _T("BS_NULL"));
	m_Combo_FillStyle.SetCurSel(m_int_Combo_FillType_Sel);

	m_ColorButton_EdgeColor.SetColor(m_COLREF_ColorButton_EdgeColor);
	m_Combo_EdgeType.InsertString(0, _T("PS_SOLID"));
	m_Combo_EdgeType.InsertString(1, _T("PS_DASH"));
	m_Combo_EdgeType.InsertString(2, _T("PS_DOT"));
	m_Combo_EdgeType.InsertString(3, _T("PS_DASHDOT"));
	m_Combo_EdgeType.InsertString(4, _T("PS_DASHDOTDOT"));
	m_Combo_EdgeType.InsertString(5, _T("PS_NULL"));
	m_Combo_EdgeType.SetCurSel(m_int_Combo_EdgeType_Sel);
	m_Edit_Edeg_Thickness.SetWindowTextW(m_str_Edit_Edge_Thickness);

	if (_ttoi(m_str_Edit_Edge_Thickness) > 1)
	{
		m_Combo_EdgeType.EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CShapeDlg::GetShapeData(CShape* pShape)
{
	m_int_Combo_ShapeType_Sel = pShape->GetShapeType();
	m_str_Edit_X.Format(_T("%d"), pShape->GetShapeX());
	m_str_Edit_Y.Format(_T("%d"), pShape->GetShapeY());
	m_str_Edit_W.Format(_T("%d"), pShape->GetShapeW());
	m_str_Edit_H.Format(_T("%d"), pShape->GetShapeH());
	m_str_Edit_Angle.Format(_T("%d"), pShape->GetShapeAngle());

	if (m_int_Combo_ShapeType_Sel == 6)
	{
		//dynamic_cast<CText*>(pShape);
		CText* pShape2;
		pShape2 = (CText*)pShape;
		m_str_Edit_Text = pShape2->GetShapeText();
	}

	m_COLREF_ColorButton_FillColor = pShape->GetShapeFillColor();
	m_int_Combo_FillType_Sel = pShape->GetShapeFillType();
	m_COLREF_ColorButton_EdgeColor = pShape->GetShapeEdgeColor();
	m_int_Combo_EdgeType_Sel = pShape->GetShapeEdgeType();
	m_str_Edit_Edge_Thickness.Format(_T("%d"), pShape->GetShapeEdgeThickness());
}

void CShapeDlg::SetShapeData(CShape* pShape)
{
	pShape->SetShapeType(m_int_Combo_ShapeType_Sel);
	pShape->SetShapeX(_ttoi(m_str_Edit_X));
	pShape->SetShapeY(_ttoi(m_str_Edit_Y));
	pShape->SetShapeArea(_ttoi(m_str_Edit_W), _ttoi(m_str_Edit_H));
	pShape->SetShapeAngle(_ttoi(m_str_Edit_Angle));

	if (m_int_Combo_ShapeType_Sel == 6)
	{
		CText* pShape2;
		pShape2 = (CText*)pShape;
		pShape2->SetShapeText(m_str_Edit_Text);
	}
	pShape->SetShapeFillColor(m_ColorButton_FillColor.GetColor());
	pShape->SetShapeFillType(m_int_Combo_FillType_Sel);


	pShape->SetShapeEdgeColor(m_ColorButton_EdgeColor.GetColor());
	pShape->SetShapeEdgeType(m_int_Combo_EdgeType_Sel);
	pShape->SetShapeEdgeThickness(_ttoi(m_str_Edit_Edge_Thickness));

	//OutputDebugString(L"Dlg::Set 设置pShape指向的对象的值\n");
}

void CShapeDlg::OnCbnSelchangeComboboxFillStyle()
{
	m_int_Combo_FillType_Sel = m_Combo_FillStyle.GetCurSel();
}


void CShapeDlg::OnCbnSelchangeComboboxEdgeStyle()
{
	m_int_Combo_EdgeType_Sel = m_Combo_EdgeType.GetCurSel();
}


void CShapeDlg::OnEnChangeEditEdgeThickness()
{
	CString thickness;
	m_Edit_Edeg_Thickness.GetWindowTextW(thickness);
	int int_thickness = _ttoi(thickness);
	if (int_thickness < 2)
	{
		m_Combo_EdgeType.EnableWindow(1);
	}
	else
	{
		m_Combo_EdgeType.EnableWindow(0);
	}
}

void CShapeDlg::OnCbnSelchangeComboShapeType()
{
	m_int_Combo_ShapeType_Sel = m_Combo_Shape_Type.GetCurSel();
}
