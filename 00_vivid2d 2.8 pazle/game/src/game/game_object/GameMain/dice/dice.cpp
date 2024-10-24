#include "dice.h"


void Dice::Initialize(void)
{
    m_DiceDigit = 1;//���u��
    m_Position = { 200.0f,200.0f };//�X�^�[�g�}�X�̈ʒu���Q��
    rect={0, 0, m_dice_width, m_dice_height};
}

void Dice::Update(void)
{
    /*
    * �܂��ʒu���ړ������邾��
    * �o�ڂ�ς��āA�����o�ڂł��T�C�R���̌����ɂ���Ď��̏o�ڂ��ς�鏈����ǉ����Ȃ��Ƃ����Ȃ�
    * 
    * ��F�����Ă�����ɂ����1�`4�̔ԍ��t�������āA�ꍇ�����Ŏ��̏o�ڂ�ς�����@
    * �����̏o�ڂ̌����ԍ��͂ǂ�����Ĕ��肷��H
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
