#include "key.h"
#include "../../../dice/dice.h"


void Key::Initialize(vivid::Vector2 pos)
{
	m_UtilityPosition = pos;

	m_KeyCount = 0;
	m_MaxKey = 3;
	m_KeyClearFlag = false;
}

void Key::Update(void)
{
	if (m_MaxKey <= m_KeyCount)
		m_KeyClearFlag = true;
}

void Key::Draw(void)
{
	vivid::DrawTexture("data\\gamemain_utility\\key.png", m_UtilityPosition);
}

void Key::Finalize(void)
{
}

bool Key::GetKeyClearFlag(void)
{
	return m_KeyClearFlag;
}

UTILITY_ID Key::GetUtilityID(void)
{
	return UTILITY_ID::KEY;
}
