#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

CMissile::CMissile()
	: m_fDir(1.f)
{
	CreateCollider();
}

CMissile::~CMissile()
{
}

void CMissile::Update()
{
	Vec2 vPos = GetPos();

	vPos.y += 400.f * m_fDir * fDT;

	SetPos(vPos);
}

void CMissile::Render(HDC _dc)
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
