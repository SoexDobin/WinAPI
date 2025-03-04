#pragma once

#define SINGLETON(type) public: \
							static type* GetInstance() \
							{ \
								static type mgr; \
								return &mgr; \
							} \
						private: \
							type(); \
							~type(); \

#define fDT CTimeManager::GetInstance()->GetfDT()
#define DT CTimeManager::GetInstance()->GetDT()
#define KEY_CHECK(key, state) CKeyManager::GetInstance()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)


enum class GROUP_TYPE
{
	DEFAULT,

	PLAYER,

	MISSILE,

	MONSTER,

	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,

	START,

	STAGE01,

	STAGE02,

	END,
};