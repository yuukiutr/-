#include "effectbase.h"

EffectBase::EffectBase(int width, int height)
	: m_Width(width)
	, m_Height(height)
{
}

void EffectBase::Initialize(vivid::Vector2 pos = {0.0f,0.0f}, float rotation = 0.0f)
{
}

void EffectBase::Update(void)
{
}

void EffectBase::Draw(void)
{
}

void EffectBase::Finalize(void)
{
}

bool EffectBase::GetActiveFlag(void)
{
	return false;
}
