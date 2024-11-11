#include "UtilityBase.h"
#include "../../dice/dice.h"

const int UtilityBase::m_utility_width = 128;
const int UtilityBase::m_utility_height = 128;


void UtilityBase::Initialize(StageCreate* stage, Dice* dice, vivid::Vector2 pos)
{
    m_Stage = stage;
    m_Dice = dice;

    m_UtilityPosition = pos;
    m_UtilityColor = 0xffffffff;
}

void UtilityBase::Update(void)
{
}

void UtilityBase::Draw(void)
{
    vivid::DrawTexture(m_Utility_Data, m_UtilityPosition, m_UtilityColor);
}

void UtilityBase::Finalize(void)
{
}

vivid::Vector2 UtilityBase::UtilityCollision(vivid::Vector2 vec2, int width, int height)
{
    bool hitflag = false;

    if (vec2.y + (float)height >= m_UtilityPosition.y
        && vec2.y <= m_UtilityPosition.y - (float)height / 2.0f)
    {
        vec2.y = m_UtilityPosition.y - (float)height;
        hitflag = true;
    }

    if (vec2.y <= m_UtilityPosition.y + (float)m_utility_height
        && vec2.y + (float)height >= m_UtilityPosition.y + (float)m_utility_height
        && vec2.x + (float)width > m_UtilityPosition.x + 5.0f
        && vec2.x < m_UtilityPosition.x + (float)m_utility_width - 5.0f)
    {
        vec2.y = m_UtilityPosition.y + (float)m_utility_height;
        hitflag = true;
    }

    //‰¡
    if (vec2.x + (float)width >= m_UtilityPosition.x
        && vec2.x <= m_UtilityPosition.x + (float)m_utility_width / 3.0f
        && vec2.y + (float)height > m_UtilityPosition.y + (float)m_utility_width / 3.0f
        && vec2.y < m_UtilityPosition.y + (float)m_utility_height / 1.5f)
    {
        vec2.x = m_UtilityPosition.x - (float)width;
        hitflag = true;
    }

    if (vec2.x + (float)width >= m_UtilityPosition.x + (float)m_utility_width
        && vec2.x <= m_UtilityPosition.x + (float)m_utility_width
        && vec2.y + (float)height > m_UtilityPosition.y + (float)m_utility_height / 3.0f
        && vec2.y < m_UtilityPosition.y + (float)m_utility_height / 1.5f)
    {
        vec2.x = m_UtilityPosition.x + (float)m_utility_width;
        hitflag = true;
    }

    if (hitflag)
    {
        return vec2;
    }
    else
    {
        return { -1.0f,-1.0f };
    }

}

vivid::Vector2 UtilityBase::GetPosition(void)
{
    return m_UtilityPosition;
}

UTILITY_ID UtilityBase::GetUtilityID(void)
{
    return UTILITY_ID();
}
