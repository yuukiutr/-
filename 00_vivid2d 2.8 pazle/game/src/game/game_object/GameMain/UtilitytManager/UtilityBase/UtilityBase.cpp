#include "UtilityBase.h"

void UtilityBase::Initialize(StageCreate* stage, vivid::Vector2 pos)
{
    m_Stage = stage;

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
    return vec2;
}

vivid::Vector2 UtilityBase::GetPosition(void)
{
    return m_UtilityPosition;
}

UTILITY_ID UtilityBase::GetUtilityID(void)
{
    return UTILITY_ID();
}
