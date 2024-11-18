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
	int m_DiceDigit; //ƒ_ƒCƒX‚Ìo–Ú
	int m_BlastCount;//”š”j‰ñ”
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
	* @return int ‚P`‚U‚Ü‚Å‚ÌŠÔ‚Å”’l‚ğ•Ô‚·B
	*/
	int GetDiceDigit(void);
	int GetDiceWidth(void);
	int GetDiceHeight(void);

	/*
*	@break	”š”­‚·‚é”ÍˆÍ‚ğ•Ô‚·
*	@param[in]	x²
*	@param[in]	y²
*	@return		”š”j”ÍˆÍ
*/
	Blast BlastSpot(int x, int y);

	vivid::Vector2 GetDicePosition(void);
};