#include "pch.h"
#include "CPlayer.h"
#include "CCollider.h"

#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CResourceManager.h"

#include "CScene.h"

#include "CTexture.h"

#include "CMissile.h"
#include "CCurveMissile.h"
#include "CDegreeMissile.h"

CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	//Texture 로딩하기
	m_pTex = CResourceManager::GetInstance()->LoadTexture(L"Player", L"texture\\Player.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));
}

CPlayer::~CPlayer()
{

}

void CPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}


	SetPos(vPos);
}


void CPlayer::Render(HDC _dc)
{
	int iWidth = static_cast<int>(m_pTex->GetWidth());
	int iHeight = static_cast<int>(m_pTex->GetHeight());
	
	Vec2 vPos = GetPos();

	/*BitBlt(_dc
		, vPos.x - static_cast<float>(iWidth / 2)
		, vPos.y - static_cast<float>(iHeight / 2)
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, SRCCOPY);*/

	TransparentBlt(_dc
		, vPos.x - static_cast<float>(iWidth / 2)
		, vPos.y - static_cast<float>(iHeight / 2)
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0 , 255));

	ComponentRender(_dc);
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CDegreeMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDirection(true);

	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}
