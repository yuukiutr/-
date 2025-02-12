#include "dice.h"
#include "../StageCreate/StageCreate.h"
#include "../UtilitytManager/UtilitytManager.h"
#include "../../../game_object/sound_manager/sound_manager.h"
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

void Dice::CreateInstance(void)
{
    Dice::DeleteInstance();

    m_Instance = new Dice();
}

void Dice::DeleteInstance(void)
{
    if (!m_Instance) return;

    delete m_Instance;
    m_Instance = nullptr;
}

Dice& Dice::GetInstance(void)
{
    return *m_Instance;
}

void Dice::Initialize(void)
{
    m_MoveCount = 0;
    m_DiceDigit = 1;//���u��
    m_Position = STAGE.StartPosition();//�X�^�[�g�}�X�̈ʒu���Q��
    m_Velocity = { 0.0f,0.0f };
    m_MoveCount = 0;
    rect={0, 0, m_dice_width, m_dice_height};
    m_Dice = { 2, 3, 5, 4, 1, 6 };

    for (int i = 0; i < 6; i++)
    {
        m_BlastContainer[i].x = 0.0f;
        m_BlastContainer[i].y = 0.0f;
    }

    m_KeyCount = 0;
    m_MaxKey = 3;
    m_KeyClearFlag = false;

    CSoundManager::GetInstance().Load();
}

