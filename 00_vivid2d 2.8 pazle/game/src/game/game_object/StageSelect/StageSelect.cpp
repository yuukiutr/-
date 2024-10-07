#include "StageSelect.h"

#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../../BGM_SE/BGM_SE.h"
#include "../../BGM_SE/SE_ID.h"

void StageSelect::Initialize(void)
{
	m_SelectNumber = 0;
	m_NowStageID = STAGE_ID::DUMMY;
}

void StageSelect::Update(void)
{

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D)
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::RIGHT))
	{
		StartSE(SE_ID::CHENG);
		m_SelectNumber++;
	}
	else if(vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A)
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::LEFT))
	{
		StartSE(SE_ID::CHENG);
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

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPAD8)
		&& vivid::keyboard::Button(vivid::keyboard::KEY_ID::D))
	{
		m_SelectNumber = (int)STAGE_ID::SPECIAL;
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
#ifdef VIVID_DEBUG

#endif // VIVID_DEBUG
}

void StageSelect::Draw(void)
{
#ifdef VIVID_DEBUG
#if _DRAW_DEBUG_DATA
	//見本 vivid::DrawText(50, "水色ブロック   　引力の強い状態でしばらく乗っていると上に落ちるブロック", { 0.0f,750.0f }, 0xffff8800);
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
