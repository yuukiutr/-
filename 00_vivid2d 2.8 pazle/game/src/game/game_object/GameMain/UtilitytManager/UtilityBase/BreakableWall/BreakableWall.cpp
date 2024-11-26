#include "BreakableWall.h"
#include "../../../dice/dice.h"

void BreakableWall::Update(void)
{
	
}

void BreakableWall::Draw(void)
{
	vivid::DrawTexture("data\\gamemain_utility\\blast_wall.png", m_UtilityPosition);
}

UTILITY_ID BreakableWall::GetUtilityID(void)
{
	return UTILITY_ID::BreakableWall;
}
