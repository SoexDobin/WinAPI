#pragma once
class CSelectGDI
{
public:
	CSelectGDI(HDC _dc, PEN_TYPE _type);
	CSelectGDI(HDC _dc, BRUSH_TYPE _type);
	~CSelectGDI();

private:
	HDC m_hdc;
	HPEN m_hDefaultPen;
	HBRUSH m_hDefaultBrush;
};

