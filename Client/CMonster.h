#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{
public:
    CMonster();
    virtual ~CMonster();

    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    float GetMaxDistance() { return m_fMaxDistance; }
    void SetMaxDistance(float _f) { m_fMaxDistance = _f; }
    Vec2 GetCenterPos() { return m_vCenterPos; }
    void SetCenterPos(Vec2 _v) { m_vCenterPos = _v; }

    virtual void Update();
    virtual void Render(HDC _dc);

private:
    float m_fSpeed;
    float m_fMaxDistance;
    Vec2 m_vCenterPos;
    int m_iDir;
};

