#pragma once

class CObject;

class CCollider
{
public:
	CCollider();
	virtual ~CCollider();

	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 SetOffsetPos() { return m_vOffsetPos; }
	Vec2 SetScale() { return m_vScale; }

private:
	CObject* m_pOwner;
	Vec2 m_vOffsetPos;
	Vec2 m_vFinalPos;
	Vec2 m_vScale;

public:
	void LateUpdate();
	void Render(HDC _dc);

	friend class CObject;
};

