#include "Title.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../TextManager/TextManager.h"

void Title::Initialize(void)
{
	m_Position = { 500.0f,700.0f };
	rect = { 0, 0, m_dice_width, m_dice_height };
	m_OuterFrameCount = 0; //外枠点滅
	m_ID = GameScene_ID::STAGESELECT;
}

void Title::Update(void)
{
	namespace keyboard = vivid::keyboard;

	//シーン切り替え
	if (keyboard::Trigger(keyboard::KEY_ID::NUMPADENTER))
	{
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
	}
	else if (keyboard::Trigger(keyboard::KEY_ID::S) && m_Position.y == 700.0f)
	{
		m_Position.y += 64.0f;
		rect = { 64, 0, m_dice_width * 2, m_dice_height };
		m_ID = GameScene_ID::OPTION;
	}

	if (m_OuterFrameCount++ > 50)
		m_OuterFrameCount = 0;
}

void Title::Draw(void)
{
#ifndef Title
	vivid::DrawText(32, "タイトル", { 0.0f,0.0f });
#endif // !Title
	vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);
	vivid::DrawTexture("data\\title\\start.png", {564.0f,700.0f});
	vivid::DrawTexture("data\\title\\option.png", { 564.0f,764.0f });
	vivid::DrawTexture("data\\title\\title.png", { 240.0f,20.0f });

	if(m_OuterFrameCount < 40)
	vivid::DrawTexture("data\\title\\outer_frame.png", { m_Position.x + m_dice_width, m_Position.y });


}

void Title::Finalize(void)
{
}
