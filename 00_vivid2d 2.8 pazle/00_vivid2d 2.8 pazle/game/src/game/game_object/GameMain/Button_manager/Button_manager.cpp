#include "Button_manager.h"
#include "../dice/dice.h"



ButtonManager& ButtonManager::GetInstance(void)
{
	static ButtonManager	instance;

	return instance;
}

// 初期化
void ButtonManager::Initialize(Dice *dice)
{
	m_Dice = dice;
}

// 更新
void ButtonManager::Updata(void)
{
}

// 描画
void ButtonManager::Draw(void)
{
}

// 解放
void ButtonManager::Finalize(void)
{
}

bool ButtonManager::GetLundingFlag(void)
{
	return false;
}

bool ButtonManager::GetOnFlag(void)
{
	return false;
}
