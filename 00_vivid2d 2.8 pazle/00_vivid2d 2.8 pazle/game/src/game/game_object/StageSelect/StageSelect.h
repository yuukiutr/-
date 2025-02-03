#pragma once
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
	int m_ReturnCount;		//無操作時間計測
	int m_return_time;		//タイトルに戻るまでの時間
	unsigned int	m_Color;		//透明度

};

#define _DRAW_DEBUG_DATA false;
