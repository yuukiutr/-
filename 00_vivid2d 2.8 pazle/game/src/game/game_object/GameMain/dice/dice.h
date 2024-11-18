#pragma once
#include "vivid.h"

class StageCreate;

struct Blast
{
	bool DicePosFlag;
	vivid::Vector2 BlastPos;
};

class Dice
{
private:
	int m_DiceDigit; //�_�C�X�̏o��
	int m_BlastCount;//���j��
	vivid::Vector2 m_Position;
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

	/*
*	@break	��������͈͂�Ԃ�
*	@param[in]	x��
*	@param[in]	y��
*	@return		���j�͈�
*/
	Blast BlastSpot(int x, int y);

	vivid::Vector2 GetDicePosition(void);
};