#include "Button_manager.h"
#include "../dice/dice.h"



ButtonManager& ButtonManager::GetInstance(void)
{
	static ButtonManager	instance;

	return instance;
}

// ������
void ButtonManager::Initialize(Dice *dice)
{
	m_Dice = dice;
}

// �X�V
void ButtonManager::Updata(void)
{
}

// �`��
void ButtonManager::Draw(void)
{
}

// ���
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
