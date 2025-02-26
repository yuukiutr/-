#include "Result.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"
#include "../TextManager/TextManager.h"
#include "../GameMain/dice/dice.h"
#include "../sound_manager/sound_manager.h"

void Result::Initialize(GameMain* main, StageSelect* target)
{
	m_ResultDiceMove = Dice::GetInstance().GetMoveCount();

	m_StageNo = 0;
	//ベスト記録の読み込み
	TEXTMANAGER.DeleteLoadData();
	switch (GameSceneManager::GetInstance()->GetSelectNumber())
	{
	case 0:
		TEXTMANAGER.Load(LOAD_ID::ONLY_NUMERIC, "data/BestRecordStage1.txt");
		break;
	case 1:
		TEXTMANAGER.Load(LOAD_ID::ONLY_NUMERIC, "data/BestRecordStage2.txt");
		break;
	case 2:
		TEXTMANAGER.Load(LOAD_ID::ONLY_NUMERIC, "data/BestRecordStage3.txt");
		break;
	default:
		break;
	}
	std::vector<std::string> vec = TEXTMANAGER.GetLoadData();
	m_LoadDiceMove = stoi(vec[0]);

	m_NewRecordFlag = false;

	m_move_count_size = { 648.0f, 203.0f };
	m_best_record_size = { 1138.0f, 133.0f };
	m_new_record_size = { 577.0f,108.0f };

	CSoundManager::GetInstance().Load();
	CSoundManager::GetInstance().Play(SOUND_ID::RESULT, false);
}

void Result::Update(void)
{
	m_TitleCount++;
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER) || m_TitleCount > 1800)
	CreateScene(GameScene_ID::TITLE);

	//記録更新してる時
	if (m_LoadDiceMove > m_ResultDiceMove)
		m_NewRecordFlag = true;
}

void Result::Draw(void)
{
	vivid::DrawTexture("data\\result\\result_bg.png", { 0.0f, 0.0f });

	vivid::DrawText(150, std::to_string(m_ResultDiceMove), { vivid::WINDOW_WIDTH / 2 - 100,200.0f });
	vivid::DrawText(150, std::to_string(m_LoadDiceMove), { vivid::WINDOW_WIDTH / 2 - 100,750.0f });

	vivid::DrawTexture("data\\result\\move_count.png", {(vivid::WINDOW_WIDTH - m_move_count_size.x) / 2, 0.0f});
	vivid::DrawTexture("data\\result\\best_record.png", { (vivid::WINDOW_WIDTH - m_best_record_size.x) / 2, 600.0f});

	//NEW RECORD
	if (m_NewRecordFlag)
	{
		vivid::DrawTexture("data\\result\\new_record.png", { (vivid::WINDOW_WIDTH - m_new_record_size.x) / 2,350.0f });
	}
}

void Result::Finalize(void)
{
	//データセーブ
	if (m_ResultDiceMove < m_LoadDiceMove) {
		switch (GameSceneManager::GetInstance()->GetSelectNumber())
		{
		case 0:
			TEXTMANAGER.SaveAndCreate(SAVE_ID::OVERWRITING, "data/BestRecordStage1.txt", std::to_string(m_ResultDiceMove));
			break;
		case 1:
			TEXTMANAGER.SaveAndCreate(SAVE_ID::OVERWRITING, "data/BestRecordStage2.txt", std::to_string(m_ResultDiceMove));
			break;
		case 2:
			TEXTMANAGER.SaveAndCreate(SAVE_ID::OVERWRITING, "data/BestRecordStage3.txt", std::to_string(m_ResultDiceMove));
			break;
		default:
			break;
		}
	}
	CSoundManager::GetInstance().StopSound(SOUND_ID::RESULT);

}
