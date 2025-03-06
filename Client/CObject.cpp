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
	if (m_pCollider != nullptr)
		m_pCollider->m_pOwner->LateUpdate();
}
