#pragma once

enum class KEY_STATE
{
	TAP,	// ���� ����
	HOLD,	// ������ �ִ�
	AWAY,	// �� ����
	NONE,	// ������ ���� ����, �������� ������ ���� ����
};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrevPush;	// ���� �����ӿ��� ���ȴ���
};

enum class KEY 
{
	LEFT,
	RIGHT,
	UP, 
	DOWN,
	
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,Z,X,C,V,B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};

class CKeyManager
{
	SINGLETON(CKeyManager);
public:
	void Init();
	void Update();

	KEY_STATE GetKeyState(KEY _eKey);

private:
	vector<tKeyInfo> m_vecKey;
};

