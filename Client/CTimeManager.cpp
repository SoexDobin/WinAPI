#include "pch.h"
#include "CTimeManager.h"

#include "CCore.h"

CTimeManager::CTimeManager() :
	m_llPrevCount{},
	m_llCurCount{},
	m_llFrequency{},
	m_dDT(0.),
	m_dAcc(0.),
	m_iCallCount(0),
	m_iFps(0)
{

};

CTimeManager::~CTimeManager()
{

};

void CTimeManager::Init()
{
	QueryPerformanceCounter(&m_llPrevCount);		// 현재 카운트
	QueryPerformanceFrequency(&m_llFrequency);	// 초당 카운트 횟수 
};

void CTimeManager::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// 이전 프레임의 카운팅과, 현재 프레임 카운팅 값의 차이를 구한다.
	m_dDT = static_cast<double>(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) 
			/ static_cast<double>(m_llFrequency.QuadPart);
	
	// 이전 카운트 값을 현재값으로 갱신(다음번에 계산을 위해서)
	m_llPrevCount = m_llCurCount;
}
void CTimeManager::Render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.)
	{
		m_iFps = m_iCallCount;

		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, Delta Time : %f", m_iFps, m_dDT);
		SetWindowText(CCore::GetInstance()->GetMainHwnd(), szBuffer);
	}
};
