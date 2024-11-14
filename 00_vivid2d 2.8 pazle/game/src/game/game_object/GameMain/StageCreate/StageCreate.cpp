#include "StageCreate.h"
#include "../dice/dice.h"

#include <fstream>

#include "../EnemyManager/EnemyManager.h"
#include "../../StageSelect/StageSelect.h"

StageCreate& StageCreate::GetInst(void)
{
    static StageCreate instance;

    return instance;
}

void StageCreate::Initialize(StageSelect* target, Dice* dice)
{
    m_Select = target;
    m_Dice = dice;
    m_StageID = m_Select->GetNowStageID();

    m_KeyDigit = 0;

    //�t�@�C�����J��
    std::ifstream file(m_StageName[(int)m_Select->GetNowStageID()].RoadName);
    std::string line = "\0";
    std::string data = "\0";

    while (std::getline(file, line))
    {
        line = line + ",";
        data = data + line;
        line = "\0";
    }

    char t = NULL;

    size_t size = data.size();

    auto k = 0;

    /*
     * �f�[�^�̉��
     */
     //�f�[�^�T�C�Y�̕��J��Ԃ�
    for (auto i = 0ull; i < size; ++i)
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            t = data[i];
            if (data[i + 1] >= '0' && data[i + 1] <= '9')
            {
                m_Map[k / g_map_chip_count_width][k % g_map_chip_count_width]
                    = (unsigned int)atoi(&t) * 10u;
                t = data[i + 1];
                m_Map[k / g_map_chip_count_width][k % g_map_chip_count_width]
                    += (unsigned int)atoi(&t);
                ++i;
            }
            else
            {
                m_Map[k / g_map_chip_count_width][k % g_map_chip_count_width]
                    = (unsigned int)atoi(&t);
            }

            ++k;
        }
    }

    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        //�������̂����܂�(���j�\�u���b�N�H)
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size);
            pos.y = (float)(i * (float)g_map_chip_size);

            /*
            * 5 ��
            * 6 
            * 7
            */

            if (m_Map[i][k] == 5u)
            {
                

                m_Map[i][k] = 0u;
            }

            if (m_Map[i][k] == 6u)
            {

                m_Map[i][k] = 0u;
            }


            if (m_Map[i][k] == 7u)
            {

                m_Map[i][k] = 0u;
            }

        }
    }

    m_SavePosition = { 0.0f,0.0f };
}

void StageCreate::Update(void)
{
    BlastRange();
}

void StageCreate::Draw(void)
{
    //�v�f�����J��Ԃ�
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size) + 200.0f;
            pos.y = (float)(i * (float)g_map_chip_size) + 200.0f;

            //�ǂݍ��ݔ͈͂����߂�
            vivid::Rect rect = {};
            rect.left = (int)m_Map[i][k] * g_map_chip_size;
            rect.right = rect.left + g_map_chip_size;
            rect.top = 0;
            rect.bottom = g_map_chip_size;

            //�`��
            vivid::DrawTexture("data\\gamemain_utility\\test.png", pos, 0xffffffff, rect);
            //vivid::DrawTexture("data/groundplus.png", { 0.0f,0.0f });
        }
    }

    //�����͈͕\��
    switch (m_DiceDigit)
    {
    case 1:
        for (int j = -1; j <= 1; j += 2)
            if (m_DicePosition.x >= 200.0f && m_DicePosition.x < 968.0f && m_DicePosition.y + 64 * j >= 200.0f && m_DicePosition.y + 64 * j < 968.0f)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x, m_DicePosition.y + 64 * j });
        break;
    case 2:
        for (int i = -1; i <= 1; i += 2)
            if (m_DicePosition.x + 64 * i >= 200.0f && m_DicePosition.x + 64 * i < 968.0f && m_DicePosition.y >= 200.0f && m_DicePosition.y < 968.0f)
            vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x + 64 * i , m_DicePosition.y});
        break;
    case 3:
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)            
                if (m_DicePosition.x + 64 * i >= 200.0f && m_DicePosition.x + 64 * i < 968.0f && m_DicePosition.y + 64 * j >= 200.0f && m_DicePosition.y + 64 * j < 968.0f)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x + 64 * i , m_DicePosition.y + 64 * j});
        break;
    case 4:
        for (int i = -1; i <= 1; i++)
            for (int j = -2; j <= 2; j += 4)
                if (m_DicePosition.x + 64 * i >= 200.0f && m_DicePosition.x + 64 * i < 968.0f && m_DicePosition.y + 64 * j >= 200.0f && m_DicePosition.y + 64 * j < 968.0f)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x + 64 * i , m_DicePosition.y + 64 * j });
        break;
    case 5:
        for (int i = -2; i <= 2; i += 4)
            for (int j = -1; j <= 1; j++)
                if (m_DicePosition.x + 64 * i >= 200.0f && m_DicePosition.x + 64 * i < 968.0f && m_DicePosition.y + 64 * j >= 200.0f && m_DicePosition.y + 64 * j < 968.0f)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x + 64 * i , m_DicePosition.y + 64 * j });
        break;
    case 6:
        for (int i = -2; i <= 2; i += 4)
            for (int j = -2; j <= 2; j += 4)
                if (m_DicePosition.x + 64 * i >= 200.0f && m_DicePosition.x + 64 * i < 968.0f && m_DicePosition.y + 64 * j >= 200.0f && m_DicePosition.y + 64 * j < 968.0f)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png", { m_DicePosition.x + 64 * i , m_DicePosition.y + 64 * j });
        break;
    default:
        break;
    }
}

