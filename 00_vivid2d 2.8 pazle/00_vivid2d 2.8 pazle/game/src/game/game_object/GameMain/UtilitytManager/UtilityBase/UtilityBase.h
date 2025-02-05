#pragma once
#include "vivid.h"
#include "../Utility_ID.h"

class Dice;

class UtilityBase
{
protected:
	Dice* m_Dice;

	vivid::Vector2 m_UtilityPosition;
	static const int m_utility_width;
	static const int m_utility_height;
	unsigned int m_UtilityColor;
	static const bool m_UtilityFlag;

public:
	//������
	virtual void Initialize(vivid::Vector2 pos);

	//�X�V
	virtual void Update(void);

	//�`��
	virtual void Draw(void);

	//���
	virtual void Finalize(void);

	//Utility�Ƃ̓����蔻��
	virtual bool GetCollisionFlag(void);

	//Utility�̈ʒu�̎擾
	virtual vivid::Vector2 GetPosition(void);

	//�������ꂽUtility��ID
	virtual UTILITY_ID GetUtilityID(void);

	virtual bool GetKeyClearFlag(void);

	bool GetUtilityFlag(void);
};