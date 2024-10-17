#include "Title.h"
#include "vivid.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../TextManager/TextManager.h"

void Title::Initialize(void)
{
	
}

void Title::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER))
	{
		CreateScene(GameScene_ID::STAGESELECT);
	}
}

void Title::Draw(void)
{
#ifndef Title
	vivid::DrawText(32, "ƒ^ƒCƒgƒ‹", { 0.0f,0.0f });
#endif // !Title

}

void Title::Finalize(void)
{
}
