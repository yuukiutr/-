#include "GameMain.h"
#include "../StageSelect/StageSelect.h"
#include "effectmanager/effectmanager.h"
#include "UtilitytManager/UtilitytManager.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "UtilitytManager/UtilityBase/Key/key.h"
#include "../sound_manager/sound_manager.h"

//main Initialize
void GameMain::Initialize(StageSelect* target)
{
	m_Select = target;
	UtilityManager::GetInstance().Initialize();
	StageCreate::GetInstance().Initialize(m_Select);
	Dice::GetInstance().Initialize();
	goal.Initialize();

	CSoundManager::GetInstance().Load();
	CSoundManager::GetInstance().Play(SOUND_ID::GAMEMAIN, true);
	//ste_BGM_Initialize();
}

//overroad Initialize
void GameMain::Initialize(void)
{
	UtilityManager::GetInstance().Initialize();
	StageCreate::GetInstance().Initialize(m_Select);
	Dice::GetInstance().Initialize();
	goal.Initialize();

	CSoundManager::GetInstance().Play(SOUND_ID::GAMEMAIN, true);
}

void GameMain::Update(void)
{
	if (Dice::GetInstance().GoalFlag() && Dice::GetInstance().KeyFlag())
	{
		goal.Update();
		CSoundManager::GetInstance().StopSound(SOUND_ID::GAMEMAIN);
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
			CSoundManager::GetInstance().Play(SOUND_ID::RETRY);
		}

		//タイトルへ
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::T))
		{
			this->Finalize();
			CSoundManager::GetInstance().Play(SOUND_ID::CANCEL);
			CreateScene(GameScene_ID::TITLE);
	}
	}
}

void GameMain::Draw(void)
{
	vivid::DrawTexture("data/gamemain_utility/back.png", { 0.0f,0.0f });
	vivid::DrawTexture("data/gamemain_utility/stage_frame.png", { m_stage_frame_pos.x, m_stage_frame_pos.y});
	UtilityManager::GetInstance().Draw();
	StageCreate::GetInstance().Draw();
	Dice::GetInstance().Draw();

	//これより前に書く
 	goal.Draw();

#ifdef VIVID_DEBUG
	vivid::DrawText(32, "ゲームメイン", { 0.0f,0.0f });
	vivid::DrawText(60, "Rでリセット", { 1000.0f,0.0f });
	vivid::DrawText(60, "Tでタイトル", { 1000.0f,70.0f });
	vivid::DrawText(60, "移動回数", { 1000.0f,150.0f });
#endif //VIVID_DEBUG

}

void GameMain::Finalize(void)
{
	StageCreate::GetInstance().Finalize();
	UtilityManager::GetInstance().Finalize();
	CSoundManager::GetInstance().StopSound(SOUND_ID::GAMEMAIN);
	goal.Finalize();
}

