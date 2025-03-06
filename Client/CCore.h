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
	HWND m_hWnd;			// 메인 윈도우 핸들
	POINT m_ptResolution;	// 메인 윈도우 해상도
	HDC m_hdc;				// 메인에 드로우 할 DC

	HBITMAP m_hBit;
	HDC m_memDC;

	// 자주 사용할 GDI Graphic
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];
};