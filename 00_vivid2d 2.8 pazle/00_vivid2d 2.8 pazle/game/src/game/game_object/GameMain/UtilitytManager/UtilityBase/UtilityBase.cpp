#include "UtilityBase.h"
#include "../../dice/dice.h"
#include "../../StageCreate/StageCreate.h"


const int UtilityBase::m_utility_width = 64;
const int UtilityBase::m_utility_height = 64;
const bool UtilityBase::m_UtilityFlag = false;


void UtilityBase::Initialize(Dice* dice, vivid::Vector2 pos)
{
    m_Dice = dice;

    m_UtilityPosition = pos;
    m_UtilityColor = 0xffffffff;
}

void UtilityBase::Update(void)
{
    vivid::Vector2 vec2 = m_Dice->GetDicePosition();
    
}

void UtilityBase::Draw(void)
{
}

void UtilityBase::Finalize(void)
{
}

bool UtilityBase::GetCollisionFlag(int x, int y)
{
    if (x < 0)x = 0;
    if (x > g_map_chip_count_width)x = g_map_chip_count_width - 1;
    if (y < 0)y = 0;
    if (y > g_map_chip_count_height)y = g_map_chip_count_height - 1;
    {
        return true;
    }
    return false;
}


vivid::Vector2 UtilityBase::GetPosition(void)
{
    return m_UtilityPosition;
}



UTILITY_ID UtilityBase::GetUtilityID(void)
{
    return UTILITY_ID::BASE;
}

bool UtilityBase::GetUtilityFlag(void)
{
    return m_UtilityFlag;
}
