#include "pch.h"
#include "CTexture.h"


CTexture::CTexture()
	: m_dc(0)
	, m_hBitmap(0)
{

}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBitmap);
}

void CTexture::Load(const wstring& _strFilePath)
{
	//LoadImage는 bmp만 지원한다. png jpeg bye..
	m_hBitmap = static_cast<HBITMAP>(LoadImage(nullptr, _strFilePath.c_str()
				, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));
	int i = 0;
	assert(m_hBitmap);
}
