// CTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "Ex1.h"
#include "CShape.h"
#include "CTestDlg.h"
#include "afxdialogex.h"



// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_str_Edit1(_T(""))
{
	OutputDebugString(L"创建对话框\n");
	m_int_Combo_1_Sel = 0;
}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_EDIT2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT1, m_str_Edit1);
	DDX_Control(pDX, IDC_COMBO_1, m_Combo_1);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Edit1.SetWindowTextW(m_str_Edit1);
	m_Combo_1.AddString(_T("AAA"));
	m_Combo_1.AddString(_T("BBB"));
	m_Combo_1.AddString(_T("CCC"));
	m_Combo_1.AddString(_T("DDD"));
	m_Combo_1.AddString(_T("FFF"));
	m_Combo_1.AddString(_T("GGG"));
	m_Combo_1.AddString(_T("HHH"));

	m_Combo_1.SetCurSel(m_int_Combo_1_Sel);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
