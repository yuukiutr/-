#include "Button.h"

const int m_width = 96;
const int m_height = 72;
const float m_max_button_timer = 5.0f;

void Button::Initialize(Dice* dice,vivid::Vector2 pos)
{
	m_Dice = dice;

	m_Button_Position = pos;
	m_Button_Timer = m_max_button_timer;
	
}

void Button::Update(void)
{

}

void Button::Draw(void)
{
}

void Button::Finalize(void)
{
}
