#include "dice.h"

/*お役立ち情報
* 1 left 0   right 63
* 2      64        178
* 3      128       191
* 4      192       255
* 5      256       319
* 6      320       383
* 
* マップ大きさ
* 一辺64×12＝768
*/

struct DICE
{
    int top,
        right,
        bottom,
        left,
        center,
        back;
};

DICE m_Dice = { 2, 3, 5, 4, 1, 6 };

void Dice::Initialize(void)
{
    m_DiceDigit = 1;//仮置き
    m_DiceDirection = 1;
    m_Position = { 200.0f,200.0f };//スタートマスの位置を参照
    rect={0, 0, m_dice_width, m_dice_height};
}

void Dice::Update(void)
{
    int work = NULL;//入れ替えるのに必要

    if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W) && m_Position.y >= 264.0f)
    {
        m_Position.y -= 64.0f;
        work = m_Dice.top;
        m_Dice.top = m_Dice.center;
        m_Dice.center = m_Dice.bottom;
        m_Dice.bottom = m_Dice.back;
        m_Dice.back = work;
    }
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A) && m_Position.x >= 264.0f)
    {
        m_Position.x -= 64.0f;
        work = m_Dice.center;
        m_Dice.center = m_Dice.right;
        m_Dice.right = m_Dice.back;
        m_Dice.back = m_Dice.left;
        m_Dice.left = work;
    }
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S) && m_Position.y < m_map_height + 136.0f)
    {
        m_Position.y += 64.0f;
        work = m_Dice.top;
        m_Dice.top = m_Dice.back;
        m_Dice.back = m_Dice.bottom;
        m_Dice.bottom = m_Dice.center;
        m_Dice.center = work;
    }
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D) && m_Position.x < m_map_width + 136.0f)
    {
        m_Position.x += 64.0f;
        work = m_Dice.center;
        m_Dice.center = m_Dice.left;
        m_Dice.left = m_Dice.back;
        m_Dice.back = m_Dice.right;
        m_Dice.right = work;
    }
    rect.left = m_dice_width * (m_Dice.center - 1);
    rect.right = m_dice_width * m_Dice.center;
}

void Dice::Draw(void)
{
    vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);
    vivid::DrawText(40, std::to_string(m_Dice.center), { 0.0f,100.0f });
}

int Dice::GetDiceDigit(void)
{
    return m_Dice.center;
}
