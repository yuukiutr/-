#include "Button_manager.h"




ButtonManager& ButtonManager::GetInstance(void)
{
	static ButtonManager	instance;

	return instance;
}

// ������
void ButtonManager::Initialize(Character* character)
{
	m_character = character;
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
