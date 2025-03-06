#pragma once

class CObject;

class CCollider
{
public:
	CCollider();
	virtual ~CCollider();


private:
	CObject* m_pOwner;
	Vec2 m_vOffsetPos;


public:
	void LateUpdate();
	friend class CObject;
};

