#pragma once
#include "vivid.h"

/*
* サイコロを振って、ランダムな数値を返す。
*/
class Dice
{
private:
	int DiceDigit;
	int BlastCount;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);

	/*
	* @return int １～６までの間で数値を返す。
	*/
	int GetDiceDigit(void);
};