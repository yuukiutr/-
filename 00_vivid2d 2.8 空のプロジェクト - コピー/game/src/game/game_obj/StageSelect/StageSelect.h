#pragma once
#include "StageID.h"

class StageSelect
{
protected:
	bool m_TutorialFlag;

	STAGE_ID m_NowStageID;
	int m_SelectNumber;
	int m_StarCount;
	int m_Handle;
	int m_CommentCount;

	enum COMMENT
	{
		NUM = 15,
	};

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	STAGE_ID GetNowStageID(void);

};

#define _DRAW_DEBUG_DATA false;
