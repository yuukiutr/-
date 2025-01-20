#include "UtilityBase.h"
#include "../../dice/dice.h"
#include "../../StageCreate/StageCreate.h"


const int UtilityBase::m_utility_width = 64;
const int UtilityBase::m_utility_height = 64;
const bool UtilityBase::m_UtilityFlag = false;


void UtilityBase::Initialize(vivid::Vector2 pos)
{
    m_UtilityPosition = pos;
    m_UtilityColor = 0xffffffff;
}

void UtilityBase::Update(void)
{
    vivid::Vector2 vec2 = Dice::GetInstance().GetDicePosition();
    
}

void UtilityBase::Draw(void)
{
}

void UtilityBase::Finalize(void)
{
}

bool UtilityBase::GetCollisionFlag(void)
{
    bool hitflg = false;

    vivid::Vector2 dice_pos = m_Dice->GetInstance().GetDicePosition();
    vivid::Vector2 dice_velo = m_Dice->GetInstance().GetVelocity();

    int width = m_Dice->GetInstance().GetDiceWidth();
    int height = m_Dice->GetInstance().GetDiceHeight();

    //è„
    if (dice_pos.x <= m_UtilityPosition.x
        && dice_pos.x + width >= m_UtilityPosition.x + m_utility_width
        && dice_pos.y + dice_velo.y <= m_UtilityPosition.y
        && dice_pos.y + height + dice_velo.y >= m_UtilityPosition.y + m_utility_height)
    {
        hitflg = true;
    }
    //âE
    if (dice_pos.x + dice_velo.x <= m_UtilityPosition.x
        && dice_pos.x + width + dice_velo.x >= m_UtilityPosition.x + m_utility_width
        && dice_pos.y <= m_UtilityPosition.y
        && dice_pos.y + height >= m_UtilityPosition.y + m_utility_height)
    {
        hitflg = true;
    }
    return hitflg;
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
