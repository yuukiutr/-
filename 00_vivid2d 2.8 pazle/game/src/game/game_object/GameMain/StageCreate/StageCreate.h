#pragma once

#include <string>

#include "vivid.h"
#include "../../StageSelect/Stage_id.h"

class StageSelect;

// マップチップ番号を列挙型で定義
enum class MAP_CHIP_ID
{
	EMPTY,			//空白
	WALL,			//壁
	STARTFLAG,		//スタート
	GOALFLAG,		//ゴール
};

const int g_map_chip_height = 64;
const int g_map_chip_width = 64;
const int g_map_chip_count_width = 12;
const int g_map_chip_count_height = 12;

class StageCreate
{
private:
	// 配列データを入れておくための二次元配列（整数）
	unsigned int m_Map[g_map_chip_count_height][g_map_chip_count_width] =
	{ (unsigned int)MAP_CHIP_ID::EMPTY };

	StageSelect* m_Select;
	STAGE_ID m_StageID;

	vivid::Vector2 m_SavePosition;

	struct ROADSTAGE
	{
		const char* const RoadName;
	};

	ROADSTAGE m_StageName[(int)STAGE_ID::MAX] =
	{
		"data\\excel\\stage1.csv",
		"data\\excel\\stage2.csv",
		"data\\excel\\stage3.csv",
		"data\\excel\\stage4.csv",
		"data\\excel\\stage5.csv",
		"data\\excel\\stage6.csv",
	};

public:
	//初期化
	void Initialize(StageSelect* target);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);
	//壁、床判定
	vivid::Vector2 GetCollision(vivid::Vector2 vec2, int width, int height, float between);
	//スタート位置を検索
	vivid::Vector2 StartPosition(void);
	//ゴールにキャラクターが接触したか(接触した == true, other == false)
	bool GoalFlag(vivid::Vector2 vec2, int width, int height);
};
