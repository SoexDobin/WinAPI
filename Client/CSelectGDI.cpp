#include "pch.h"
#include "CSelectGDI.h"

#include "CCore.h"

CSelectGDI::CSelectGDI(HDC _dc, PEN_TYPE _type)
	: m_hdc(_dc)
	, m_hDefaultPen(nullptr)
	, m_hDefaultBrush(nullptr)
{
	HPEN hPen = CCore::GetInstance()->GetPEN(_type);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);
}

CSelectGDI::CSelectGDI(HDC _dc, BRUSH_TYPE _type)
	: m_hdc(_dc)
	, m_hDefaultPen(nullptr)
	, m_hDefaultBrush(nullptr)
{
	HBRUSH hBrush = CCore::GetInstance()->GetBrush(_type);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush);
}

CSelectGDI::~CSelectGDI()
{
	if (m_hDefaultPen != nullptr)
		SelectObject(m_hdc, m_hDefaultPen);
	if (m_hDefaultBrush != nullptr)
		SelectObject(m_hdc, m_hDefaultBrush);
}
