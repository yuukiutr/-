#pragma once
#include "gamescene_id.h"
#include "../StageSelect/StageSelect.h"

class GameSceneManager
{
public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void SetSelectNumber(int num);
	int GetSelectNumber(void);	//どのステージかの一時保存場所

	static GameSceneManager* GetInstance(void);

private:

	static inline GameSceneManager* m_Instance;

	StageSelect* m_Select;
	int m_StageNo;
};

void CreateScene(GameScene_ID next_scene);