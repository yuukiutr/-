#include "dice.h"
#include "../StageCreate/StageCreate.h"
/*���𗧂����
* 1 left 0   right 63
* 2      64        178
* 3      128       191
* 4      192       255
* 5      256       319
* 6      320       383
* 
* �}�b�v�傫��
* ���64�~12��768
* ���܂̂Ƃ���̈ʒu
* x,y:200�`968
*/


/*
*  @brief	�_�C�X�̖ڂ��Ǘ�����\����
*/
struct DICE
{
    int top,
        right,
        bottom,
        left,
        center,		//���݂̃_�C�X�̏o�ځI�I�I�I�I�I�I�I
        back;
};

DICE m_Dice = { 2, 3, 5, 4, 1, 6 };

void Dice::Initialize(void)
{
    m_DiceDigit = 1;//���u��
    m_Position = STAGE.StartPosition();//�X�^�[�g�}�X�̈ʒu���Q��
    rect={0, 0, m_dice_width, m_dice_height};
}

void Dice::Update(void)
{
    int x = (int)((m_Position.x - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    int y = (int)((m_Position.y - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());

    int work = NULL;//����ւ���̂ɕK�v

    //��ɓ]����
    if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::W) && m_Position.y >= 264.0f && STAGE.CheckWall(x, y - 1) != true)
    {
        m_Position.y -= 64.0f;
        work = m_Dice.top;
        m_Dice.top = m_Dice.center;
        m_Dice.center = m_Dice.bottom;
        m_Dice.bottom = m_Dice.back;
        m_Dice.back = work;
    }
    //���ɓ]����
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::A) && m_Position.x >= 264.0f && STAGE.CheckWall(x - 1, y) != true)
    {
        m_Position.x -= 64.0f;
        work = m_Dice.center;
        m_Dice.center = m_Dice.right;
        m_Dice.right = m_Dice.back;
        m_Dice.back = m_Dice.left;
        m_Dice.left = work;
    }
    //���ɓ]����
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::S) && m_Position.y < m_map_height + 136.0f && STAGE.CheckWall(x, y + 1) != true)
    {
        m_Position.y += 64.0f;
        work = m_Dice.top;
        m_Dice.top = m_Dice.back;
        m_Dice.back = m_Dice.bottom;
        m_Dice.bottom = m_Dice.center;
        m_Dice.center = work;
    }
    //�E�ɓ]����
    else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::D) && m_Position.x < m_map_width + 136.0f && STAGE.CheckWall(x + 1, y) != true)
    {
        m_Position.x += 64.0f;
        work = m_Dice.center;
        m_Dice.center = m_Dice.left;
        m_Dice.left = m_Dice.back;
        m_Dice.back = m_Dice.right;
        m_Dice.right = work;
    }
    //�`��ʒu
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

int Dice::GetDiceWidth(void)
{
    return m_dice_width;
}

int Dice::GetDiceHeight(void)
{
    return m_dice_height;
}

Blast Dice::BlastSpot(int x, int y)
{
	bool blast_flg = false;
	m_BlastPosition = m_Position;

	switch (m_Dice.center)
	{
	case 1:
		if (m_Position.x >= 200.0f &&
			m_Position.x < 968.0f &&
			m_Position.y + 64 * y >= 200.0f &&
			m_Position.y + 64 * y < 968.0f)
		{
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_flg = true;
		}
		break;
	case 2:
		if (m_Position.x + 64 * x >= 200.0f &&
			m_Position.x + 64 * x < 968.0f &&
			m_Position.y >= 200.0f &&
			m_Position.y < 968.0f)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			blast_flg = true;
		}
		break;
	case 3:
		if (m_Position.x + 64 * x >= 200.0f &&
			m_Position.x + 64 * x < 968.0f &&
			m_Position.y + 64 * y >= 200.0f &&
			m_Position.y + 64 * y < 968.0f)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_flg = true;
		}
		break;
	case 4:
		if (m_Position.x + 64 * x >= 200.0f &&
			m_Position.x + 64 * x < 968.0f &&
			m_Position.y + 64 * y >= 200.0f &&
			m_Position.y + 64 * y < 968.0f)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_flg = true;
		}
		break;
	case 5:
		if (m_Position.x + 64 * x >= 200.0f &&
			m_Position.x + 64 * x < 968.0f &&
			m_Position.y + 64 * y >= 200.0f &&
			m_Position.y + 64 * y < 968.0f)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_flg = true;
		}
		break;
	case 6:
		if (m_Position.x + 64 * x >= 200.0f &&
			m_Position.x + 64 * x < 968.0f &&
			m_Position.y + 64 * y >= 200.0f &&
			m_Position.y + 64 * y < 968.0f)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_flg = true;
		}
		break;
	default:
		break;
	}

	return {blast_flg, m_BlastPosition };

}

vivid::Vector2 Dice::GetDicePosition(void)
{
    return m_Position;
}
