#pragma once
#include "../UtilityBase.h"

class BreakableWall : public UtilityBase
{
private:

public:

	void Update(void)override;
	void Draw(void)override;

	UTILITY_ID GetUtilityID(void)override;
};