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

bool UtilityBase::GetCollisionFlag(void)
{
    vivid::Vector2 pos = m_Dice->GetDicePosition();
    int width = m_Dice->GetDiceWidth();
    int height = m_Dice->GetDiceHeight();
    if (pos.x + (float)width > m_UtilityPosition.x
        && pos.x < m_UtilityPosition.x + (float)m_utility_width
        && pos.y + (float)height > m_UtilityPosition.y
        && pos.y < m_UtilityPosition.y + (float)m_utility_height)
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
