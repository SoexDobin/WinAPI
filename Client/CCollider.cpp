#include "pch.h"
#include "CCollider.h"

#include "CObject.h"

#include "CSelectGDI.h"

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vOffsetPos{0, 0}
	, m_vFinalPos{0, 0}
	, m_vScale{0, 0}
{

}

CCollider::~CCollider()
{

}

void CCollider::LateUpdate()
{
	Vec2 vObjectPos= m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void CCollider::Render(HDC _dc)
{
	CSelectGDI pen(_dc, PEN_TYPE::GREEN);
	CSelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, static_cast<int>(m_vFinalPos.x - m_vScale.x / 2.f)
		, static_cast<int>(m_vFinalPos.y - m_vScale.y / 2.f)
		, static_cast<int>(m_vFinalPos.x + m_vScale.x / 2.f)
		, static_cast<int>(m_vFinalPos.y + m_vScale.y / 2.f)
		);
}
