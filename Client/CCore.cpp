#include "pch.h"
#include "CCore.h"

#include "CPathManager.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CObject.h"

CCore::CCore() : m_hWnd(0), m_ptResolution({}), m_hdc(0), m_hBit(0), m_memDC(0)
	, m_arrBrush{}, m_arrPen{}
{

}

CCore::~CCore() 
{
	ReleaseDC(m_hWnd, m_hdc);
	DeleteObject(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int CCore::Init(HWND hWnd, POINT ptResolution)
{
	m_hWnd = hWnd;
	m_ptResolution = ptResolution;

	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hdc = GetDC(m_hWnd);

	// 이중 버퍼링 용도로 비트맵과 DC를 만듬
	m_hBit = CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hdc);

	HBITMAP holdBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(holdBit);

	// 자주 사용할 팬 및 브러쉬 생성
	CreateBrushPen();

	// 매니저 초기화
	CPathManager::GetInstance()->Init();
	CTimeManager::GetInstance()->Init();
	CKeyManager::GetInstance()->Init();
	CSceneManager::GetInstance()->Init();

	return S_OK;
}

void CCore::Progress()
{
	//Manager Update
	CTimeManager::GetInstance()->Update();
	CKeyManager::GetInstance()->Update();
	CSceneManager::GetInstance()->Update();

	// Rendering
	// 화면 Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneManager::GetInstance()->Render(m_memDC);

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	//CTimeManager::GetInstance()->Render();
}

void CCore::CreateBrushPen()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}