#include "Title.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../TextManager/TextManager.h"
#include "../sound_manager/sound_manager.h"

void Title::Initialize(void)
{
	m_Position = { 500.0f,700.0f };
	rect = { 0, 0, m_dice_width, m_dice_height };
	m_OuterFrameCount = 0; //外枠点滅
	m_ID = GameScene_ID::STAGESELECT;
	
	CSoundManager::GetInstance().Load();
	CSoundManager::GetInstance().Play(SOUND_ID::TITLE, true);
}

void Title::Update(void)
{
	namespace keyboard = vivid::keyboard;

	//シーン切り替え
	if (keyboard::Trigger(keyboard::KEY_ID::NUMPADENTER))
	{
		CSoundManager::GetInstance().Play(SOUND_ID::DECISION);
		switch (m_ID)
		{
		case GameScene_ID::STAGESELECT:

			CreateScene(GameScene_ID::STAGESELECT);
			break;

		case GameScene_ID::OPTION:
			CreateScene(GameScene_ID::OPTION);
			break;

		default:
			break;
		}
	}
	if (keyboard::Trigger(keyboard::KEY_ID::W) && m_Position.y == 764.0f)
	{
		m_Position.y -= 64.0f;
		rect = { 0, 0, m_dice_width, m_dice_height };
		m_ID = GameScene_ID::STAGESELECT;
		CSoundManager::GetInstance().Play(SOUND_ID::SELECT);
	}
	else if (keyboard::Trigger(keyboard::KEY_ID::S) && m_Position.y == 700.0f)
	{
		m_Position.y += 64.0f;
		rect = { 64, 0, m_dice_width * 2, m_dice_height };
		m_ID = GameScene_ID::OPTION;
		CSoundManager::GetInstance().Play(SOUND_ID::SELECT);
	}

	if (m_OuterFrameCount++ > m_outer_frame_roop_time)
		m_OuterFrameCount = 0;
}

void Title::Draw(void)
{
	vivid::DrawTexture("data\\title\\title_bg.jpeg", {0.0f,0.0f});
#ifndef Title
	vivid::DrawText(32, "タイトル", { 0.0f,0.0f });
#endif // !Title
	vivid::DrawTexture("data\\title\\title_dice.png", m_Position, 0xffffffff, rect);
	vivid::DrawTexture("data\\title\\start.png", {564.0f,700.0f});
	vivid::DrawTexture("data\\title\\option.png", { 564.0f,764.0f });
	vivid::DrawTexture("data\\title\\title.png",
		{ (float)(vivid::WINDOW_WIDTH - m_title_logo_width) / 2,300.0f });

	//いらないかも
	//if(m_OuterFrameCount < m_outer_frame_light_time)
	//vivid::DrawTexture("data\\title\\outer_frame.png", { m_Position.x + m_dice_width, m_Position.y });


}

void Title::Finalize(void)
{
	CSoundManager::GetInstance().StopSound(SOUND_ID::TITLE);
}
