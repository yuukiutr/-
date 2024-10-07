#include "StageSelect.h"

#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"

void StageSelect::Initialize(void)
{
	m_SelectNumber = 0;
	m_NowStageID = STAGE_ID::DUMMY;
	m_StarCount = 0;
	m_TutorialFlag = false;
	m_CommentCount = 0;

	m_Handle = CreateFontToHandle("ゴシック", 50, 2, DX_FONTTYPE_EDGE, -1, 2);
}

void StageSelect::Update(void)
{
	if (m_TutorialFlag)
	{
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RETURN))
		{
			++m_CommentCount;

			if (m_CommentCount >= NUM)
			{
				CreateScene(GameScene_ID::MAIN);
				return;
			}
		}
	}

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D) && !m_TutorialFlag
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::RIGHT))
	{
		m_SelectNumber++;
	}
	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A)
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::LEFT)
		&& !m_TutorialFlag)
	{
		m_SelectNumber--;
	}

	if (m_SelectNumber >= (int)STAGE_ID::DUMMY)
	{
		m_SelectNumber = 0;
	}

	if (m_SelectNumber < 0)
	{
		m_SelectNumber = (int)STAGE_ID::DUMMY;
		m_SelectNumber--;
	}



	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::START))
	{
		CreateScene(GameScene_ID::TITLE);
	}


#ifdef VIVID_DEBUG
#if _DRAW_DEBUG_DATA
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPADENTER)
		&& vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPAD3) && !m_TutorialFlag)
	{
		m_SelectNumber = (int)STAGE_ID::DUMMY;
	}
#endif
#endif //VIVID_DEBUG

	if (m_NowStageID != (STAGE_ID)m_SelectNumber)
	{
		m_NowStageID = (STAGE_ID)m_SelectNumber;
	}
}

void StageSelect::Draw(void)
{

#ifdef VIVID_DEBUG
#if _DRAW_DEBUG_DATA
	//ここでデバック用に必要な数値を出す
#endif
#endif
}

void StageSelect::Finalize(void)
{
}

STAGE_ID StageSelect::GetNowStageID(void)
{
	return m_NowStageID;
}
