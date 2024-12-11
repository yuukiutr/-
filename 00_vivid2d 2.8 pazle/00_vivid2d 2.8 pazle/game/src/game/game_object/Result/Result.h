#pragma once
#include "vivid.h"
#include "../StageSelect/Stage_id.h"
#include "../GameMain/dice/dice.h"


class StageSelect;
class GameMain;
class Dice;

class Result
{
private:
	StageSelect* m_Select;
	GameMain* m_Main;

	int m_ResultDiceMove;
	int m_LoadDiceMove;

public:
	void Initialize(GameMain* main,StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};