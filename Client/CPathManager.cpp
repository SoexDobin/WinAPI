#include "pch.h"
#include "CPathManager.h"

#include "CCore.h"

CPathManager::CPathManager()
	: m_szContentPath{}
{

}

CPathManager::~CPathManager()
{

}

void CPathManager::Init()
{
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = wcslen(m_szContentPath);

	// 상위 폴더로
	for (int i = iLen - 1; 0 <= i; --i) 
	{
		if (m_szContentPath[i] == '\\')
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}
	// path + bin\content
	wcscat_s(m_szContentPath, L"\\bin\\content\\");

	SetWindowText(CCore::GetInstance()->GetMainHwnd(), m_szContentPath);
}
