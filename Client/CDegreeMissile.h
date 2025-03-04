#pragma once
#include "CMissile.h"

class CDegreeMissile : public CMissile
{
public:
	CDegreeMissile();
	virtual ~CDegreeMissile();

	float GetTheta() { return m_fTheta; }
	void SetTheta(float _fTheta) { m_fTheta = _fTheta; }

	virtual void SetDirection(float _fTheta)
	{

	};
	
	virtual void Update();
	virtual void Render(HDC _dc);

private:
	float m_fTheta;
	Vec2 m_vDir;
};

