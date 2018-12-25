#pragma once
#include <Windows.h>

//inline �Լ�ȣ�� ����� ����.

inline POINT PointMake(int x, int y)
{
	POINT pt = { x,y };
	return pt;
}

inline void lineMake(HDC hdc, int x1, int y1, int x2, int y2, int cWidth, COLORREF color, int iStyle)
{
	HPEN hPen, hOldPen;
	hPen = CreatePen(iStyle, cWidth, color);
	hOldPen = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);

	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
}

inline RECT RectMake(int x, int y, int width, int height)		// ������ ũ�⸦ �˰������� ����.
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)	// �߽��� �˰������� ����.
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };
	return rc;
}

inline RECT RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

inline void DrawObject(HDC hdc, const RECT& rc, int size, const COLORREF penColor, const COLORREF brColor, const OBJ_TYPE nType, const int ropCode = R2_XORPEN)
{
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;

	//Restoperation : �̹������� �̹����� ������ ��� ó���ϰڴ°�..
	//SetROP2(hdc, ropCode);

	hPen = CreatePen(PS_SOLID, size, penColor);
	hOldPen = (HPEN)SelectObject(hdc, hPen);

	hBrush = CreateSolidBrush(brColor);
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	switch (nType)
	{
	case ELLIPSE:
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
		break;
	case RECTANGLE:
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		break;
	}

	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);
}

//inline void DrawLine(HDC hdc, int startX, int startY, int endX, int endY, int size, const COLORREF penColor)
//{
//	HPEN hPen, hOldPen;
//	HBRUSH hBrush, hOldBrush;
//
//	hPen = CreatePen(PS_SOLID, size, penColor);
//	hOldPen = (HPEN)SelectObject(hdc, hPen);
//
//	lineMake(hdc, startX, startY, endX, endY);
//
//	SelectObject(hdc, hOldPen);
//
//	DeleteObject(hPen);
//}


inline void DrawObject(HDC hdc, const RECT& rc, int size, const COLORREF color, const OBJ_TYPE nType, const int ropCode = R2_XORPEN)
{
	DrawObject(hdc, rc, size, color, color, nType, ropCode);
}

inline void TextOutPutInt(HDC hdc, int _x, int _y, int _outPutSize, int _outPutInt)
{
	HFONT hFont;
	HFONT OldFont;

	hFont = CreateFont(_outPutSize, 0, NULL, NULL, FW_HEAVY, 0, 0, 0, HANGUL_CHARSET, NULL, NULL, NULL, NULL, TEXT("����ü"));
	OldFont = (HFONT)SelectObject(hdc, hFont);

	TCHAR textOut[100] = { 0, };
	_stprintf_s(textOut, sizeof(textOut), TEXT("%d"), _outPutInt);
	TextOut(hdc, _x, _y, TEXT(textOut), _tcslen(TEXT(textOut)));
	
	SelectObject(hdc, OldFont);
	DeleteObject(hFont);
}