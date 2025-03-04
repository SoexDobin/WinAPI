#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
public:
	void Init();

	CScene* GetCurScene() { return m_curScene; }

	void Update();
	void Render(HDC _dc);


private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END];
	CScene* m_curScene = nullptr;

};

