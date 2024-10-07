#pragma once
#include "character/character.h"
#include "goal/goal.h"
#include "lose/lose.h"
#include "EnemyManager/EnemyManager.h"

class StageSelect;

class GameMain
{
private:
	StageSelect* m_Select;
	Character character;
	Goal goal;
	Lose lose;

	int m_Timer;
	int m_ResetCount;
	int m_GameOverCount;

public:
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
