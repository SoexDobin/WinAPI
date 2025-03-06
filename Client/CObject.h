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
	CCollider* GetCollider() { return m_pCollider; }

	virtual void Update() = 0;
	virtual void LateUpdate() final;
	virtual void Render(HDC _dc);

	void ComponentRender(HDC _dc);
private:
	Vec2 m_vPos;
	Vec2 m_vScale;

	CCollider* m_pCollider;
};