void StageCreate::Finalize(void)
{
}

/*
 * @brief �}�b�v�`�b�v�̓����蔻��
 * @param[in] vivid::Vector2 vec2 <- �����蔻�肪�ق����L�����N�^�[�̍��W
 * @param[in] int width <- �����蔻�肪�ق����L�����N�^�[�̉���
 * @param[in] int height <- �����蔻�肪�ق����L�����N�^�[�̏c��
 * @return vivid::Vector vec2 <- param �œ��ꂽvivid::Vector2�Ŏ󂯎�点��
 *
 */
vivid::Vector2 StageCreate::GetCollision(vivid::Vector2 vec2, int width, int height, float between)
{
    //�v�f�����J��Ԃ�
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            if (m_Map[i][k] == 1u)
            {

                vivid::Vector2 pos;
                pos.x = (float)(k * (float)g_map_chip_size);
                pos.y = (float)(i * (float)g_map_chip_size);

                //
                if (m_Map[i - 1][k] != 1u && i > 0 || i == 0)
                {
                    if (vec2.x + (float)width > pos.x + between
                        && vec2.x < pos.x + (float)g_map_chip_size - between
                        && vec2.y + (float)height >= pos.y
                        && vec2.y < pos.y - (float)height / 2.0f)
                    {
                        vec2.y = pos.y - (float)height;
                    }
                }

                if (vec2.y <= pos.y + (float)g_map_chip_size
                    && vec2.y + (float)height >= pos.y + (float)g_map_chip_size
                    && vec2.x + (float)width > pos.x + between
                    && vec2.x < pos.x + (float)g_map_chip_size - between)
                {
                    vec2.y = pos.y + (float)g_map_chip_size;
                }
                //}

                //��
                if (vec2.x + (float)width >= pos.x
                    && vec2.x <= pos.x + (float)g_map_chip_size / 3.0f
                    && vec2.y + (float)height > pos.y + (float)g_map_chip_size / 3.0f
                    && vec2.y < pos.y + (float)g_map_chip_size / 1.5f)
                {
                    vec2.x = pos.x - (float)width;
                }

                if (vec2.x + (float)width >= pos.x + (float)g_map_chip_size / 2.0f
                    && vec2.x <= pos.x + (float)g_map_chip_size
                    && vec2.y + (float)height > pos.y + (float)g_map_chip_size / 3.0f
                    && vec2.y < pos.y + (float)g_map_chip_size / 1.5f)
                {
                    vec2.x = pos.x + (float)g_map_chip_size;
                }
            }
        }
    }

    return vec2;
}

vivid::Vector2 StageCreate::StartPosition(void)
{
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            if (m_Map[i][k] != 3) continue;

            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size)+200.0f;
            pos.y = (float)(i * (float)g_map_chip_size)+200.0f;

            return pos;
        }
    }

    return { -1.0f,-1.0f };
}

bool StageCreate::GoalFlag(vivid::Vector2 vec2, int width, int height)
{
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            if (m_Map[i][k] != 4) continue;

            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size);
            pos.y = (float)(i * (float)g_map_chip_size);

            if (vec2.x + (float)width >= pos.x + width / 2.0f
                && vec2.x <= pos.x + (float)g_map_chip_size - width / 2.0f
                && vec2.y + (float)height > pos.y + (float)g_map_chip_size - height * 2.0f / 3.0f
                && vec2.y < pos.y + (float)g_map_chip_size - height / 3.0f)
            {
                return true;
            }
        }
    }

    return false;
}

void StageCreate::BlastRange(void)
{
    m_DicePosition = m_Dice->GetDicePosition();
    m_DiceDigit = m_Dice->GetDiceDigit();
}

int StageCreate::GetKeyDigit(void)
{
    return m_KeyDigit;
}

int StageCreate::GetMapChipSize(void)
{
    return g_map_chip_size;
}

bool StageCreate::CheckWall(int x, int y)
{
    if (x < 0)x = 0;
    if (x > g_map_chip_count_width)x = g_map_chip_count_width - 1;
    if (y < 0)y = 0;
    if (y > g_map_chip_count_height)y = g_map_chip_count_height - 1;

    //ID���ǂ����j�ǂȂ�i�߂Ȃ�
    if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::WALL 
        || m_Map[y][x] == (unsigned char)MAP_CHIP_ID::BLASTWALL)
        return true;

    return false;
}