#pragma once
#include "vivid.h"
#include "Stage_id.h"

class StageSelect
{
protected:
	STAGE_ID m_NowStageID;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	STAGE_ID GetNowStageID(void);

private:
	int m_SelectNumber;
	int m_FrameCount;					//フレームの点滅用
	int m_frame_invisible;				//フレームの見えない時間
	int m_frame_count_reset;			//フレームカウントのリセット
	int m_ReturnCount;					//無操作時間計測
	int m_return_time;					//タイトルに戻るまでの時間
	unsigned int	m_Color;			//透明度
	bool m_FremeVisibleFlag;			//フレームのフラグ
	vivid::Vector2 m_ButtonPosition;	//ボタンの位置
	vivid::Vector2 m_stage1_position;	//stage 1の位置
};

#define _DRAW_DEBUG_DATA false;
