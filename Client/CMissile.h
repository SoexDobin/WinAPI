#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
public:
    CMissile();
    virtual ~CMissile();

    float GetDirection() { return m_fDir; }
    void SetDirection(bool _bUp) 
    {
        if (_bUp)
            m_fDir = -1.f;
        else
            m_fDir = 1.f;
    }

    virtual void Update();
    virtual void Render(HDC _dc);

private:
    float m_fDir;
};

