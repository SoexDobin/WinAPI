#pragma once
#include "define.h"

class CCore 
{
	SINGLETON(CCore);
public:
	int Init(HWND hWnd, POINT ptResolution);
	void Progress();

private:
	void Update();
	void Render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hdc; }
	POINT GetResolution() { return m_ptResolution; }

private:
	HWND m_hWnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hdc;				// ���ο� ��ο� �� DC

	HBITMAP m_hBit;
	HDC m_memDC;
};