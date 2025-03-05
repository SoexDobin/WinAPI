#include "pch.h"
#include "CScene_Start.h"

#include "CCore.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CPathManager.h"
#include "CTexture.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	CObject* pObj = new CPlayer;
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f,100.f));

	AddObject(pObj, GROUP_TYPE::DEFAULT);

	// 몬스터 생성
	CMonster* pMon = nullptr;
	int iMonsterCount = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;

	Vec2 vResolutuon = CCore::GetInstance()->GetResolution();
	float fTerm = (vResolutuon.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonsterCount - 1);

	for (int i = 0; i < iMonsterCount; i++)
	{
		pMon = new CMonster;
		pMon->SetCenterPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 50.f));
		pMon->SetPos(Vec2(pMon->GetCenterPos()));

		pMon->SetMaxDistance(fMoveDist);
		pMon->SetScale(Vec2(fObjScale, fObjScale));

		AddObject(pMon, GROUP_TYPE::DEFAULT);
	}
}

void CScene_Start::Exit()
{

}
