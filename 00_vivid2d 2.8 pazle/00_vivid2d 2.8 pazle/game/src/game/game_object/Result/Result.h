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

	int m_TitleCount;		//�^�C�g���ɖ߂�܂ł̎���
	int m_ResultDiceMove;	//����̋L�^
	int m_LoadDiceMove;		//�x�X�g�L�^
	bool m_NewRecordFlag;	//�L�^�X�V������
	vivid::Vector2 m_move_count_size;
	vivid::Vector2 m_best_record_size;
	vivid::Vector2 m_new_record_size;

public:
	void Initialize(GameMain* main,StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};