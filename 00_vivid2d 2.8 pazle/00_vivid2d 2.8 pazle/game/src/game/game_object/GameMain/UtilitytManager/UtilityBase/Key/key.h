#pragma 

#include "../UtilityBase.h"

class Key : public UtilityBase
{
private:
	int m_KeyCount;			//カギ数カウント
	int m_MaxKey;			//最大カギ数
	bool m_KeyClearFlag;	//カギ数条件達成フラグ

public:
	void Initialize(vivid::Vector2 position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	bool GetKeyClearFlag(void);

	UTILITY_ID GetUtilityID(void)override;
};