#include "option.h"
#include"../gamescene_manager/gamescene_manager.h"


void OPTION::Initialize(void)
{
}

void OPTION::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A)
		||vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1,vivid::controller::BUTTON_ID::B))
	{
		CreateScene(GameScene_ID::TITLE);
	}

}

void OPTION::Draw(void)
{
#ifdef VIVID_DEBUG
	vivid::DrawText(50, "オプション", { 0.0f,0.0f });
	vivid::DrawText(50, "Aボタンで戻る", { 0.0f,50.0f });

#endif // VIVID_DEBUG

}

void OPTION::Finalize(void)
{
}
