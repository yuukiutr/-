#include "EnemyBase.h"

#include "../../character/character.h"

//const int EnemyBase::m_enemy_width;
//const int EnemyBase::m_enemy_height;

void EnemyBase::Move(void)
{
}

bool EnemyBase::GetLoseFlag(void)
{
    return false;
}

bool EnemyBase::GetDeadFlag(void)
{
    return false;
}

void EnemyBase::Initialize(Character* character)
{
	m_character = character;
    

    m_EnemyVelocity;
    m_EnemyDirection;
}

void EnemyBase::Update(void)
{

}

void EnemyBase::Draw(void)
{

}

void EnemyBase::Finalize(void)
{
}
