#pragma once

#include"aqua.h"

class CExplosionEffect :public aqua::IGameObject
{

public :
	CExplosionEffect(IGameObject* parent);
	~CExplosionEffect(void) = default;
	void Initialize(const aqua::CVector2& position);
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
private:
	aqua::CAnimationSprite m_AnimeSprite;
};