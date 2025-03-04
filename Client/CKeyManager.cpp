#include "pch.h"
#include "CKeyManager.h"

#include "CCore.h"

// 1. 프레임 동기화
// 동일 프레임 내에서 같은 키에 대해, 동일한 입력 이벤트를 가져간다

// 2. 키 입력 이벤트 처리
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
	// 윈도우 포커싱 알아내기
	//HWND hMainWnd = CCore::GetInstance()->GetMainHwnd();
	HWND hWnd = GetFocus();

	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// 키가 눌려있다.
			if (GetAsyncKeyState(g_arrVKey[i]) & 0x8000) 
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에도 눌려 있었다.
					m_vecKey[i].eState = KEY_STATE::HOLD;

				}
				else
				{
					// 이전에 눌려있지 않았다.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}
			// 키가 안눌려 있다.
			else
			{
				if (m_vecKey[i].bPrevPush) 
				{
					// 이전에 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else 
				{
					// 이전에도 안눌려있었다.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	// 윈도우 포커싱 해제 상태
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

