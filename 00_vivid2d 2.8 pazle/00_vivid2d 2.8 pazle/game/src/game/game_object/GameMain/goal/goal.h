#pragma once
#include "vivid.h"

class Character;
class StageCreate;

class Goal
{
private:
	int m_ChangeSceneCount;
	vivid::Vector2 m_goal_size;
	bool m_GoalSound;
public:
	Goal();
	void Initialize(void);
	void Update();
	void Draw(void);
	void Finalize(void);

};