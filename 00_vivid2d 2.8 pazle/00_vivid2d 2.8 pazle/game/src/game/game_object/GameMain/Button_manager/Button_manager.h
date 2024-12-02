#pragma once

#include "vivid.h"
#include "Button_id.h"
#include <functional>
#include <map>
#include <list>

class Button;
class Dice;

class ButtonManager
{
private:
	ButtonManager(void) = default;
	~ButtonManager(void) = default;
	ButtonManager(const ButtonManager& rhs) = delete;
	ButtonManager(const ButtonManager&& rhs) = delete;
	ButtonManager& operator=(const ButtonManager& rhs) = delete;

	Dice* m_Dice;

public:


	static ButtonManager& GetInstance(void);
	void Initialize(Dice* dice);
	void Updata(void);
	void Draw(void);
	void Finalize(void);
	bool GetLundingFlag(void);
	bool GetOnFlag(void);

};