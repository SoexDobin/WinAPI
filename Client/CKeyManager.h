#pragma once

enum class KEY_STATE
{
	TAP,	// 누른 시점
	HOLD,	// 누르고 있는
	AWAY,	// 땐 시점
	NONE,	// 눌리지 않은 상태, 이전에도 눌리지 않은 상태
};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrevPush;	// 이전 프레임에서 눌렸는지
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

