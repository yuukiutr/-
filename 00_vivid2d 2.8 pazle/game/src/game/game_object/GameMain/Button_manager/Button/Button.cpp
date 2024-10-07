#include "Button.h"
#include "../../character/character.h"

const int m_width = 96;
const int m_height = 72;
const float m_max_button_timer = 5.0f;

void Button::Initialize(Character* character, vivid::Vector2 pos)
{
	m_Character = character;

	m_Button_Position = pos;
	m_Button_Timer = m_max_button_timer;
	bool m_ButtonOnFlag = false;
	bool m_OnCharacterFlag = false;
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
