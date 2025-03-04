#pragma once

class CObject;

class CScene
{
	
public:
	CScene();
	virtual ~CScene();

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void Update();
	void Render(HDC _dc);

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	};

private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring m_strName;

};

