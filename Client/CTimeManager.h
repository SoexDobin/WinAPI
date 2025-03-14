#pragma once

// 프레임 당 시간값(delta time)이 필요함
class CTimeManager
{
	SINGLETON(CTimeManager);
public:
	void Init();
	void Update();
	void Render();

	double GetDT() { return m_dDT; }
	double GetfDT() { return static_cast<double>(m_dDT); }

private:
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llFrequency;

	double m_dDT;		// 프레임 사이의 시간 값
	double m_dAcc;		// 1초 체크를 위한 누적 시간
	UINT m_iCallCount;	// 함수 호출 횟수 체크
	UINT m_iFps;		// 초당 호출 횟수
};

