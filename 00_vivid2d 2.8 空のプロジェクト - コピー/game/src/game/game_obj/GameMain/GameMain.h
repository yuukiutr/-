#pragma once

class StageSelect;

class GameMain
{
private:
	StageSelect* m_Select;

	int m_Timer;
	int m_ResetCount;
	int m_GameOverCount;

public:
	void Initialize(StageSelect* target);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void GAMEMAIN_DEBUG_DRAW_DATA(void);
};
