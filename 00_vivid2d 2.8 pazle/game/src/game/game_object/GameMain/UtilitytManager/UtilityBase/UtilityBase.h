#pragma once
#include "vivid.h"
#include "../Utility_ID.h"

class StageCreate;

class UtilityBase
{
protected:
	StageCreate* m_Stage;
	vivid::Vector2 m_UtilityPosition;
	static const int m_utility_width;
	static const int m_utility_height;
	unsigned int m_UtilityColor;

	static const std::string m_Utility_Data;

public:
	//‰Šú‰»
	virtual void Initialize(StageCreate* stage, vivid::Vector2 pos);

	//XV
	virtual void Update(void);

	//•`‰æ
	virtual void Draw(void);

	//‰ğ•ú
	virtual void Finalize(void);

	//BOX‚Æ‚Ì“–‚½‚è”»’è
	virtual vivid::Vector2 UtilityCollision(vivid::Vector2 vec2, int width, int height);

	//BOX‚ÌˆÊ’u‚Ìæ“¾
	virtual vivid::Vector2 GetPosition(void);

	//¶¬‚³‚ê‚½BOX‚ÌID
	virtual UTILITY_ID GetUtilityID(void);
};