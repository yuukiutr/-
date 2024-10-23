#pragma once
#include "vivid.h"

class Dice
{
private:
	int m_DiceDigit; //�_�C�X�̏o��
	int m_BlastCount;//���j��
	vivid::Vector2 m_Position;
	vivid::Rect rect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);

	/*
	* @return int �P�`�U�܂ł̊ԂŐ��l��Ԃ��B
	*/
	int GetDiceDigit(void);
};