void Dice::Update(void)
{
    //�J�M�擾��+1
    if (UtilityManager::GetInstance().GetKeyDeleteFlag())
    {
        m_KeyCount++;
        UtilityManager::GetInstance().SetKeyDeleteFlag(false);
    }

    //�J�M�S���
    if (m_MaxKey <= m_KeyCount)
        m_KeyClearFlag = true;

    namespace keyboard = vivid::keyboard;
    
    int x = (int)((m_Position.x - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    int y = (int)((m_Position.y - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());

    m_Velocity.x = 0.0f;
    m_Velocity.y = 0.0f;

    int work = NULL;//����ւ���̂ɕK�v

    //���j

    if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::NUMPADENTER))
    {
        for (int i = 0; i < 6; i++)
        {
            UtilityManager::GetInstance().Blast(m_BlastContainer[i]);
        }
    }

    //
    //  �ړ�
    //
    //��ɓ]����
    if (keyboard::Trigger(keyboard::KEY_ID::W) &&
        m_Position.y >= 264.0f &&
        !STAGE.CheckWall(x, y - 1))
    {
        m_Velocity.y -= 64.0f;
        if (!UtilityManager::GetInstance().Collision())
        {
            work = m_Dice.top;
            m_Dice.top = m_Dice.center;
            m_Dice.center = m_Dice.bottom;
            m_Dice.bottom = m_Dice.back;
            m_Dice.back = work;
            m_MoveCount++;

            CSoundManager::GetInstance().Play(SOUND_ID::DICE_MOVE);
        }
        else m_Velocity.y = 0.0f;

    }
    //���ɓ]����
    else if (keyboard::Trigger(keyboard::KEY_ID::A) &&
        m_Position.x >= 264.0f &&
        !STAGE.CheckWall(x - 1, y))
    {
        m_Velocity.x -= 64.0f;
        if (!UtilityManager::GetInstance().Collision())
        {
            work = m_Dice.center;
            m_Dice.center = m_Dice.right;
            m_Dice.right = m_Dice.back;
            m_Dice.back = m_Dice.left;
            m_Dice.left = work;
            m_MoveCount++;

            CSoundManager::GetInstance().Play(SOUND_ID::DICE_MOVE);
        }
        else m_Velocity.x = 0.0f;

    }
    //���ɓ]����
    else if (keyboard::Trigger(keyboard::KEY_ID::S) &&
        m_Position.y < m_map_height + 136.0f &&
        !STAGE.CheckWall(x, y + 1))
    {
        m_Velocity.y += 64.0f;
        if (!UtilityManager::GetInstance().Collision())
        {
            work = m_Dice.top;
            m_Dice.top = m_Dice.back;
            m_Dice.back = m_Dice.bottom;
            m_Dice.bottom = m_Dice.center;
            m_Dice.center = work;
            m_MoveCount++;

            CSoundManager::GetInstance().Play(SOUND_ID::DICE_MOVE);
        }
        else m_Velocity.y = 0.0f;

    }
    //�E�ɓ]����
    else if (keyboard::Trigger(keyboard::KEY_ID::D) &&
        m_Position.x < m_map_width + 136.0f &&
        !STAGE.CheckWall(x + 1, y))
    {
        m_Velocity.x += 64.0f;
        if (!UtilityManager::GetInstance().Collision())
        {
            work = m_Dice.center;
            m_Dice.center = m_Dice.left;
            m_Dice.left = m_Dice.back;
            m_Dice.back = m_Dice.right;
            m_Dice.right = work;
            m_MoveCount++;

            CSoundManager::GetInstance().Play(SOUND_ID::DICE_MOVE);
        }
        else m_Velocity.x = 0.0f;
    }
    else
    {
        m_Velocity.x = 0.0f;
        m_Velocity.y = 0.0f;
    }


    m_Position += m_Velocity;
    //�`��ʒu
    rect.left = m_dice_width * (m_Dice.center - 1);
    rect.right = m_dice_width * m_Dice.center;

    if (keyboard::Button(keyboard::KEY_ID::R))
        m_MoveCount = 0;
}

void Dice::Draw(void)
{

    vivid::DrawTexture("data\\gamemain_utility\\dice.png", m_Position, 0xffffffff, rect);
    vivid::DrawText(40, std::to_string(m_Dice.center), { 0.0f,100.0f });
    vivid::DrawText(40, std::to_string(m_KeyCount), { 0.0f,40.0f });

#ifdef VIVID_DEBUG
    int id = 0;
    int x = (int)((m_Position.x - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    int y = (int)((m_Position.y - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    if (STAGE.GetMapChipID(x, y) == MAP_CHIP_ID::BLASTWALL)
        id = 3;

    vivid::DrawText(40,std::to_string(id),{ 0.0f, 200.0f });
    vivid::DrawText(40, std::to_string(m_MoveCount), { 0.0f,150.0f });
#endif // VIVID_DEBUG

}

//�_�C�X�̏o��
int Dice::GetDiceDigit(void)
{
    return m_Dice.center;
}

//�_�C�X�̕�
int Dice::GetDiceWidth(void)
{
    return m_dice_width;
}

//�_�C�X�̍���
int Dice::GetDiceHeight(void)
{
    return m_dice_height;
}

//��������
int Dice::GetMoveCount(void)
{
    return m_MoveCount;
}

vivid::Vector2 Dice::GetVelocity(void)
{
    return m_Velocity;
}

Blast Dice::BlastSpot(int x, int y)
{
	bool blast_range_flg = false;
	m_BlastPosition = m_Position;

	switch (m_Dice.center)
	{
	case 1:
		if (m_Position.x >= m_map_position.x &&
			m_Position.x < m_map_position.x + m_map_width &&
			m_Position.y + 64 * y >= m_map_position.y &&
			m_Position.y + 64 * y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_range_flg = true;
		}
		break;
	case 2:
		if (m_Position.x + 64 * x >= m_map_position.x &&
			m_Position.x + 64 * x < m_map_position.x + m_map_width &&
			m_Position.y >= m_map_position.y &&
			m_Position.y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			blast_range_flg = true;
		}
		break;
	case 3:
		if (m_Position.x + 64 * x >= m_map_position.x &&
			m_Position.x + 64 * x < m_map_position.x + m_map_width&&
			m_Position.y + 64 * y >= m_map_position.y &&
			m_Position.y + 64 * y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_range_flg = true;
		}
		break;
	case 4:
		if (m_Position.x + 64 * x >= m_map_position.x &&
			m_Position.x + 64 * x < m_map_position.x + m_map_width&&
			m_Position.y + 64 * y >= m_map_position.y &&
			m_Position.y + 64 * y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_range_flg = true;
		}
		break;
	case 5:
		if (m_Position.x + 64 * x >= m_map_position.x &&
			m_Position.x + 64 * x < m_map_position.x + m_map_width&&
			m_Position.y + 64 * y >= m_map_position.y &&
			m_Position.y + 64 * y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_range_flg = true;
		}
		break;
	case 6:
		if (m_Position.x + 64 * x >= m_map_position.x &&
			m_Position.x + 64 * x < m_map_position.x + m_map_width&&
			m_Position.y + 64 * y >= m_map_position.y &&
			m_Position.y + 64 * y < m_map_position.y + m_map_height)
		{
			m_BlastPosition.x = m_Position.x + 64 * x;
			m_BlastPosition.y = m_Position.y + 64 * y;
			blast_range_flg = true;
		}
		break;
	default:
		break;
	}
    
    int i = 0;
    while (m_BlastContainer[i].x != 0.0f
        && m_BlastContainer[i].y != 0.0f
        &&i<=6)
    {
        i++;
    }
    if (i < 6)
    {
        m_BlastContainer[i] = m_BlastPosition;
    }
    
	return {blast_range_flg, m_BlastPosition,MAP_CHIP_ID::EMPTY};
}

vivid::Vector2 Dice::GetBlastPos(int i)
{
    return m_BlastContainer[i];
}

bool Dice::GoalFlag(void)
{
int x = (int)((m_Position.x - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
int y = (int)((m_Position.y - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    return STAGE.GoalFlag(x,y);
}

bool Dice::KeyFlag(void)
{
    return m_KeyClearFlag;
}

//�_�C�X�̈ʒu
vivid::Vector2 Dice::GetDicePosition(void)
{
    return m_Position;
}
