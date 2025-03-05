#include "pch.h"
#include "CResourceManager.h"

#include "CPathManager.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
{

}

CResourceManager::~CResourceManager()
{
	map<wstring, CTexture*>::iterator iter = m_mapTexture.begin();
	for (; iter != m_mapTexture.end(); iter++)
	{
		delete iter->second;
	}
}

CTexture* CResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr) 
	{
		return pTex;
	}

	wstring strFilePath = CPathManager::GetInstance()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture(); 
	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTexture.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResourceManager::FindTexture(const wstring _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTexture.find(_strKey);

	if (iter == m_mapTexture.end())
	{
		return nullptr;
	}

	return iter->second;
}
