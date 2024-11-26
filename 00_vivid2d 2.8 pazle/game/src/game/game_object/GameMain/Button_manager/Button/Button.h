#pragma once
#include "vivid.h"

class Character;
class Dice;

class Button
{
protected:
	vivid::Vector2 m_Button_Position;
	vivid::Vector2 m_Pushed_Button_Position;
	const int m_width;
	const int m_height;
	vivid::Vector2 m_rect;
	Dice* m_Dice;
	const float m_max_button_timer;
	float m_Button_Timer;
	bool m_ButtonOnFlag;
	bool m_OnCharacterFlag;


public:
	void Initialize(Dice* dice, vivid::Vector2 pos);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};
