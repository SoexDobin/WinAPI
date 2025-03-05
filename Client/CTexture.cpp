#include "pch.h"
#include "CTexture.h"

#include "CCore.h"

CTexture::CTexture()
	: m_dc(0)
	, m_hBitmap(0)
	, m_bitInfo{}
{
	
}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBitmap);
}

void CTexture::Load(const wstring& _strFilePath)
{
	// LoadImage는 bmp만 지원한다. png jpeg bye..
	// 파일로 부터 로딩한 데이터를 비트맵으로 생성
	m_hBitmap = static_cast<HBITMAP>(LoadImage(nullptr, _strFilePath.c_str()
				, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));
	// 비트맵과 연결할 DC
	m_dc = CreateCompatibleDC(CCore::GetInstance()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(m_dc, m_hBitmap));
	DeleteObject(hPrevBit);
	 
	// 비트맵 정보
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitInfo);

	assert(m_hBitmap);
}
