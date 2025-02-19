#include "game.h"
#include "game_object/GameMain/dice/dice.h"
#include "game_object/gamescene_manager/gamescene_manager.h"
#include "vivid.h"
#include "game_object/TextManager/TextManager.h"
#include "game_object/sound_manager/sound_manager.h"

GameSceneManager gamescenemanager;

void Game::Initialize(void)
{
	//�T�E���h�}�l�[�W���[�擾
	CSoundManager& sound = CSoundManager::GetInstance();

	//�T�E���h�ǂݍ���
	sound.Load();

	//BGM�Đ�
	sound.Play(SOUND_ID::TITLE, true);

	Dice::CreateInstance();
	gamescenemanager.Initialize();

}

void Game::Update(void)
{
	gamescenemanager.Update();
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
