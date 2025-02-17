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
		m_SelectNumber++;
		m_ReturnCount = 0;
	}
	else if(vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A))
	{
		m_SelectNumber--;
		m_ReturnCount = 0;
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
	vivid::DrawTexture("data\\stage_select_bg.png", { 0.0f, 0.0f });
	vivid::DrawTexture("data\\button.png", { 200.0f, 200.0f });
	if(m_FremeVisibleFlag)
	vivid::DrawTexture("data\\button_frame.png", { 200.0f, 200.0f });
	vivid::DrawTexture("data\\stage1.png", { 201.0f, 255.0f });

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
