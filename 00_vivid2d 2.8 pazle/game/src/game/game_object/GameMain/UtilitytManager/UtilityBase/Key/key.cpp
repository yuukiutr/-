#include "key.h"
#include "../../../dice/dice.h"

const std::string Key::m_Utility_Data = "data\\gamemain_utility\\key.png";
const bool Key::m_UtilityFlag = false;

void Key::Update(void)
{

}

UTILITY_ID Key::GetUtilityID(void)
{
	return UTILITY_ID::KEY;
}
