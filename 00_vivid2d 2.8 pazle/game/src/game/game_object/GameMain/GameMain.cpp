#include "GameMain.h"
#include "../StageSelect/StageSelect.h"
#include "effectmanager/effectmanager.h"


//main Initialize
void GameMain::Initialize(StageSelect* target)
{
	m_Select = target;
	m_Timer = 0;
	m_ResetCount = 0;
	m_GameOverCount = 0;
	m_create.Initialize(m_Select);
	EffectManager::CreateInstance();
	EFFECT.Initialize();
	character.Initialize();
	EnemyManager::GetInstance().Initialize(&character);
	goal.Initialize();
	//ste_BGM_Initialize();
}

//overroad Initialize
void GameMain::Initialize(void)
{
	m_Timer = 0;
	m_create.Initialize(m_Select);
	EffectManager::CreateInstance();
	EFFECT.Initialize();
	character.Initialize();
	EnemyManager::GetInstance().Initialize(&character);
	goal.Initialize();
}

void GameMain::Update(void)
{
	if (!character.GetGoalFlag())
	{
		if (!character.GetLoseFlag()&&
			!EnemyManager::GetInstance().GetLoseFlag())
		{
			if (m_Timer < 2159999)
			{
				m_Timer++;
			}

			m_create.Update();
			character.Update();
			EnemyManager::GetInstance().Update();
			EFFECT.Update();

			if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
				||vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::START)
				&&vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::X))
			{
				m_ResetCount++;
				this->Finalize();
				this->Initialize();
			}

		}
		else
		{
			//GAME OVER
			if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
				||vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
			{
				m_GameOverCount++;
				this->Finalize();
				this->Initialize();

			}
		}

	}
	else
	{

		goal.Update();
	}

}

void GameMain::Draw(void)
{
	vivid::DrawTexture("data/back.png", { 0.0f,0.0f });
	m_create.Draw();
	EFFECT.Draw();
	character.Draw();
	EnemyManager::GetInstance().Draw();

	//‚±‚ê‚æ‚è‘O‚É‘‚­
	goal.Draw();

#ifdef VIVID_DEBUG
	vivid::DrawText(32, "ƒQ[ƒ€ƒƒCƒ“", { 0.0f,0.0f });

	character.CHARACTER_DEBUG_DRAW_DATA();
	this->GAMEMAIN_DEBUG_DRAW_DATA();
#endif //VIVID_DEBUG

}

void GameMain::Finalize(void)
{
	m_create.Finalize();
	character.Finalize();
	EnemyManager::GetInstance().Finalize();
	goal.Finalize();
	EFFECT.Finalize();
	EffectManager::DeleteInstance();
}

int GameMain::GetTimer(void)
{
	return m_Timer;
}

int GameMain::GetResetCount(void)
{
	return m_ResetCount;
}

int GameMain::GetGameOverCount(void)
{
	return m_GameOverCount;
}

void GameMain::GAMEMAIN_DEBUG_DRAW_DATA(void)
{
#ifdef VIVID_DEBUG

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPAD3))
	{
		vivid::DrawText(30, "TM:" + std::to_string(m_Timer), { 0.0f,330.0f }, 0xff00ff00);
		vivid::DrawText(30, "RC:" + std::to_string(m_ResetCount), { 0.0f,360.0f }, 0xff00ff00);
		vivid::DrawText(30, "DC:" + std::to_string(m_GameOverCount), { 0.0f,390.0f }, 0xff00ff00);
		switch (m_Select->GetNowStageID())
		{
		case STAGE_ID::STAGE1:
			vivid::DrawText(30, "SS:STAGE1", { 0.0f,420.0f }, 0xff00ff00);
			break;
		case STAGE_ID::STAGE2:
			vivid::DrawText(30, "SS:STAGE2", { 0.0f,420.0f }, 0xff00ff00);
			break;
		case STAGE_ID::STAGE3:
			vivid::DrawText(30, "SS:STAGE3", { 0.0f,420.0f }, 0xff00ff00);
			break;
		case STAGE_ID::STAGE4:
			vivid::DrawText(30, "SS:STAGE4", { 0.0f,420.0f }, 0xff00ff00);
			break;
		case STAGE_ID::STAGE5:
			vivid::DrawText(30, "SS:STAGE5", { 0.0f,420.0f }, 0xff00ff00);
			break;
		case STAGE_ID::STAGE6:
			vivid::DrawText(30, "SS:STAGE6", { 0.0f,420.0f }, 0xff00ff00);
			break;
		default:
			break;
		}
		vivid::DrawText(30, "RD:" + std::to_string(rand() % 65536), {0.0f,450.0f}, 0xff00ff00);

	}
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::ADD))
	{
		vivid::DrawText(30, "DEBUG COMMAND", { 0.0f,510.0f }, 0xff00ff00);
	}

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::SUBTRACT))
	{
		vivid::DrawText(30, "Varsion : bata.10.0", {(float)vivid::WINDOW_WIDTH / 2.0f,0.0f}, 0xff00ff00);
		vivid::DrawText(30, "WINDOWSIZE X:" + std::to_string(vivid::WINDOW_WIDTH), { (float)vivid::WINDOW_WIDTH / 2.0f,30.0f }, 0xff00ff00);
		vivid::DrawText(30, "WINDOWSIZE Y:" + std::to_string(vivid::WINDOW_HEIGHT), { (float)vivid::WINDOW_WIDTH / 2.0f,60.0f }, 0xff00ff00);
		vivid::DrawText(30, "DeltaTime:" + std::to_string(vivid::GetDeltaTime()), { (float)vivid::WINDOW_WIDTH / 2.0f,90.0f }, 0xff00ff00);
	}

#endif //VIVID_DEBUG

}
