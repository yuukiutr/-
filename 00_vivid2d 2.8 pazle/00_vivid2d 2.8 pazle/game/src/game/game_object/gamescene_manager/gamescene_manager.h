#pragma once
#include "gamescene_id.h"

class GameSceneManager
{
public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};

void CreateScene(GameScene_ID next_scene);