#include "game.h"
#include "game_obj/gamescene_manager/gamescene_manager.h"
#include "vivid.h"

GameSceneManager gamescenemanager;

void Game::Initialize(void)
{
	gamescenemanager.Initialize();
}

void Game::Update(void)
{
	gamescenemanager.Update();

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::LCONTROL)
		&& vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
		|| vivid::keyboard::Button(vivid::keyboard::KEY_ID::RCONTROL)
		&& vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::R)
		|| vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::A)
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
}
