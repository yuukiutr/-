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

	int m_DiceDigit;	//�_�C�X�̏o��
	int m_BlastCount;	//���j��
	int m_MoveCount;	//�ړ���
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
	*	@brief	���j�\��n��Ԃ�
	*/
	vivid::Vector2 GetBlastPos(int i);


	bool GoalFlag(void);
	vivid::Vector2 GetDicePosition(void);
};