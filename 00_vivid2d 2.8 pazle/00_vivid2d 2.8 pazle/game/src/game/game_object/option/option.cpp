#include "option.h"
#include"../gamescene_manager/gamescene_manager.h"
#include "../sound_manager/sound_manager.h"

void Option::Initialize(void)
{
	CSoundManager::GetInstance().Load();
}

void Option::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R))
	{
		CSoundManager::GetInstance().Play(SOUND_ID::CANCEL);
		CreateScene(GameScene_ID::TITLE);
	}

}

void Option::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(50, "オプション", { 0.0f,0.0f });
	vivid::DrawText(50, "Rボタンで戻る", { 0.0f,50.0f });

#endif // VIVID_DEBUG

}

void Option::Finalize(void)
{
}
