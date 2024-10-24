#include "dice.h"


void Dice::Initialize(void)
{
    m_DiceDigit = 1;//仮置き
    m_Position = { 200.0f,200.0f };//スタートマスの位置を参照
    rect={0, 0, m_dice_width, m_dice_height};
}

void Dice::Update(void)
{
    /*
    * まだ位置を移動させるだけ
    * 出目を変えて、同じ出目でもサイコロの向きによって次の出目が変わる処理を追加しないといけない
    * 
    * 例：向いてる方向によって1～4の番号付けをして、場合分けで次の出目を変える方法
    * ↑次の出目の向き番号はどうやって判定する？
    */
    if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W))
    {
        m_Position.y -= 64.0f;
    } 
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A))
    {
        m_Position.x -= 64.0f;
    }
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S))
    {
        m_Position.y += 64.0f;
    }
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D))
    {
        m_Position.x += 64.0f;
    }
}

void Dice::Draw(void)
{
    vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);
}

int Dice::GetDiceDigit(void)
{
    return 6;
}
