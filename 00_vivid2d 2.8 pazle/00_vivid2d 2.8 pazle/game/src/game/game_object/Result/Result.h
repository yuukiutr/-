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

	int m_ResultDiceMove;	//今回の記録
	int m_LoadDiceMove;		//ベスト記録
	bool m_NewRecordFlag;	//記録更新したか

public:
	void Initialize(GameMain* main,StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};