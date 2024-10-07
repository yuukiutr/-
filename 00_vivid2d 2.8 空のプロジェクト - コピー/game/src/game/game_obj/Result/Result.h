#pragma once
#include "vivid.h"
#include "../StageSelect/Stage_id.h"

class StageSelect;
class GameMain;

class Result
{
private:
	int m_Frame;
	int m_Second;
	int m_Minute;
	int m_Hours;
	int m_ColorChangeTimer;
	int m_ResetCount;
	int m_GameOverCount;
	unsigned int m_Color;

	struct TARGETTIME
	{
		std::string TargetString;
		int TargetTime;
	};

	bool m_TimeWithinFlag;
	bool m_ColorChangeFlag;
	StageSelect* m_Select;
	GameMain* m_Main;

public:
	void Initialize(GameMain* main, StageSelect* target);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};