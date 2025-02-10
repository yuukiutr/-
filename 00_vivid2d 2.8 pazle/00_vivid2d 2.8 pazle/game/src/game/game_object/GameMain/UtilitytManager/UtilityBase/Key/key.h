#pragma 

#include "../UtilityBase.h"

class Key : public UtilityBase
{
private:

	

public:
	void Initialize(vivid::Vector2 position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	UTILITY_ID GetUtilityID(void)override;
};