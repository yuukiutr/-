#pragma once
#include "vivid.h"
#include "../StageSelect/Stage_id.h"

class StageSelect;
class GameMain;

class Result
{
private:
	StageSelect* m_Select;
	GameMain* m_Main;

public:
	void Initialize(GameMain* main,StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};