#include "pch.h"
#include "CCurveMissile.h"
#include "CTimeManager.h"
#include "cmath"

CCurveMissile::CCurveMissile()
	: m_curveWidth(100.f)
	, m_curveFrequency(10.f)
	, m_timeElapsed(0.0f)
{
}

CCurveMissile::~CCurveMissile()
{
}

void CCurveMissile::Update()
{	
	if (m_startPos.x == 0 && m_startPos.y == 0) 
	{
		m_startPos = GetPos();
	}

	Vec2 vPos = GetPos();
	m_timeElapsed += fDT;

	vPos.y += 200.f * GetDirection() * fDT;
	vPos.x = m_startPos.x + m_curveWidth * sin(m_timeElapsed * m_curveFrequency);

	SetPos(vPos);
}
