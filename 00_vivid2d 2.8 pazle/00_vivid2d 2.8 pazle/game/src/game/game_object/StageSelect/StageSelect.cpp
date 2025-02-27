#include "StageSelect.h"
#include "../sound_manager/sound_manager.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"

void StageSelect::Initialize(void)
{
	m_SelectNumber = 0;
	m_FrameCount = 0;
	m_frame_invisible = 50;
	m_frame_count_reset = 70;
	m_ReturnCount = 0;
	m_return_time = 1200;
	m_Color = 0x00ffffff;
	m_FremeVisibleFlag = true;
	m_NowStageID = STAGE_ID::DUMMY;
	m_ButtonPosition = { 100.0f,200.0f };
	m_stage1_position = { 100.0f,310.0f };

	CSoundManager::GetInstance().Load();
	CSoundManager::GetInstance().Play(SOUND_ID::STAGESELECT, true);
}

void StageSelect::Update(void)
{
	m_FrameCount++;
	int alpha = m_Color >> 24;

	if (m_FrameCount > m_frame_invisible)
		m_FremeVisibleFlag = false;

	if (m_FrameCount > m_frame_count_reset)
	{
		m_FremeVisibleFlag = true;
		m_FrameCount = 0;
	}

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D))
	{
		if (m_SelectNumber == 2)
		{
			m_SelectNumber = 0;
		}
		else
		{
			m_SelectNumber++;
		}
		m_ReturnCount = 0;
		CSoundManager::GetInstance().Play(SOUND_ID::SELECT);
	}
	else if(vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A))
	{
		if (m_SelectNumber == 0)
		{
			m_SelectNumber = 2;
		}
		else 
		{
		m_SelectNumber--;
		}
		m_ReturnCount = 0;
		CSoundManager::GetInstance().Play(SOUND_ID::SELECT);

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

if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R))
	{
		 CreateScene(GameScene_ID::TITLE);
		 CSoundManager::GetInstance().Play(SOUND_ID::CANCEL);
	}
	
if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER))
{
	CreateScene(GameScene_ID::MAIN);
}

//–³‘€ì20•b‚Åƒ^ƒCƒgƒ‹‚Ö
if (++m_ReturnCount >= m_return_time)
{
	alpha += 5;//ˆÃ“]
	if (alpha >= 255)
	{
		alpha = 255;
	CreateScene(GameScene_ID::TITLE);
	}
	m_Color = alpha << 24 | (m_Color & 0x00ffffff);

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
	vivid::DrawTexture("data\\stage_select\\stage_select_bg.png", { 0.0f, 0.0f });
	vivid::DrawTexture("data\\stage_select\\button.png", m_ButtonPosition);
	if(m_FremeVisibleFlag)
	vivid::DrawTexture("data\\stage_select\\button_frame.png", m_ButtonPosition);
	vivid::DrawTexture("data\\stage_select\\select.png", {100.0f,600.0f});
	switch (m_SelectNumber)
	{
	case 0:
		vivid::DrawTexture("data\\stage_select\\stage1.png", m_stage1_position);
		break;
	case 1:
		vivid::DrawTexture("data\\stage_select\\stage2.png", m_stage1_position);
		break;
	case 2:
		vivid::DrawTexture("data\\stage_select\\stage3.png", m_stage1_position);
		break;
	default:
		break;
	}

#ifdef VIVID_DEBUG
	vivid::DrawText(50, "ƒQ[ƒ€‘I‘ð", { 0.0f,0.0f });
	vivid::DrawText(50, "R‚Å–ß‚é", { 0.0f,50.0f });
#endif

	vivid::DrawTexture("data\\black_bg.png", { 0.0f,0.0f }, m_Color);
}

void StageSelect::Finalize(void)
{
	CSoundManager::GetInstance().StopSound(SOUND_ID::STAGESELECT);
}

STAGE_ID StageSelect::GetNowStageID(void)
{
	return m_NowStageID;
}

int StageSelect::GetSelectNumber(void)
{
	return m_SelectNumber;
}
