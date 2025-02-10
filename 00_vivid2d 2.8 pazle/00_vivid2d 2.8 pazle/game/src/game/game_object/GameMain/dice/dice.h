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
	vivid::Vector2 m_Velocity;
	vivid::Vector2 m_BlastPosition;
	vivid::Vector2 m_BlastContainer[6];
	vivid::Rect rect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const vivid::Vector2 m_map_position = {200.0f, 200.0f};
	const float m_map_width = 768;
	const float m_map_height = 768;

	int m_KeyCount;			//カギ数カウント
	int m_MaxKey;			//最大カギ数
	bool m_KeyClearFlag;	//カギ数条件達成フラグ

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
	vivid::Vector2 GetVelocity(void);

	/*
*	@brief	爆発する範囲を返す
*	@param[in]	x軸
*	@param[in]	y軸
*	@return		爆破範囲
*/
	Blast BlastSpot(int x, int y);

	/*
	*	@brief	爆破予定地を返す
	*/
	vivid::Vector2 GetBlastPos(int i);


	bool GoalFlag(void);
	bool KeyFlag(void);
	vivid::Vector2 GetDicePosition(void);
};