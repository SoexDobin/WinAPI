#pragma once
#include "define.h"

class CCore 
{
	SINGLETON(CCore);
public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

private:
	void CreateBrushPen();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hdc; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _type) { return m_arrBrush[(UINT)_type]; }
	HPEN GetPEN(PEN_TYPE _type) { return m_arrPen[(UINT)_type]; }

private:
	HWND m_hWnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hdc;				// ���ο� ��ο� �� DC

	HBITMAP m_hBit;
	HDC m_memDC;

	// ���� ����� GDI Graphic
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];
};