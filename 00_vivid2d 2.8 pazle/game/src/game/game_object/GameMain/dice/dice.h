#pragma once
#include "vivid.h"

class StageCreate;

class Dice
{
private:
	int m_DiceDigit; //ダイスの出目
	int m_BlastCount;//爆破回数
	vivid::Vector2 m_Position;
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
	* @return int １～６までの間で数値を返す。
	*/
	int GetDiceDigit(void);
	int GetDiceWidth(void);
	int GetDiceHeight(void);

	vivid::Vector2 GetDicePosition(void);
};