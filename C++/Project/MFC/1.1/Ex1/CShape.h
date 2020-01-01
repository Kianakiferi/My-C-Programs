#pragma once
//Copyright:FANS Corporation
//Author: Kiana~
//Date: 2019-12/29 1:46PM
//Description: CShape��
//Version: B0.02

#include <afxwin.h>
enum ElementType {
	NOTSET,
	SQUARE,
	RECTANGLE,
	CIRCLE,
	ELLIPSE,
	TRIANGLE,
	TEXT
};

//enum Linestyle { 
//	BS_SOLID, ��ʵ���
//	BS_NULL, �����
//	BS_HATCHED, ͼ�����
//	BS_PATTERN, �Զ���ͼ�����
//	BS_DIBPATTERN �Զ���ͼ����� }; 

//enum Fillstyle {
//	HS_HORIZONTAL, __________________
//	HS_VERTICAL, ||||||||||||||||||||
//	HS_FDIAGONAL, \\\\\\\\\\\\\
//	HS_BDIAGONAL, ////////////
//	HS_CROSS, ###########
//	HS_DIAGCROSS }; xxxxxxxxxxxxxxx

//enum Edgestyle {
//PS_SOLID, ʵ�ߡ�
// PS_DASH, ------------
// PS_DOT, �� �� �� �� �� �� ��  �� �� ��  �� ��
// PS_DASHDOT, - �� - �� - �� - �� - �� - �� 
// PS_DASHDOTDOT, - �� �� - �� �� -  �� �� -  �� ��
// PS_NULL, ���ɼ�
// PS_USERSTYLE, �û��Զ��� �ɲ��� puserstyle �� userstylecount ָ��
// 

//CShape����
class CShape : public CObject
{
public:
	virtual void Draw(CDC* pDC) = 0;
	virtual bool IsMatched(CPoint cpCursor) = 0;
	virtual void Serialize(CArchive& ar) = 0;

	//һ���Get
	virtual int GetShapeType();
	virtual int GetShapeX();
	virtual int GetShapeY();
	virtual int GetShapeAngle();
	virtual int GetShapeW();
	virtual int GetShapeH();

	virtual COLORREF GetShapeFillColor();
	virtual int GetShapeFillType();
	virtual COLORREF GetShapeEdgeColor();
	virtual int GetShapeEdgeType();
	virtual int GetShapeEdgeThickness();

	//һ���Set
	virtual void SetShapeType(int m_NewType);
	virtual void SetShapeX(int coorX);
	virtual void SetShapeY(int coorY);
	virtual void SetShapeArea(int shapeW, int shapeH);
	virtual void SetShapeAngle(int shapeA);

	virtual void SetShapeFillColor(COLORREF colorFill);
	virtual void SetShapeFillType(int fillType);
	virtual void SetShapeEdgeColor(COLORREF edgeColor);
	virtual void SetShapeEdgeType(int edgeType);
	virtual void SetShapeEdgeThickness(int edgeThickness);
protected:
	ElementType shapeType = NOTSET;
	double coordinateX = 0;
	double coordinateY = 0;
	double shapeWidth;
	double shapeHeight;
	int shapeAngle = 0;

	COLORREF fillColor;
	int fillType;
	COLORREF edgeColor;
	int edgeType;
	int edgeThickness;
};

//��������
class CSquare : public CShape
{

public:
	CSquare();
	CSquare(int coordinateX, int coordinateY, int shapeWidth);
	//~CSquare();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CSquare)

	//���������Լ���SetShapeArea
	void SetShapeArea(int shapeW, int shapeH);
};

//������
class  CRectangle : public CShape
{
public:
	CRectangle();
	CRectangle(int coordinateX, int coordinateY, int  shapeWidth, int  shapeHeight);
	//~CRectangle();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CRectangle)
};

//Բ����
class CCircle : public CShape
{
public:
	CCircle();
	CCircle(int coordinateX, int coordinateY, int  radius);
	//~CCircle();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CCircle)

private:
	int radius;
};

//��Բ����
class CEllipse : public CShape
{
public:
	CEllipse();
	CEllipse(int coordinateX, int coordinateY, int shapeWidth, int shapeHeight);
	//~CEllipse();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CEllipse)
};

//��������
class CTriangle : public CShape
{
public:
	CTriangle();
	CTriangle(int coordinateX, int coordinateY, double shapeWidth, double shapeHeight);
	//~CTriangle();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CTriangle)
};

//������
class CText : public CShape
{
public:
	CText();
	CText(int coordinateX, int coordinateY, int angle, CString strtext, int textSize);
	//~CText();

	void Draw(CDC* pDC);
	bool IsMatched(CPoint cpCursor);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CText)

	CString GetShapeText();
	void SetShapeText(CString t_strText);
private:
	CString strtext;
	CString fontname;
	int textSize;
};
