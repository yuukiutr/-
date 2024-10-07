#include "effectmanager.h"

#include <list>
#include <map>
#include <functional>

#include "vivid.h"
#include "effect_id.h"
#include "effect/effectbase.h"

void EffectManager::Initialize(void)
{
	m_Generator[EFFECT_ID::DUMMY] = []() {return nullptr; };
}

void EffectManager::Update(void)
{
	auto it = m_EffectList.begin();
	auto end = m_EffectList.end();

	while (it != end)
	{
		(*it)->Update();

		if (!(*it)->GetActiveFlag())
		{
			(*it)->Finalize();

			delete (*it);

			it = m_EffectList.erase(it);

			continue;
		}

		++it;
	}
}

void EffectManager::Draw(void)
{
	auto it = m_EffectList.begin();
	auto end = m_EffectList.end();

	while (it != end)
	{
		(*it)->Draw();

		++it;
	}
}

void EffectManager::Finalize(void)
{
	auto it = m_EffectList.begin();
	auto end = m_EffectList.end();

	while (it != end)
	{
		(*it)->Finalize();
		
		delete (*it);

		it = m_EffectList.erase(it);
	}

	m_EffectList.clear();

}

void EffectManager::Create(EFFECT_ID ID,vivid::Vector2 pos, float rotation)
{
	EffectBase* base = nullptr;

	base = m_Generator[ID]();

	if (base == nullptr) return;

	base->Initialize(pos, rotation);

	m_EffectList.push_back(base);
}

void EffectManager::CreateInstance(void)
{
	EffectManager::DeleteInstance();

	s_Instance = new EffectManager();
}

void EffectManager::DeleteInstance(void)
{
	if (s_Instance != nullptr)
	{
		delete s_Instance;

		s_Instance = nullptr;
	}

}

EffectManager& EffectManager::GetInstance(void)
{
	// TODO: return ステートメントをここに挿入します
	return *s_Instance;
}
