#pragma once
#include "CObject.h"

class CPlayer :
    public CObject
{
public:
    CPlayer();
    virtual ~CPlayer();

    virtual void Update();
    virtual void Render(HDC _dc);

private:
    void CreateMissile();
};

