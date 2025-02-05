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
	//‰Šú‰»
	virtual void Initialize(vivid::Vector2 pos);

	//XV
	virtual void Update(void);

	//•`‰æ
	virtual void Draw(void);

	//‰ğ•ú
	virtual void Finalize(void);

	//Utility‚Æ‚Ì“–‚½‚è”»’è
	virtual bool GetCollisionFlag(void);

	//Utility‚ÌˆÊ’u‚Ìæ“¾
	virtual vivid::Vector2 GetPosition(void);

	//¶¬‚³‚ê‚½Utility‚ÌID
	virtual UTILITY_ID GetUtilityID(void);

	virtual bool GetKeyClearFlag(void);

	bool GetUtilityFlag(void);
};