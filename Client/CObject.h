#pragma once

class CCollider;

class CObject
{
public:
	CObject();
	virtual ~CObject();

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	void CreateCollider();

	virtual void Update() = 0;
	virtual void LateUpdate() final;
	virtual void Render(HDC _dc) = 0;

private:
	Vec2 m_vPos;
	Vec2 m_vScale;

	CCollider* m_pCollider;
};

