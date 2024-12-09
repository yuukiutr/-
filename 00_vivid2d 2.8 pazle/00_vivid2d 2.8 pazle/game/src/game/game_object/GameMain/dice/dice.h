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

	int m_DiceDigit;	//ダイスの出目
	int m_BlastCount;	//爆破回数
	int m_MoveCount;	//移動回数
	vivid::Vector2 m_Position;
	vivid::Vector2 m_BlastPosition;
	vivid::Rect rect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
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
	* @return int １～６までの間で数値を返す。
	*/
	int GetDiceDigit(void);
	int GetDiceWidth(void);
	int GetDiceHeight(void);
	int GetMoveCount(void);

	/*
*	@brief	爆発する範囲を返す
*	@param[in]	x軸
*	@param[in]	y軸
*	@return		爆破範囲
*/
	Blast BlastSpot(int x, int y);

	/*
	*	@brief	爆破範囲に破壊できるオブジェクトがある場合破壊する
	*/
	MAP_CHIP_ID Blast(void);


	bool GoalFlag(void);
	vivid::Vector2 GetDicePosition(void);
};