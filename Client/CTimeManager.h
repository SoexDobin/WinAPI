#pragma once

// ������ �� �ð���(delta time)�� �ʿ���
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

	double m_dDT;		// ������ ������ �ð� ��
	double m_dAcc;		// 1�� üũ�� ���� ���� �ð�
	UINT m_iCallCount;	// �Լ� ȣ�� Ƚ�� üũ
	UINT m_iFps;		// �ʴ� ȣ�� Ƚ��
};

