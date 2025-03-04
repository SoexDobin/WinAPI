#include "pch.h"
#include "CMonster.h"

#include "CTimeManager.h"

CMonster::CMonster()
	: m_fSpeed(100.f)
	, m_fMaxDistance(50.f)
	, m_vCenterPos(Vec2(0.f, 0.f))
	, m_iDir(1)
{
}

CMonster::~CMonster()
{
}

void CMonster::Update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += m_fSpeed * m_iDir * fDT;

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	if (fDist > 0.f) 
	{
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}

void CMonster::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc,
		static_cast<int>(vPos.x - vScale.x / 2.f),
		static_cast<int>(vPos.y - vScale.y / 2.f),
		static_cast<int>(vPos.x + vScale.x / 2.f),
		static_cast<int>(vPos.y + vScale.y / 2.f)
	);
}
