//Copyright:FANS Corporation
//Author: Kiana~
//Date: 2019-12/29 1:46PM
//Description: CShape���ʵ��
//Version: B0.02

#include "pch.h"
#include "CShape.h"
#include <math.h>

const int DEFAULT_WIDTH = 10;
const int DEFAULT_HEIGHT = 5;
const double PI = 3.14159265358979;

//CShape����

//Get����
int CShape::GetShapeType()
{
	return shapeType;
}
int CShape::GetShapeX()
{
	if (coordinateX < 65535)
	{
		return int(coordinateX);
	}
	else
	{
		return 0;
	}
}
int CShape::GetShapeY()
{
	if (coordinateX < 65535)
	{
		return int(coordinateY);
	}
	else
	{
		return 0;
	}
}
int CShape::GetShapeW()
{
	if (shapeWidth < 65535)
	{
		return int(shapeWidth);
	}
	else
	{
		return 0;
	}

}
int CShape::GetShapeH()
{
	if (shapeHeight < 65535)
	{
		return int(shapeHeight);
	}
	else
	{
		return 0;
	}
}
int CShape::GetShapeAngle()
{
	return shapeAngle;
}

COLORREF CShape::GetShapeFillColor()
{
	return fillColor;
}
int CShape::GetShapeFillType()
{
	return fillType;
}
COLORREF CShape::GetShapeEdgeColor()
{
	return edgeColor;
}
int CShape::GetShapeEdgeType()
{
	return edgeType;
}
int CShape::GetShapeEdgeThickness()
{
	return edgeThickness;
}

//Set����

void CShape::SetShapeType(int m_NewType)
{
	this->shapeType = ElementType(m_NewType);
	/*
	switch (m_NewType)
	{
	case 0:
		{
			break;
		}
	case 1:
	{
		(CSquare) *this;
		break
	}
	default:
		break;
	}
	*/
}
void CShape::SetShapeX(int coorX)
{
	this->coordinateX = coorX;
}
void CShape::SetShapeY(int coorY)
{
	this->coordinateY = coorY;
}
void CShape::SetShapeArea(int shapeW, int shapeH)
{
	this->shapeWidth = shapeW;
	this->shapeHeight = shapeH;
	OutputDebugString(L"����ShapeW\n");
}
void CShape::SetShapeAngle(int shapeA)
{
	this->shapeAngle = shapeA;
}

void CShape::SetShapeFillColor(COLORREF colorFill)
{
	this->fillColor = colorFill;
}
void CShape::SetShapeFillType(int t_fillType)
{
	this->fillType = t_fillType;
}
void CShape::SetShapeEdgeColor(COLORREF t_edgeColor)
{
	this->edgeColor = t_edgeColor;
}
void CShape::SetShapeEdgeType(int t_edgeType)
{
	this->edgeType = t_edgeType;
}
void CShape::SetShapeEdgeThickness(int t_edgeThickness)
{
	this->edgeThickness = t_edgeThickness;
}

//��������
CSquare::CSquare()
{
	shapeType = SQUARE;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	shapeWidth = DEFAULT_WIDTH;
	shapeHeight = DEFAULT_WIDTH;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID + 6;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CSquare�Ķ���\n");
}

CSquare::CSquare(int coordinateX, int coordinateY, int m_width)
{
	shapeType = SQUARE;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	shapeAngle = 0;
	this->shapeWidth = m_width;
	this->shapeHeight = m_width;

	fillColor = RGB(244, 143, 177);
	fillType = BS_SOLID + 6;

	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CSquare�Ķ���\n");
}

