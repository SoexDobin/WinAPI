#pragma once

class CPathManager
{
	SINGLETON(CPathManager);
public:

	void Init(); 

	const wchar_t* GetContentPath() { return m_szContentPath; };

private:
	wchar_t m_szContentPath[255];
};

