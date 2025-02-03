#pragma 

#include "../UtilityBase.h"

class Key : public UtilityBase
{
private:
	int m_KeyCount;			//�J�M���J�E���g
	int m_MaxKey;			//�ő�J�M��
	bool m_KeyClearFlag;	//�J�M�������B���t���O

public:
	void Initialize(vivid::Vector2 position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	bool GetKeyClearFlag(void);

	UTILITY_ID GetUtilityID(void)override;
};