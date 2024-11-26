#include "Title.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../TextManager/TextManager.h"

void Title::Initialize(void)
{
	m_Position = { 500.0f,700.0f };
	rect = { 0, 0, m_dice_width, m_dice_height };
	m_GoStageSelect = true;
	m_OuterFrameCount = 0;
}

void Title::Update(void)
{
	namespace keyboard = vivid::keyboard;

	if (keyboard::Trigger(keyboard::KEY_ID::NUMPADENTER) && m_GoStageSelect)
	{
		CreateScene(GameScene_ID::STAGESELECT);
	}
	else if(keyboard::Trigger(keyboard::KEY_ID::NUMPADENTER))
	{
		CreateScene(GameScene_ID::OPTION);
	}

	if ((keyboard::Trigger(keyboard::KEY_ID::W) || keyboard::Trigger(keyboard::KEY_ID::S)) && m_Position.y == 764.0f)
	{
		m_Position.y -= 64.0f;
		rect = { 0, 0, m_dice_width, m_dice_height };
		m_GoStageSelect = true;
	}
	else if ((keyboard::Trigger(keyboard::KEY_ID::S) || keyboard::Trigger(keyboard::KEY_ID::W)) && m_Position.y == 700.0f)
	{
		m_Position.y += 64.0f;
		rect = { 64, 0, m_dice_width * 2, m_dice_height };
		m_GoStageSelect = false;
	}

	if (m_OuterFrameCount++ > 40)
		m_OuterFrameCount = 0;
}

void Title::Draw(void)
{
#ifndef Title
	vivid::DrawText(32, "ƒ^ƒCƒgƒ‹", { 0.0f,0.0f });
#endif // !Title
	vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);
	vivid::DrawTexture("data\\title\\start.png", {564.0f,700.0f});
	vivid::DrawTexture("data\\title\\option.png", { 564.0f,764.0f });

	if(m_OuterFrameCount < 30)
	vivid::DrawTexture("data\\title\\outer_frame.png", { m_Position.x + 64.0f,m_Position.y });


}

void Title::Finalize(void)
{
}
