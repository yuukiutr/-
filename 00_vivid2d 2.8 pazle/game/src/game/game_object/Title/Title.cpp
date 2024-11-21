#include "Title.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../TextManager/TextManager.h"

void Title::Initialize(void)
{
	m_Position = { 500.0f,700.0f };//スタートマスの位置を参照
	rect = { 0, 0, m_dice_width, m_dice_height };
	m_GoStageSelect = true;
}

void Title::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER) && m_GoStageSelect)
	{
		CreateScene(GameScene_ID::STAGESELECT);
	}
	else if(vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER))
	{
		CreateScene(GameScene_ID::OPTION);
	}

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W) && m_Position.y == 764.0f)
	{
		m_Position.y -= 64.0f;
		rect = { 0, 0, m_dice_width, m_dice_height };
		m_GoStageSelect = true;
	}
	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S) && m_Position.y == 700.0f)
	{
		m_Position.y += 64.0f;
		rect = { 64, 0, m_dice_width * 2, m_dice_height };
		m_GoStageSelect = false;
	}
}

void Title::Draw(void)
{
#ifndef Title
	vivid::DrawText(32, "タイトル", { 0.0f,0.0f });
#endif // !Title
	vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);


}

void Title::Finalize(void)
{
}
