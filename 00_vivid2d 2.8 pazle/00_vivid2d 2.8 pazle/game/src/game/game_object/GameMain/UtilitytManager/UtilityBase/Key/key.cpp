#include "key.h"
#include "../../../dice/dice.h"
#include "../../UtilitytManager.h"

void Key::Initialize(vivid::Vector2 pos)
{
	m_UtilityPosition = pos;
}

void Key::Update(void)
{
}

void Key::Draw(void)
{
	vivid::DrawTexture("data\\gamemain_utility\\key.png", m_UtilityPosition);
}

void Key::Finalize(void)
{
}

UTILITY_ID Key::GetUtilityID(void)
{
	return UTILITY_ID::KEY;
}
