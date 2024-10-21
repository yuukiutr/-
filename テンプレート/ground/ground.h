
#pragma once

#include <string>

#include "vivid.h"
#include "../../StageSelect/Stage_id.h"

class StageSelect;

// マップチップ番号を列挙型で定義
enum class MAP_CHIP_ID
{
	EMPTY,      //何もない
	WALL,       //木（茂み）
	STARTFLAG, //スタート
	GOALFLAG,  //ゴール
};

const int g_map_chip_height = 72;
const int g_map_chip_width = 96;
const int g_map_chip_count_width = vivid::WINDOW_WIDTH / g_map_chip_width;
const int g_map_chip_count_height = vivid::WINDOW_HEIGHT / g_map_chip_height;

class Ground
{
private:
	// 配列データを入れておくための二次元配列（整数）
	unsigned int m_Map[g_map_chip_count_height][g_map_chip_count_width] =
	{ (unsigned int)MAP_CHIP_ID::EMPTY };

	StageSelect* m_Select;
	STAGE_ID m_StageID;

	vivid::Vector2 m_GroundPosition;
	vivid::Vector2 m_SavePosition;

	struct ROADSTAGE
	{
		const char* const RoadName;
	};

	ROADSTAGE m_StageName[(int)STAGE_ID::MAX] =
	{
		"data\\stage1.csv",
		"data\\stage2.csv",
		"data\\stage3.csv",
		"data\\stage4.csv",
		"data\\stage5.csv",
		"data\\stage6.csv",
		"data\\stage7.csv",
		"data\\stage8.csv",
		"data\\stage9.csv",
		"data\\stage10.csv",
		"data\\stage11.csv",
		"data\\stage12.csv",
		"data\\stage13.csv",
		"data\\stage14.csv",
		"data\\stage15.csv",
		"data\\stage16.csv",
		"data\\stage17.csv",
		"data\\stage18.csv",
		"data\\stage19.csv",
		"data\\stage20.csv",
		"data\\stage21.csv",
		"data\\stage22.csv",
		"data\\stage23.csv",
		"data\\stage24.csv",
		"data\\map_1.csv",
		"data\\special.csv",
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
	vivid::Vector2 GetCollision(vivid::Vector2 vec2, int width, int height,float between);
	//床の上に接触しているか(接触している == true,other == false)
	bool GetLandingFlag(vivid::Vector2 vec2, int width, int height);
	//壁に接触しているか(接触している == true,other == false)
	bool GetCollisionFlag(vivid::Vector2 vec2, int width, int height);
	//スタート位置を検索
	vivid::Vector2 StartPosition(void);
	//ミニキャラのスタート位置を検索
	vivid::Vector2 MiniStartPosition(void);
	//ゴールにキャラクターが接触したか(接触した == true, other == false)
	bool GoalFlag(vivid::Vector2 vec2, int width, int height);
	//敵の初期位置を返す
	vivid::Vector2 GetEnemyPosition(void);
};
