#pragma once
#include "pch.h"
#include "CRes.h"

class CTexture :
	public CRes
{
public:
	UINT GetWidth() { return m_bitInfo.bmWidth; };
	UINT GetHeight() { return m_bitInfo.bmHeight; };

	HDC GetDC() { return m_dc; };

	void Load(const wstring& _strFilePath);

private:
	CTexture();
	virtual ~CTexture();

	friend class CResourceManager;
private:
	HDC m_dc;
	HBITMAP m_hBitmap;
	BITMAP m_bitInfo;
};