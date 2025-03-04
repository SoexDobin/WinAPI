#include "pch.h"
#include "CKeyManager.h"

#include "CCore.h"

// 1. ������ ����ȭ
// ���� ������ ������ ���� Ű�� ����, ������ �Է� �̺�Ʈ�� ��������

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold, away, 

int g_arrVKey[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','Z','X','C','V','B',

	VK_MENU, //alt
	VK_CONTROL, //ctrl
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN, //enter
	VK_ESCAPE, //esc
};

CKeyManager::CKeyManager()
{

}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i) 
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false});
	}
	
	m_vecKey[(int)KEY::LEFT].eState;
}

void CKeyManager::Update()
{
	// ������ ��Ŀ�� �˾Ƴ���
	//HWND hMainWnd = CCore::GetInstance()->GetMainHwnd();
	HWND hWnd = GetFocus();

	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// Ű�� �����ִ�.
			if (GetAsyncKeyState(g_arrVKey[i]) & 0x8000) 
			{
				if (m_vecKey[i].bPrevPush)
				{
					// �������� ���� �־���.
					m_vecKey[i].eState = KEY_STATE::HOLD;

				}
				else
				{
					// ������ �������� �ʾҴ�.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}
			// Ű�� �ȴ��� �ִ�.
			else
			{
				if (m_vecKey[i].bPrevPush) 
				{
					// ������ �����־���.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else 
				{
					// �������� �ȴ����־���.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	// ������ ��Ŀ�� ���� ����
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::TAP == m_vecKey[i].eState 
				|| KEY_STATE::HOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}

KEY_STATE CKeyManager::GetKeyState(KEY _eKey)
{
	return m_vecKey[(int)_eKey].eState;
}

