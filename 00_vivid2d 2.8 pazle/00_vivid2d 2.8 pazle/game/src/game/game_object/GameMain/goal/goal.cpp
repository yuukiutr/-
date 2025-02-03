#include "goal.h"
#include <cmath>
#include "../../gamescene_manager/gamescene_manager.h"
#include "../StageCreate/StageCreate.h"
#include "../dice/dice.h"
#include "../UtilitytManager/UtilityBase/Key/key.h"

Goal::Goal()
{
}

void Goal::Initialize(void)
{

}

void Goal::Update()
{
	//ƒŠƒUƒ‹ƒg‚Ö
	CreateScene(GameScene_ID::RESULT);
}

void Goal::Draw(void)
{

}

void Goal::Finalize(void)
{
}
