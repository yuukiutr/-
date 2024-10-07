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
	//初期化
	void Initialize(void);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);
	//キャラクターの位置
	vivid::Vector2 GetCharacterPosition(void);
	//キャラクターの移動速度
	vivid::Vector2 GetCharacterVelocity(void);
	//キャラクターの向き
	vivid::Vector2 GetCharacterDirection(void);
	//キャラクターの幅
	int GetCharacterWidth(void);
	//キャラクターの高さ
	int GetCharacterHeight(void);
	//負け判定(LOSE == true,other == false)
	bool GetLoseFlag(void);
	//ゴール判定(GOAL == true,other == false)
	bool GetGoalFlag(void);
	//デバック時に表示されるキャラクターのデータ
	void CHARACTER_DEBUG_DRAW_DATA(void);

};
