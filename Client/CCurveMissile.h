#pragma once
#include "CMissile.h"
class CCurveMissile :
    public CMissile
{
public:
    CCurveMissile();
    virtual ~CCurveMissile();

    float GetCurveWidth() { return m_curveWidth; }
    void SetCurveWidth(float _width) { m_curveWidth = _width; }
    float GetCurveFrequency() { return m_curveFrequency; }
    void SetCurveFrequency(float _frequency) { m_curveFrequency = _frequency; }

    virtual void Update();

private:
    float m_curveWidth;
    float m_curveFrequency;
    float m_timeElapsed;
    Vec2 m_startPos = {0, 0};
};

