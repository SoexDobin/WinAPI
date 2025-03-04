#pragma once
#include "pch.h"
#include "CRes.h"

class CTexture :
	public CRes
{
public:
	CTexture();
	virtual ~CTexture();

	void Load(const wstring& _strFilePath);

private:
	HDC m_dc;
	HBITMAP m_hBitmap;
};