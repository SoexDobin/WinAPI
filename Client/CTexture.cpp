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
	// LoadImage�� bmp�� �����Ѵ�. png jpeg bye..
	// ���Ϸ� ���� �ε��� �����͸� ��Ʈ������ ����
	m_hBitmap = static_cast<HBITMAP>(LoadImage(nullptr, _strFilePath.c_str()
				, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));
	// ��Ʈ�ʰ� ������ DC
	m_dc = CreateCompatibleDC(CCore::GetInstance()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(m_dc, m_hBitmap));
	DeleteObject(hPrevBit);
	 
	// ��Ʈ�� ����
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitInfo);

	assert(m_hBitmap);
}
