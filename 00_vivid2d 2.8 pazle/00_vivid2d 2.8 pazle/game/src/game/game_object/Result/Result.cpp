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

	//ベスト記録の読み込み
	TEXTMANAGER.DeleteLoadData();
	TEXTMANAGER.Load(LOAD_ID::ONLY_NUMERIC, "data/BestRecord.txt");
	std::vector<std::string> vec = TEXTMANAGER.GetLoadData();
	m_LoadDiceMove = stoi(vec[0]);

	m_NewRecordFlag = false;

	CSoundManager::GetInstance().Load();
	CSoundManager::GetInstance().Play(SOUND_ID::RESULT, false);
}

void Result::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER))
	CreateScene(GameScene_ID::TITLE);

	//記録更新してる時
	if (m_LoadDiceMove > m_ResultDiceMove)
		m_NewRecordFlag = true;
}

void Result::Draw(void)
{
	vivid::DrawText(40, std::to_string(m_ResultDiceMove), { 0.0f,0.0f });
	vivid::DrawText(40, std::to_string(m_LoadDiceMove), { 0.0f,40.0f });

	if (m_NewRecordFlag)
		vivid::DrawText(40, "NEW RECORD!", { 0.0f,80.0f });
}

void Result::Finalize(void)
{
	//データセーブ
	if (m_ResultDiceMove < m_LoadDiceMove) {
	TEXTMANAGER.DeleteTextData("data/BestRecord.txt");
	TEXTMANAGER.SaveAndCreate(SAVE_ID::PS, "data/BestRecord.txt", std::to_string(m_ResultDiceMove));
	}
	CSoundManager::GetInstance().StopSound(SOUND_ID::RESULT);

}
