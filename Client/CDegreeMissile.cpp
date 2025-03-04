#include "pch.h"
#include "CDegreeMissile.h"
#include "CTimeManager.h"

CDegreeMissile::CDegreeMissile()
	: m_fTheta(1.5f * 3.14f / 2)
	, m_vDir(Vec2(1.f, 1.f))
{
	m_vDir.Normalize();
}

CDegreeMissile::~CDegreeMissile()
{
}

void CDegreeMissile::Update()
{
	Vec2 vPos = GetPos();

	
	float b = sinf(90.f);

	//vPos.x += 600.f * fDT * cosf(m_fTheta);
	//vPos.y += 600.f * fDT * sinf(m_fTheta) * GetDirection();

	vPos.x += 600.f * fDT * m_vDir.x;
	vPos.y += 600.f * fDT * m_vDir.y * GetDirection();

	SetPos(vPos);
}

void CDegreeMissile::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc,
		static_cast<int>(vPos.x - vScale.x / 2.f),
		static_cast<int>(vPos.y - vScale.y / 2.f),
		static_cast<int>(vPos.x + vScale.x / 2.f),
		static_cast<int>(vPos.y + vScale.y / 2.f)
	);
}
