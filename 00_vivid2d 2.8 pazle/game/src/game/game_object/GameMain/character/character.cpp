#include "character.h"


void Character::Initialize(void)
{
	m_CharacterVelocity = { 0.0f,0.0f };
	m_CharacterDirection = { 1.0f,1.0f };
	m_CharacterState = STATE_ID::OTHER;
	m_AnimChangeTimer = 0;
	m_AnimRectPoint = 0;
}

void Character::Update(void)
{

}

void Character::Draw(void)
{
	vivid::Rect rect = {};

	rect.left = m_AnimRectPoint * m_character_width;
	rect.right = rect.left + m_character_width;
	rect.top = (int)m_CharacterState * m_character_height;
	rect.bottom = rect.top + m_character_height;
	vivid::Vector2 anchor = { (float)m_character_width / 2.0f,(float)m_character_height / 2.0f };

	//vivid::DrawTexture("", m_CharacterPosition,0xffffffff,rect,anchor,m_CharacterDirection);
	//vivid::DrawText(100, std::to_string(m_Ground->LandingFlag(m_CharacterPosition, m_character_width, m_character_height)), { 700.0f,700.0f },0xffff00ff);
}

void Character::Finalize(void)
{
}

vivid::Vector2 Character::GetCharacterPosition(void)
{
	return m_CharacterPosition;
}

vivid::Vector2 Character::GetCharacterVelocity(void)
{
	return m_CharacterVelocity;
}

vivid::Vector2 Character::GetCharacterDirection(void)
{
	return m_CharacterDirection;
}

int Character::GetCharacterWidth(void)
{
	return m_character_width;
}

int Character::GetCharacterHeight(void)
{
	return m_character_height;
}


bool Character::GetLoseFlag(void)
{
	return false;
}

bool Character::GetGoalFlag(void)
{
	return false;
}

void Character::CHARACTER_DEBUG_DRAW_DATA(void)
{

#ifdef VIVID_DEBUG

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPAD3))
	{
		vivid::DrawText(30, "XP:" + std::to_string(m_CharacterPosition.x), { 0.0f,0.0f },0xff00ff00);
		vivid::DrawText(30, "YP:" + std::to_string(m_CharacterPosition.y), { 0.0f,30.0f },0xff00ff00);
		vivid::DrawText(30, "XV:" + std::to_string(m_CharacterVelocity.x), { 0.0f,60.0f },0xff00ff00);
		vivid::DrawText(30, "YV:" + std::to_string(m_CharacterVelocity.y), { 0.0f,90.0f },0xff00ff00);
		vivid::DrawText(30, "DR:" + std::to_string(m_CharacterDirection.x), { 0.0f,120.0f },0xff00ff00);
		vivid::DrawText(30, "AT:" + std::to_string(m_AnimChangeTimer), { 0.0f,150.0f },0xff00ff00);
		vivid::DrawText(30, "AR:" + std::to_string(m_AnimRectPoint), { 0.0f,180.0f },0xff00ff00);
	}
#endif //VIVID_DEBUG

}
