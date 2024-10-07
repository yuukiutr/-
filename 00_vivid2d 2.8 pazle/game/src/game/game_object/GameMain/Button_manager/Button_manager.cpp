#include "Button_manager.h"




ButtonManager& ButtonManager::GetInstance(void)
{
	static ButtonManager	instance;

	return instance;
}

// ‰Šú‰»
void ButtonManager::Initialize(Character* character)
{
	m_character = character;
}

// XV
void ButtonManager::Updata(void)
{
}

// •`‰æ
void ButtonManager::Draw(void)
{
}

// ‰ğ•ú
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
