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

	int m_TitleCount;		//タイトルに戻るまでの時間
	int m_ResultDiceMove;	//今回の記録
	int m_LoadDiceMove;		//ベスト記録
	bool m_NewRecordFlag;	//記録更新したか
	vivid::Vector2 m_move_count_size;
	vivid::Vector2 m_best_record_size;
	vivid::Vector2 m_new_record_size;

public:
	void Initialize(GameMain* main,StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};