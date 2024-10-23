#pragma once
#include "character/character.h"
#include "goal/goal.h"
#include "EnemyManager/EnemyManager.h"
#include "StageCreate/StageCreate.h"

class StageSelect;

class GameMain
{
private:

	StageSelect* m_Select;
	Character character;
	Goal goal;
	StageCreate m_create;

	int m_Timer;
	int m_ResetCount;
	int m_GameOverCount;

public:
	GameMain() = default;
	~GameMain() = default;

	void Initialize(StageSelect* target);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	int GetTimer(void);
	int GetResetCount(void);
	int GetGameOverCount(void);
	void GAMEMAIN_DEBUG_DRAW_DATA(void);

};
