#pragma once
#include "vivid.h"

class Character;
class StageCreate;

class Goal
{
private:
	vivid::Vector2 m_DicePosition;

public:
	Goal();
	void Initialize(void);
	void Update();
	void Draw(void);
	void Finalize(void);

};