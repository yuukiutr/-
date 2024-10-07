#pragma once
#include "vivid.h"

class Character
{
private:
	const int m_character_height;
	const int m_character_width;
	vivid::Vector2 m_CharacterPosition;
	vivid::Vector2 m_CharacterVelocity;
	vivid::Vector2 m_CharacterDirection;
	const float m_character_inertia;
	const float m_character_move_speed;
	bool m_LoseFlag;

	enum class STATE_ID
	{
		OTHER,
		PUSH,
		JUMP,
	};

	STATE_ID m_CharacterState;
	int m_AnimChangeTimer;
	int m_AnimRectPoint;

public:
	//������
	void Initialize(void);
	//�X�V
	void Update(void);
	//�`��
	void Draw(void);
	//���
	void Finalize(void);
	//�L�����N�^�[�̈ʒu
	vivid::Vector2 GetCharacterPosition(void);
	//�L�����N�^�[�̈ړ����x
	vivid::Vector2 GetCharacterVelocity(void);
	//�L�����N�^�[�̌���
	vivid::Vector2 GetCharacterDirection(void);
	//�L�����N�^�[�̕�
	int GetCharacterWidth(void);
	//�L�����N�^�[�̍���
	int GetCharacterHeight(void);
	//��������(LOSE == true,other == false)
	bool GetLoseFlag(void);
	//�S�[������(GOAL == true,other == false)
	bool GetGoalFlag(void);
	//�f�o�b�N���ɕ\�������L�����N�^�[�̃f�[�^
	void CHARACTER_DEBUG_DRAW_DATA(void);

};
