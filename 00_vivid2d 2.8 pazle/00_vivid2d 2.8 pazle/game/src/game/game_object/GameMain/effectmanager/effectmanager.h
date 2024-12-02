#pragma once

#ifndef GEKKIDEN2_EFFECTMANAGER_H_
#define GEKKIDEN2_EFFECTMANAGER_H_

#include <list>
#include <map>
#include <functional>

#include "effect_id.h"
#include "effect/effectbase.h"
#include "vivid.h"

#endif //GEKKIDEN2_EFFECTMANAGER_H_

class EffectManager final
{
private:
	EffectManager() = default;
	~EffectManager() = default;
	
	static inline EffectManager* s_Instance;

	using EFFECT_LIST = std::list<EffectBase*>;

	EFFECT_LIST m_EffectList;

	std::map<EFFECT_ID, std::function<EffectBase* (void)>> m_Generator;

public:

	EffectManager(const EffectManager& rhs) = delete;
	EffectManager& operator=(const EffectManager& rhs) = delete;
	EffectManager(const EffectManager&& rhs) = delete;
	EffectManager& operator=(const EffectManager&& rhs) = delete;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void Create(EFFECT_ID ID,vivid::Vector2 pos = { 0.0f,0.0f }, float rotation = 0.0f);

	static void CreateInstance(void);

	static void DeleteInstance(void);

	static EffectManager& GetInstance(void);

};

#define EFFECT EffectManager::GetInstance()
