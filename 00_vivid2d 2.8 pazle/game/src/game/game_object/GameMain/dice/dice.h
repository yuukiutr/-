#pragma once
#include "vivid.h"

/*
* �T�C�R����U���āA�����_���Ȑ��l��Ԃ��B
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
	* @return int �P�`�U�܂ł̊ԂŐ��l��Ԃ��B
	*/
	int GetDiceDigit(void);
};