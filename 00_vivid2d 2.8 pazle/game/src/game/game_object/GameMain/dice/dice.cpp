#include "dice.h"


void Dice::Initialize(void)
{
}

void Dice::Update(void)
{
    srand((unsigned long long)GetNowHiPerformanceCount(NULL));

}

void Dice::Draw(void)
{
    
}

int Dice::GetDiceDigit(void)
{
    return 6;
}
