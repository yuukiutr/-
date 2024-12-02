#pragma once
#include "Stage_id.h"

class StageSelect
{
protected:
	STAGE_ID m_NowStageID;
	int m_SelectNumber;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	STAGE_ID GetNowStageID(void);

};

#define _DRAW_DEBUG_DATA false;
