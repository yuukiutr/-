#pragma once
#include "goal/goal.h"
#include "StageCreate/StageCreate.h"
#include "UtilitytManager/UtilitytManager.h"
#include "dice/dice.h"

class StageSelect;

class GameMain
{
private:

	StageSelect* m_Select;
	UtilityManager* m_Utility;
	Goal goal;

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
