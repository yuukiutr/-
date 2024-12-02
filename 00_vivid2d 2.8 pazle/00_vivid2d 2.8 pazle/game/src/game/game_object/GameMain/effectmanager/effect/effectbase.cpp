#include "effectbase.h"

EffectBase::EffectBase(int width, int height)
	: m_Width(width)
	, m_Height(height)
{
}

void EffectBase::Initialize(vivid::Vector2 pos ,float rotation)
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
