#include "gamescene_manager.h"
#include "../GameMain/GameMain.h"
#include "../Title/Title.h"
#include "../StageSelect/StageSelect.h"
#include "../Result/Result.h"
#include "../credit/credit.h"

//credit��S��option�ɂ���(���Ƃ�)

GameMain gamemain;
Title title;
StageSelect stageselect;
Result result;
CREDIT credit;

GameScene_ID gamescene_id = GameScene_ID::DUMMY;

void CreateScene(GameScene_ID next_scene)
{
	if (next_scene == gamescene_id)
	{
		return;
	}
	else
	{
		switch (gamescene_id)
		{
		case GameScene_ID::MAIN:
			gamemain.Finalize();
			break;
		case GameScene_ID::TITLE:
			title.Finalize();
			break;
		case GameScene_ID::STAGESELECT:
			stageselect.Finalize();
			break;
		case GameScene_ID::OPTION:
			credit.Finalize();
			break;
		case GameScene_ID::RESULT:
			result.Finalize();
			break;
		default:
			break;
		}

		gamescene_id = next_scene;

		
		switch (gamescene_id)
		{
		case GameScene_ID::MAIN:
			gamemain.Initialize(&stageselect);
			break;
		case GameScene_ID::TITLE:
			title.Initialize();
			break;
		case GameScene_ID::STAGESELECT:
			stageselect.Initialize();
			break;
		case GameScene_ID::RESULT:
			result.Initialize(&gamemain, &stageselect);
			break;
		case GameScene_ID::OPTION:
			credit.Initialize();
			break;

		default:
			break;
		}
	}


}

void GameSceneManager::Initialize(void)
{
	CreateScene(GameScene_ID::TITLE);
}

void GameSceneManager::Update(void)
{
	switch (gamescene_id)
	{
	case GameScene_ID::MAIN:
		gamemain.Update();
		break;
	case GameScene_ID::TITLE:
		title.Update();
		break;
	case GameScene_ID::STAGESELECT:
		stageselect.Update();
		break;
	case GameScene_ID::RESULT:
		result.Update();
		break;
	case GameScene_ID::OPTION:
		credit.Update();
		break;

	default:
		break;
	}
}

void GameSceneManager::Draw(void)
{
	switch (gamescene_id)
	{
	case GameScene_ID::MAIN:
		gamemain.Draw();
		break;
	case GameScene_ID::TITLE:
		title.Draw();
		break;
	case GameScene_ID::STAGESELECT:
		stageselect.Draw();
		break;
	case GameScene_ID::RESULT:
		result.Draw();
		break;
	case GameScene_ID::OPTION:
		credit.Draw();
		break;

	default:
		break;
	}
}

void GameSceneManager::Finalize(void)
{
	switch (gamescene_id)
	{
	case GameScene_ID::MAIN:
		gamemain.Finalize();
		break;
	case GameScene_ID::TITLE:
		title.Finalize();
		break;
	case GameScene_ID::STAGESELECT:
		stageselect.Finalize();
		break;
	case GameScene_ID::RESULT:
		result.Finalize();
		break;
	case GameScene_ID::OPTION:
		credit.Finalize();
		break;

	default:
		break;
	}
}
