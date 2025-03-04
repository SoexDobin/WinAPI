#pragma once
#include "pch.h"

class CRes
{
public:
	CRes();
	virtual ~CRes();

	const wstring& GetKey() { return m_strKey; }
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }

private:
	wstring m_strKey;
	wstring m_strRelativePath;
};

