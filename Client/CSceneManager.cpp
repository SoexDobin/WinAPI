#include "pch.h"
#include "CSceneManager.h"

#include "CScene_Start.h"

CSceneManager::CSceneManager()
	: m_curScene(nullptr)
{

};

CSceneManager::~CSceneManager()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i) 
	{
		if(m_arrScene[i] != nullptr)
			delete m_arrScene[i];
	}
};

void CSceneManager::Init()
{
	// Scene »ý¼º
	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CScene_Tool;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE01] = new CScene_Stage01;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE02] = new CScene_Stage02;

	m_curScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_curScene->Enter();
}

void CSceneManager::Update()
{
	m_curScene->Update();
}

void CSceneManager::Render(HDC _dc)
{
	m_curScene->Render(_dc);
}
