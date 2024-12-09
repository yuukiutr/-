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

public:
	GameMain() = default;
	~GameMain() = default;

	void Initialize(StageSelect* target);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};
