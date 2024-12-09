#include "Result.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"
#include "../TextManager/TextManager.h"
#include "../GameMain/dice/dice.h"

void Result::Initialize(GameMain* main, StageSelect* target)
{
	m_ResultDiceMove = Dice::GetInstance().GetMoveCount();
	TEXTMANAGER.DeleteLoadData();
	TEXTMANAGER.Load(LOAD_ID::ONLY_NUMERIC, "data/memo.txt");
	std::vector<std::string> vec = TEXTMANAGER.GetLoadData();
	TextLoader loader;
	m_LoadDiceMove = (int)loader.to_long_double(vec[0]);
}

void Result::Update(void)
{
	
}

void Result::Draw(void)
{
	vivid::DrawText(40, std::to_string(m_ResultDiceMove), { 0.0f,0.0f });
	vivid::DrawText(40, std::to_string(m_LoadDiceMove), { 0.0f,40.0f });
}

void Result::Finalize(void)
{
	//データセーブ
	if (m_ResultDiceMove < m_LoadDiceMove) {
	TEXTMANAGER.DeleteTextData("data/memo.txt");
	TEXTMANAGER.SaveAndCreate(SAVE_ID::PS, "data/memo.txt", std::to_string(m_ResultDiceMove));
	}

}
