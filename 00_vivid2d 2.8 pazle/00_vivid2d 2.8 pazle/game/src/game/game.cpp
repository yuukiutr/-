#include "game.h"
#include "game_object/GameMain/dice/dice.h"
#include "game_object/gamescene_manager/gamescene_manager.h"
#include "vivid.h"
#include "game_object/TextManager/TextManager.h"
#include "game_object/sound_manager/sound_manager.h"

GameSceneManager gamescenemanager;

void Game::Initialize(void)
{
	//サウンドマネージャー取得
	CSoundManager& sound = CSoundManager::GetInstance();

	//サウンド読み込み
	sound.Load();

	//BGM再生
	sound.Play(SOUND_ID::TITLE, true);

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
