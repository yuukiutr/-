#include "goal.h"
#include <cmath>
#include "../../gamescene_manager/gamescene_manager.h"
#include "../StageCreate/StageCreate.h"
#include "../dice/dice.h"
#include "../UtilitytManager/UtilityBase/Key/key.h"
#include "../../../game_object/sound_manager/sound_manager.h"


Goal::Goal()
{
}

void Goal::Initialize(void)
{
	CSoundManager::GetInstance().Load();
	m_ChangeSceneCount = 0;
	m_goal_size = { 607.0f,231.0f };
	m_GoalSound = true;
}

void Goal::Update()
{
	m_ChangeSceneCount++;

	//ゴールサウンド
	if(m_GoalSound)
	{
	CSoundManager::GetInstance().Play(SOUND_ID::GOAL);
	m_GoalSound = false;
	}

	if (m_ChangeSceneCount >= 180)
	{
	//リザルトへ
	CreateScene(GameScene_ID::RESULT);
	}
}

void Goal::Draw(void)
{
	//GOALの文字
	if (!m_GoalSound)
		vivid::DrawTexture("data\\gamemain_utility\\goal.png", 
			{ (vivid::WINDOW_WIDTH - m_goal_size.x) / 2,
			  (vivid::WINDOW_HEIGHT - m_goal_size.y) / 2});
}

void Goal::Finalize(void)
{
}
