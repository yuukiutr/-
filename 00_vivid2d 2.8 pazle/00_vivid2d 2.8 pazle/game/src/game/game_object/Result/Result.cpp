#include "Result.h"
#include "../gamescene_manager/gamescene_manager.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"
#include "../TextManager/TextManager.h"

void Result::Initialize(GameMain* main, StageSelect* target)
{

}

void Result::Update(void)
{
	
}

void Result::Draw(void)
{

}

void Result::Finalize(void)
{
	//データセーブ
	TEXTMANAGER.DeleteTextData("data/memo.txt");
	for (int  i = 0; i < 26; i++)
	{

		//TEXTMANAGER.SaveAndCreate(SAVE_ID::PS, "data/memo.txt", std::to_string(GetStarCount((STAGE_ID)i)));
	}

}
