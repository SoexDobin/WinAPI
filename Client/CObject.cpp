#include "pch.h"
#include "CObject.h"

#include "CCollider.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

CObject::CObject() 
	: m_vPos(Vec2(0, 0))
	, m_vScale(Vec2(0, 0))
	, m_pCollider(nullptr)
{

}

CObject::~CObject()
{
	if (m_pCollider != nullptr)
	{
		delete m_pCollider;
	}
}

void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}

void CObject::LateUpdate()
{
	if (m_pCollider)
		m_pCollider->LateUpdate();
}

void CObject::Render(HDC _dc)
{
	Rectangle(_dc
		, static_cast<int>(m_vPos.x - m_vPos.x / 2.f)
		, static_cast<int>(m_vPos.y - m_vPos.y / 2.f)
		, static_cast<int>(m_vPos.x + m_vScale.x / 2.f)
		, static_cast<int>(m_vPos.y + m_vScale.y / 2.f)
	);

	ComponentRender(_dc);
}

void CObject::ComponentRender(HDC _dc)
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->Render(_dc);
	}
}
