#include "pch.h"
#include "CPlayer.h"

#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CScene.h"

#include "CMissile.h"
#include "CCurveMissile.h"
#include "CDegreeMissile.h"

CPlayer::CPlayer()
{
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
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc,
		static_cast<int>(vPos.x - vScale.x / 2.f),
		static_cast<int>(vPos.y - vScale.y / 2.f),
		static_cast<int>(vPos.x + vScale.x / 2.f),
		static_cast<int>(vPos.y + vScale.y / 2.f)
	);
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
