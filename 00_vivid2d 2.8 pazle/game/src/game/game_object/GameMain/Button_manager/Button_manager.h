#pragma once

#include "vivid.h"
#include "Button_id.h"
#include "../character/character.h"
#include <functional>
#include <map>
#include <list>

class Button;
class Character;

class ButtonManager
{
private:
	ButtonManager(void) = default;
	~ButtonManager(void) = default;
	ButtonManager(const ButtonManager& rhs) = delete;
	ButtonManager(const ButtonManager&& rhs) = delete;
	ButtonManager& operator=(const ButtonManager& rhs) = delete;

	Character* m_character;


public:


	static ButtonManager& GetInstance(void);
	void Initialize(Character* character);
	void Updata(void);
	void Draw(void);
	void Finalize(void);
	bool GetLundingFlag(void);
	bool GetOnFlag(void);

};