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

	Dice() = default;
	~Dice() = default;

	Dice(const Dice&) = delete;
	Dice(const Dice&&) = delete;
	Dice& operator=(const Dice&) = delete;
	Dice& operator=(const Dice&&) = delete;

	static inline Dice* m_Instance;

	int m_DiceDigit;	//ƒ_ƒCƒX‚Ìo–Ú
	int m_BlastCount;	//”š”j‰ñ”
	int m_MoveCount;	//ˆÚ“®‰ñ”
	vivid::Vector2 m_Position;
	vivid::Vector2 m_Velocity;
	vivid::Vector2 m_BlastPosition;
	vivid::Rect rect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const vivid::Vector2 m_map_position = {200.0f, 200.0f};
	const float m_map_width = 768;
	const float m_map_height = 768;

public:

	static void CreateInstance(void);
	static void DeleteInstance(void);
	static Dice& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);

	/*
	* @return int ‚P`‚U‚Ü‚Å‚ÌŠÔ‚Å”’l‚ğ•Ô‚·B
	*/
	int GetDiceDigit(void);
	int GetDiceWidth(void);
	int GetDiceHeight(void);
	int GetMoveCount(void);
	vivid::Vector2 GetVelocity(void);

	/*
*	@brief	”š”­‚·‚é”ÍˆÍ‚ğ•Ô‚·
*	@param[in]	x²
*	@param[in]	y²
*	@return		”š”j”ÍˆÍ
*/
	Blast BlastSpot(int x, int y);

	/*
	*	@brief	”š”j—\’è’n‚ğ•Ô‚·
	*/
	vivid::Vector2 GetBlastPos(int i);


	bool GoalFlag(void);
	vivid::Vector2 GetDicePosition(void);
};