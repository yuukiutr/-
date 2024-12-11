#include "GameMain.h"
#include "../StageSelect/StageSelect.h"
#include "effectmanager/effectmanager.h"
#include "UtilitytManager/UtilitytManager.h"
#include "../gamescene_manager/gamescene_manager.h"


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

	goal.Initialize();
	Dice::GetInstance().Initialize();
}

void GameMain::Update(void)
{
	if (!Dice::GetInstance().GoalFlag())
	{

		StageCreate::GetInstance().Update();
		UtilityManager::GetInstance().Update();
		Dice::GetInstance().Update();

		//リセット
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
			|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::START)
			&& vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::X))
		{
			this->Finalize();
			this->Initialize();
		}

	}
	else
	{

		goal.Update();
	}

	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		CreateScene(GameScene_ID::RESULT);
}

void GameMain::Draw(void)
{
	vivid::DrawTexture("data/back.png", { 0.0f,0.0f });
	StageCreate::GetInstance().Draw();
	Dice::GetInstance().Draw();
	UtilityManager::GetInstance().Draw();

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

