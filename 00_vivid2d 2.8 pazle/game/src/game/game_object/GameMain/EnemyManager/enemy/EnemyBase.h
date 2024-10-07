#pragma once
#include "vivid.h"
#include "../Enemy_ID.h"

class Character;

class EnemyBase
{
protected:
	//�萔
	static const int m_enemy_width;
	static const int m_enemy_height;
	const vivid::Vector2 m_EnemyMoveSpeed;

	//�ϐ�
	vivid::Vector2 m_EnemyPosition;
	vivid::Vector2 m_EnemyVelocity;
	vivid::Vector2 m_EnemyDirection;

	//�N���X�̌Ăяo��
	Character* m_character;

	//�֐�
	void Move(void);
public:
	virtual	void Initialize(Character* character);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);

	bool GetLoseFlag(void);
	bool GetDeadFlag(void);
};