void CSquare::Draw(CDC* pDC)
{
	this->shapeHeight = shapeWidth;
	//������
	CBrush brush, * pOldBrush;
	if (fillType >= HS_HORIZONTAL && fillType <= HS_DIAGCROSS)
	{
		brush.CreateHatchBrush(fillType, fillColor);
	}
	if (fillType == 6)
	{
		brush.CreateSolidBrush(fillColor);
	}
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//���߿�
	CPen pen, * pOldPen;
	pen.CreatePen(edgeType, edgeThickness, edgeColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//C4244 ����
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		pDC->Rectangle(int(coordinateX - (shapeWidth * 0.5)),
			int(coordinateY - (shapeHeight * 0.5)),
			int(coordinateX + (shapeWidth * 0.5)),
			int(coordinateY + (shapeHeight * 0.5)));
	}

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

	//OutputDebugString(L"CSquare::Draw ����\n");
}

bool CSquare::IsMatched(CPoint cpCursor)
{
	//��CRect�� �ж��Ƿ���������
	double double_shapeArea = shapeWidth * 0.5;
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		CRect ObjArea(int(coordinateX - double_shapeArea),
			int(coordinateY - double_shapeArea),
			int(coordinateX + double_shapeArea),
			int(coordinateY + double_shapeArea));

		if (PtInRect(ObjArea, cpCursor))
		{
			//OutputDebugString(L"CSquare::IsMatched �ڷ�Χ��\n");
			return TRUE;
		}

		else
		{
			return false;
		}
	}
	return false;
}

IMPLEMENT_SERIAL(CSquare, CObject, 1)
void CSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeWidth;
		ar << shapeHeight;
		ar << shapeAngle;

		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeWidth;
		ar >> shapeHeight;
		ar >> shapeAngle;

		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}

void CSquare::SetShapeArea(int shapeW, int shapeH)
{
	if (this->shapeWidth != shapeW || this->shapeHeight == shapeH)
	{
		this->shapeWidth = shapeW;
		this->shapeHeight = shapeW;
		//OutputDebugString(L"CSquare::SetShapeArea W,H������ΪW\n");
		return;
	}
	if (this->shapeWidth == shapeW || this->shapeHeight != shapeH)
	{
		this->shapeWidth = shapeH;
		this->shapeHeight = shapeH;
		//OutputDebugString(L"CSquare::SetShapeArea W,H������ΪH\n");
		return;
	}
}

//������
CRectangle::CRectangle()
{
	shapeType = RECTANGLE;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	shapeWidth = DEFAULT_WIDTH;
	shapeHeight = DEFAULT_HEIGHT;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID + 6;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CRectangle�Ķ���\n");
}

CRectangle::CRectangle(int coordinateX, int coordinateY, int shapeWidth, int shapeHeight)
{
	shapeType = RECTANGLE;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	shapeAngle = 0;
	this->shapeWidth = shapeWidth;
	this->shapeHeight = shapeHeight;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID + 6;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CRectangle�Ķ���\n");
}

