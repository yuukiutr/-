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
    bool hitflag = false;

    vivid::Vector2 vec2 = m_Dice->GetDicePosition();
    vivid::Vector2 velo = m_Dice->GetVelocity();

    int width = m_Dice->GetDiceWidth();
    int height = m_Dice->GetDiceHeight();

    if (vec2.x + (float)width > m_UtilityPosition.x + velo.x + 1.0f
        && vec2.x < m_UtilityPosition.x + (float)m_utility_width + velo.x - 1.0f
        && vec2.y + (float)height >= m_UtilityPosition.y
        && vec2.y <= m_UtilityPosition.y - (float)height / 2.0f)
    {
        hitflag = true;
    }

    if (vec2.y <= m_UtilityPosition.y + (float)m_utility_height
        && vec2.y + (float)height >= m_UtilityPosition.y + (float)m_utility_height
        && vec2.x + (float)width > m_UtilityPosition.x + 5.0f
        && vec2.x < m_UtilityPosition.x + (float)m_utility_width - 5.0f)
    {
        hitflag = true;
    }

    //‰¡
    if (vec2.x + (float)width >= m_UtilityPosition.x
        && vec2.x <= m_UtilityPosition.x + (float)m_utility_width / 3.0f
        && vec2.y + (float)height > m_UtilityPosition.y + (float)m_utility_width / 3.0f
        && vec2.y < m_UtilityPosition.y + (float)m_utility_height / 1.5f)
    {
        hitflag = true;
    }

    if (vec2.x + (float)width >= m_UtilityPosition.x + (float)m_utility_width
        && vec2.x <= m_UtilityPosition.x + (float)m_utility_width
        && vec2.y + (float)height > m_UtilityPosition.y + (float)m_utility_height / 3.0f
        && vec2.y < m_UtilityPosition.y + (float)m_utility_height / 1.5f)
    {
        hitflag = true;
    }

    return hitflag;
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
