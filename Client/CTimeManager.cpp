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
	QueryPerformanceCounter(&m_llPrevCount);		// ���� ī��Ʈ
	QueryPerformanceFrequency(&m_llFrequency);	// �ʴ� ī��Ʈ Ƚ�� 
};

void CTimeManager::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�.
	m_dDT = static_cast<double>(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) 
			/ static_cast<double>(m_llFrequency.QuadPart);
	
	// ���� ī��Ʈ ���� ���簪���� ����(�������� ����� ���ؼ�)
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