void CRectangle::Draw(CDC* pDC)
{
	//������
	CBrush brush, * pOldBrush;
	if (fillType >= HS_HORIZONTAL && fillType <= HS_DIAGCROSS)
	{
		brush.CreateHatchBrush(fillType, fillColor);
	}
	else if (fillType == 6)
	{
		brush.CreateSolidBrush(fillColor);
	}
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//���߿�
	CPen pen, * pOldPen;
	pen.CreatePen(edgeType, edgeThickness, edgeColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	if (coordinateX < 65535 || coordinateY < 65535)
	{
		pDC->Rectangle(int(coordinateX - (shapeWidth * 0.5)),
			int(coordinateY - (shapeHeight * 0.5)),
			int(coordinateX + (shapeWidth * 0.5)),
			int(coordinateY + (shapeHeight * 0.5)));
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

	//OutputDebugString(L"CRectangle::Draw ����\n");
}

bool CRectangle::IsMatched(CPoint cpCursor)
{
	//������CRect���ж��Ƿ���������
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		CRect ObjArea(int(coordinateX - (shapeWidth * 0.5)),
			int(coordinateY - (shapeHeight * 0.5)),
			int(coordinateX + (shapeWidth * 0.5)),
			int(coordinateY + (shapeHeight * 0.5)));
		if (PtInRect(ObjArea, cpCursor))
		{
			//OutputDebugString(L"CSquare::IsMatched �ڷ�Χ��\n");
			return TRUE;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void CRectangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeWidth;
		ar << shapeHeight;
		ar << shapeAngle;

		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeWidth;
		ar >> shapeHeight;
		ar >> shapeAngle;

		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}
IMPLEMENT_SERIAL(CRectangle, CObject, 1)

//Բ����
CCircle::CCircle()
{
	shapeType = CIRCLE;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	radius = DEFAULT_WIDTH;
	shapeWidth = (double)radius * 2;
	shapeHeight = (double)radius * 2;	//C26451����

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID + 6;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CCircle�Ķ���\n");
}

CCircle::CCircle(int coordinateX, int coordinateY, int  radius)
{
	shapeType = RECTANGLE;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	shapeAngle = 0;
	this->radius = radius;
	shapeWidth = (double)radius * 2;
	shapeHeight = (double)radius * 2;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CCircle�Ķ���\n");
}

void CCircle::Draw(CDC* pDC)
{
	//������
	CBrush brush, * pOldBrush;
	if (fillType >= HS_HORIZONTAL && fillType <= HS_DIAGCROSS)
	{
		brush.CreateHatchBrush(fillType, fillColor);
	}
	else if (fillType == 6)
	{
		brush.CreateSolidBrush(fillColor);
	}
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//���߿�
	CPen pen, * pOldPen;
	pen.CreatePen(edgeType, edgeThickness, edgeColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	if (coordinateX < 65535 || coordinateY < 65535)
	{
		pDC->Ellipse(int(coordinateX - radius),
			int(coordinateY - radius),
			int(coordinateX + radius),
			int(coordinateY + radius));
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

	//OutputDebugString(L"CCircle::Draw ����\n");
}

bool CCircle::IsMatched(CPoint cpCursor)
{
	//����ѧ�ķ����ж��Ƿ���������
	double a = coordinateX - cpCursor.x;
	double b = coordinateY - cpCursor.y;
	double r2 = (double)radius * radius;

	if (!(a * a + b * b > r2))
	{
		//OutputDebugString(L"CCircle::IsMatched �ڷ�Χ��\n");
		return TRUE;
	}
	else
	{
		return false;
	}
}

void CCircle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeWidth;
		ar << shapeHeight;
		ar << radius;
		ar << shapeAngle;

		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeWidth;
		ar >> shapeHeight;
		ar >> radius;
		ar >> shapeAngle;

		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}
IMPLEMENT_SERIAL(CCircle, CObject, 1)

//��Բ����
CEllipse::CEllipse()
{
	shapeType = ELLIPSE;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	shapeWidth = DEFAULT_WIDTH;
	shapeHeight = DEFAULT_HEIGHT;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CEllipse�Ķ���\n");
}

CEllipse::CEllipse(int coordinateX, int coordinateY, int shapeWidth, int shapeHeight)
{
	shapeType = ELLIPSE;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	shapeAngle = 0;
	this->shapeWidth = shapeWidth;
	this->shapeHeight = shapeHeight;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CEllipse�Ķ���\n");
}

void CEllipse::Draw(CDC* pDC)
{
	//������
	CBrush brush, * pOldBrush;
	if (fillType >= HS_HORIZONTAL && fillType <= HS_DIAGCROSS)
	{
		brush.CreateHatchBrush(fillType, fillColor);
	}
	else if (fillType == 6)
	{
		brush.CreateSolidBrush(fillColor);
	}
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//���߿�
	CPen pen, * pOldPen;
	pen.CreatePen(edgeType, edgeThickness, edgeColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	if (coordinateX < 65535 || coordinateY < 65535)
	{
		pDC->Ellipse(int(coordinateX - (shapeWidth * 0.5)),
			int(coordinateY - (shapeHeight * 0.5)),
			int(coordinateX + (shapeWidth * 0.5)),
			int(coordinateY + (shapeHeight * 0.5)));
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

	//OutputDebugString(L"CEllipse::Draw ����\n");
}

bool CEllipse::IsMatched(CPoint cpCursor)
{
	//��CRgn���ж��Ƿ���������
	CRgn ObjArea;
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		ObjArea.CreateEllipticRgn(int(coordinateX - (shapeWidth * 0.5)),
			int(coordinateY - (shapeHeight * 0.5)),
			int(coordinateX + (shapeWidth * 0.5)),
			int(coordinateY + (shapeHeight * 0.5)));
		if (ObjArea.PtInRegion(cpCursor))
		{
			//OutputDebugString(L"CEllipse::IsMatched �ڷ�Χ��\n");
			return TRUE;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void CEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeWidth;
		ar << shapeHeight;
		ar << shapeAngle;

		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeWidth;
		ar >> shapeHeight;
		ar >> shapeAngle;

		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}
IMPLEMENT_SERIAL(CEllipse, CObject, 1)

//��������
CTriangle::CTriangle()
{
	shapeType = TRIANGLE;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	shapeWidth = DEFAULT_WIDTH;
	shapeHeight = DEFAULT_WIDTH * 0.866025;
	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CTriangle�Ķ���\n");
}

CTriangle::CTriangle(int coordinateX, int coordinateY, double shapeWidth, double shapeHeight)
{
	shapeType = TRIANGLE;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	shapeAngle = 0;
	this->shapeWidth = shapeWidth;
	this->shapeHeight = shapeHeight;
	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CTriangle�Ķ���\n");
}

void CTriangle::Draw(CDC* pDC)
{
	//���߿�
	CBrush brush, * pOldBrush;
	if (fillType >= HS_HORIZONTAL && fillType <= HS_DIAGCROSS)
	{
		brush.CreateHatchBrush(fillType, fillColor);
	}
	else
	{
		brush.CreateSolidBrush(fillColor);
	}
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//������
	CPen pen, * pOldPen;
	pen.CreatePen(edgeType, edgeThickness, edgeColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	CPoint mPoint[3];
	if (shapeWidth < 65535 || shapeHeight < 65535)
	{
		double offset = shapeHeight * 0.5;
		mPoint[0].x = int(coordinateX - (shapeWidth * 0.5));
		mPoint[0].y = int(coordinateY + offset);
		mPoint[1].x = int(coordinateX + (shapeWidth * 0.5));
		mPoint[1].y = int(coordinateY + offset);
		mPoint[2].x = int(coordinateX);
		mPoint[2].y = int(coordinateY - shapeHeight + offset);
	}
	pDC->Polygon(mPoint, 3);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

bool CTriangle::IsMatched(CPoint cpCursor)
{
	//
	CRgn ObjArea;
	CPoint mPoint[3];
	double offset = shapeHeight * 0.5;
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		mPoint[0].x = int (coordinateX - (shapeWidth * 0.5));
		mPoint[0].y = int (coordinateY + offset);
		mPoint[1].x = int (coordinateX + (shapeWidth * 0.5));
		mPoint[1].y = int (coordinateY + offset);
		mPoint[2].x = int (coordinateX);
		mPoint[2].y = int (coordinateY - shapeHeight + offset);
	}


	ObjArea.CreatePolygonRgn(mPoint, 3, ALTERNATE);

	if (ObjArea.PtInRegion(cpCursor))
	{
		//OutputDebugString(L"CSquare::IsMatched �ڷ�Χ��\n");
		return TRUE;
	}
	else
	{
		return false;
	}
}

void CTriangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeWidth;
		ar << shapeHeight;
		ar << shapeAngle;

		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeWidth;
		ar >> shapeHeight;
		ar >> shapeAngle;

		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}
IMPLEMENT_SERIAL(CTriangle, CObject, 1)

//������
CText::CText()
{
	shapeType = TEXT;
	coordinateX = 0;
	coordinateY = 0;
	shapeAngle = 0;
	textSize = 10;
	shapeWidth = DEFAULT_WIDTH;
	shapeHeight = DEFAULT_WIDTH;
	strtext = "�ı���";
	fontname = "Microsoft YaHei UI";
	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�޲δ���CText�Ķ���\n");
}

CText::CText(int coordinateX, int coordinateY, int angle, CString strtext, int t_textSize)
{
	int textCount = strtext.GetLength();

	shapeType = TEXT;
	this->coordinateX = coordinateX;
	this->coordinateY = coordinateY;
	this->shapeWidth = (double)t_textSize * textCount * 1.25;
	this->shapeHeight = (double)t_textSize * 3;
	this->shapeAngle = angle;
	this->strtext = strtext;
	this->fontname = "Microsoft YaHei UI";
	this->textSize = t_textSize;

	fillColor = RGB(255, 255, 255);
	fillType = BS_SOLID;
	edgeColor = RGB(0, 0, 0);
	edgeType = PS_SOLID;
	edgeThickness = 2;

	//OutputDebugString(L"�вδ���CText�Ķ���\n");
}

CString CText::GetShapeText()
{
	return strtext;
}

void CText::SetShapeText(CString t_strText)
{
	this->strtext = t_strText;
}

void CText::Draw(CDC* pDC)
{
	//��������
	CFont font, * pOldFont;
	font.CreateFont(int(shapeHeight),
		textSize,
		shapeAngle * 10,
		0,
		textSize,
		0,
		0,
		0,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		fontname);
	pOldFont = (CFont*)pDC->SelectObject(&font);

	//������ɫ
	pDC->SetTextColor(edgeColor);

	if (coordinateX < 65535 || coordinateY < 65535)
	{
		pDC->TextOutW(int(coordinateX), int(coordinateY), strtext);
	}
	pDC->SelectObject(pOldFont);

	//OutputDebugString(L"CText::Draw ����\n");
}

bool CText::IsMatched(CPoint cpCursor)
{
	double AngleDEG = (shapeAngle * PI / 180);
	double sinA = sin(AngleDEG);
	double cosA = cos(AngleDEG);

	double sinH = sinA * (this->shapeHeight);
	double cosH = cosA * (this->shapeHeight);
	double sinW = sinA * (this->shapeWidth);
	double cosW = cosA * (this->shapeWidth);

	CPoint mPoint[4];
	if (coordinateX < 65535 || coordinateY < 65535)
	{
		mPoint[0].x = int(this->coordinateX);
		mPoint[0].y = int(this->coordinateY);
		mPoint[1].x = int(this->coordinateX + sinH);
		mPoint[1].y = int(this->coordinateY + cosH);
		mPoint[2].x = int(this->coordinateX + sinH + cosW);
		mPoint[2].y = int(this->coordinateY + cosH - sinW);
		mPoint[3].x = int(this->coordinateX + cosW);
		mPoint[3].y = int(this->coordinateY - sinW);
	}


	CRgn ObjArea;
	ObjArea.CreatePolygonRgn(mPoint, 4, ALTERNATE);

	if (ObjArea.PtInRegion(cpCursor))
	{
		//OutputDebugString(L"CText::IsMatched �ڷ�Χ��\n");
		return TRUE;
	}
	else
	{
		return false;
	}
}

void CText::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)shapeType;
		ar << coordinateX << coordinateY;
		ar << shapeAngle;
		ar << shapeWidth;
		ar << shapeHeight;

		ar << strtext;
		ar << fontname;
		ar << textSize;
		ar << fillColor;
		ar << fillType;
		ar << edgeColor;
		ar << edgeType;
		ar << edgeThickness;
	}
	else
	{
		WORD w;
		ar >> w;
		shapeType = (ElementType)w;
		ar >> coordinateX >> coordinateY;
		ar >> shapeAngle;
		ar >> shapeWidth;
		ar >> shapeHeight;

		ar >> strtext;
		ar >> fontname;
		ar >> textSize;
		ar >> fillColor;
		ar >> fillType;
		ar >> edgeColor;
		ar >> edgeType;
		ar >> edgeThickness;
	}
}
IMPLEMENT_SERIAL(CText, CObject, 1)