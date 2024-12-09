#include "game.h"
#include "game_object/GameMain/dice/dice.h"
#include "game_object/gamescene_manager/gamescene_manager.h"
#include "vivid.h"
#include "game_object/TextManager/TextManager.h"

GameSceneManager gamescenemanager;

void Game::Initialize(void)
{
	Dice::CreateInstance();
	gamescenemanager.Initialize();
}

void Game::Update(void)
{
	gamescenemanager.Update();

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::LCONTROL)
		&& vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
		|| vivid::keyboard::Button(vivid::keyboard::KEY_ID::RCONTROL)
		&& vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
		||vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1,vivid::controller::BUTTON_ID::A)
		)
	{
		gamescenemanager.Initialize();


	}
}

void Game::Draw(void)
{
	gamescenemanager.Draw();
}

void Game::Finalize(void)
{
	gamescenemanager.Finalize();
	TEXTMANAGER.DeleteLoadData();
	Dice::DeleteInstance();
}
