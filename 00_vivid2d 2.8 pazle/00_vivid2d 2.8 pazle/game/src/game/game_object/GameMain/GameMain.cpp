#include "GameMain.h"
#include "../StageSelect/StageSelect.h"
#include "effectmanager/effectmanager.h"
#include "UtilitytManager/UtilitytManager.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "UtilitytManager/UtilityBase/Key/key.h"

//main Initialize
void GameMain::Initialize(StageSelect* target)
{
	m_Select = target;
	UtilityManager::GetInstance().Initialize();
	StageCreate::GetInstance().Initialize(m_Select);
	Dice::GetInstance().Initialize();
	goal.Initialize();
	//ste_BGM_Initialize();
}

//overroad Initialize
void GameMain::Initialize(void)
{
	UtilityManager::GetInstance().Initialize();
	StageCreate::GetInstance().Initialize(m_Select);
	Dice::GetInstance().Initialize();

	goal.Initialize();
}

void GameMain::Update(void)
{
	if (Dice::GetInstance().GoalFlag() && UtilityManager::GetInstance().GetKeyClearFlag())
	{
		goal.Update();
	}
	else
	{
		StageCreate::GetInstance().Update();
		Dice::GetInstance().Update();
		UtilityManager::GetInstance().Update();

		//リセット
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R))
		{
			this->Finalize();
			this->Initialize();
		}
	}

#ifdef DEBUG
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		CreateScene(GameScene_ID::RESULT);
#endif // DEBUG

}

void GameMain::Draw(void)
{
	vivid::DrawTexture("data/back.png", { 0.0f,0.0f });
	UtilityManager::GetInstance().Draw();
	StageCreate::GetInstance().Draw();
	Dice::GetInstance().Draw();

	//これより前に書く
	goal.Draw();

#ifdef VIVID_DEBUG
	vivid::DrawText(32, "ゲームメイン", { 0.0f,0.0f });
#endif //VIVID_DEBUG

}

void GameMain::Finalize(void)
{
	StageCreate::GetInstance().Finalize();
	UtilityManager::GetInstance().Finalize();
	goal.Finalize();
}

