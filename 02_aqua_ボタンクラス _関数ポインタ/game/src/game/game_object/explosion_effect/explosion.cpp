#include "explosion.h"

CExplosionEffect::CExplosionEffect(IGameObject* parent)
	:IGameObject(parent,"ExplosionEffect","Effect")
{
}

void CExplosionEffect::Initialize(const aqua::CVector2& position)
{
	m_AnimeSprite.Create("data\\explosion.ass");
	m_AnimeSprite.position = position;

}

void CExplosionEffect::Update(void)
{
	m_AnimeSprite.Update();

	if (m_AnimeSprite.Finished())
		DeleteObject();
}

void CExplosionEffect::Draw(void)
{
	m_AnimeSprite.Draw();
}

void CExplosionEffect::Finalize(void)
{
	m_AnimeSprite.Delete();
}
