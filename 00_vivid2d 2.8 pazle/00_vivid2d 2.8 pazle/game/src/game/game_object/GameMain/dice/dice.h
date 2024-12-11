#pragma once
#include "vivid.h"
#include "../StageCreate/MapChipID.h"


struct Blast
{
	bool			DicePosFlag;
	vivid::Vector2	BlastPos;
	MAP_CHIP_ID		ID;
};

class Dice
{
private:
	int m_DiceDigit;	//�_�C�X�̏o��
	int m_BlastCount;	//���j��
	int m_MoveCount;	//�ړ���
	vivid::Vector2 m_Position;
	vivid::Vector2 m_Velocity;
	vivid::Vector2 m_BlastPosition;
	vivid::Rect rect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const float m_map_width = 768;
	const float m_map_height = 768;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);

	/*
	* @return int �P�`�U�܂ł̊ԂŐ��l��Ԃ��B
	*/
	int GetDiceDigit(void);
	int GetDiceWidth(void);
	int GetDiceHeight(void);
	int GetMoveCount(void);
	vivid::Vector2 GetVelocity(void);

	/*
*	@brief	��������͈͂�Ԃ�
*	@param[in]	x��
*	@param[in]	y��
*	@return		���j�͈�
*/
	Blast BlastSpot(int x, int y);

	/*
	*	@brief	���j�͈͂ɔj��ł���I�u�W�F�N�g������ꍇ�j�󂷂�
	*/
	MAP_CHIP_ID Blast(void);


	bool GoalFlag(void);
	vivid::Vector2 GetDicePosition(void);
};