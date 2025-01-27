#include "StageCreate.h"
#include "../dice/dice.h"

#include <fstream>

#include "../../StageSelect/StageSelect.h"
#include "../UtilitytManager/UtilitytManager.h"

/*
*  maptipID 
* 0　床 
* 1　壁
* 2　スタート
* 3　ゴール
* 4　壊せる壁
* 5　鍵
*/

StageCreate& StageCreate::GetInstance(void)
{
    static StageCreate instance;

    return instance;
}

void StageCreate::Initialize(StageSelect* target)
{
    m_Select = target;
    m_StageID = m_Select->GetNowStageID();

    m_KeyDigit = 0;

    //ファイルを開く
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
     * データの解析
     */
     //データサイズの分繰り返し
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
        //動くものを入れます(爆破可能ブロック？)
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size)+200.0f;
            pos.y = (float)(i * (float)g_map_chip_size)+200.0f;

            /*
            * ４ 壊せる壁
            * ５ 鍵
            */

            if (m_Map[i][k] == 4u)
            {
                UtilityManager::GetInstance().Create(UTILITY_ID::BreakableWall, pos);
            }

            /*if (m_Map[i][k] == 5u)
            {
                UtilityManager::GetInstance().Create(UTILITY_ID::KEY, pos);
                m_Map[i][k] = 0u;
            }*/

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
    namespace keyboad = vivid::keyboard;
    BlastRange();
    /*爆破*/
    /*if (keyboad::Trigger(keyboad::KEY_ID::NUMPADENTER))
    {
         MAP_CHIP_SPOT pos = GetMapChipSpot(UtilityManager::GetInstance().Blast().BlastPos);

        if (UtilityManager::GetInstance().Blast().ID == MAP_CHIP_ID::BLASTWALL)
        {
            m_Map[pos.x][pos.y] = 0u;
        }
    }*/
}

void StageCreate::Draw(void)
{
    //要素数分繰り返す
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size) + 200.0f;
            pos.y = (float)(i * (float)g_map_chip_size) + 200.0f;

            //読み込み範囲を求める
            vivid::Rect rect = {};
            rect.left = (int)m_Map[i][k] * g_map_chip_size;
            rect.right = rect.left + g_map_chip_size;
            rect.top = 0;
            rect.bottom = g_map_chip_size;

            //描画
            vivid::DrawTexture("data\\gamemain_utility\\test.png", pos, 0xffffffff, rect);
            //vivid::DrawTexture("data/groundplus.png", { 0.0f,0.0f });
        }
    }


    //爆破範囲表示
    switch (m_DiceDigit)
    {
    case 1:

        for (int j = -1; j <= 1; j += 2)
        {
            if (Dice::GetInstance().BlastSpot(0, j).DicePosFlag)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                    Dice::GetInstance().BlastSpot(0, j).BlastPos);
        }
        break;
    case 2:
        for (int i = -1; i <= 1; i += 2)
        {
            if (Dice::GetInstance().BlastSpot(i, 0).DicePosFlag)
                vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                    Dice::GetInstance().BlastSpot(i, 0).BlastPos);
        }
        break;
    case 3:
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
            {
                if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
                    vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                        Dice::GetInstance().BlastSpot(i, j).BlastPos);
            }
        break;
    case 4:
        for (int i = -1; i <= 1; i++)
            for (int j = -2; j <= 2; j += 4)
            {
                if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
                    vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                        Dice::GetInstance().BlastSpot(i, j).BlastPos);
            }
        break;
    case 5:
        for (int i = -2; i <= 2; i += 4)
            for (int j = -1; j <= 1; j++)
            {
                if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
                    vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                        Dice::GetInstance().BlastSpot(i, j).BlastPos);
            }
        break;
    case 6:
        for (int i = -2; i <= 2; i += 4)
            for (int j = -2; j <= 2; j += 4)
            {
                if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
                    vivid::DrawTexture("data\\gamemain_utility\\blast_range.png",
                        Dice::GetInstance().BlastSpot(i, j).BlastPos);
            }
        break;
    default:
        break;
    }
}

void StageCreate::Finalize(void)
{
}

vivid::Vector2 StageCreate::GetCollision(vivid::Vector2 vec2, int width, int height, float between)
{
    //要素数分繰り返す
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

                //横
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
            if (m_Map[i][k] != 2) continue;

            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_size)+200.0f;
            pos.y = (float)(i * (float)g_map_chip_size)+200.0f;

            return pos;
        }
    }

    return { -1.0f,-1.0f };
}

bool StageCreate::GoalFlag(int x, int y)
{

    if (x < 0)x = 0;
    if (x > g_map_chip_count_width)x = g_map_chip_count_width - 1;
    if (y < 0)y = 0;
    if (y > g_map_chip_count_height)y = g_map_chip_count_height - 1;

    if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::GOALFLAG)return true;

    return false;
}

void StageCreate::BlastRange(void)
{
    m_DicePosition = Dice::GetInstance().GetDicePosition();
    m_DiceDigit = Dice::GetInstance().GetDiceDigit();
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

    //IDが壁か爆破壁なら進めない
    if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::WALL)
        //m_Map[y][x] == (unsigned char)MAP_CHIP_ID::BLASTWALL)
    {
        return true;
    }
    return false;
}

MAP_CHIP_ID StageCreate::GetMapChipID(int x, int y)
{
    if (x < 0)x = 0;
    if (x > g_map_chip_count_width)x = g_map_chip_count_width - 1;
    if (y < 0)y = 0;
    if (y > g_map_chip_count_height)y = g_map_chip_count_height - 1;
    {
        if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::WALL) return MAP_CHIP_ID::WALL;
        if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::BLASTWALL)
            return MAP_CHIP_ID::BLASTWALL;
        if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::GOALFLAG) 
            return MAP_CHIP_ID::GOALFLAG;
    }


    return MAP_CHIP_ID::EMPTY;
}

MAP_CHIP_SPOT StageCreate::GetMapChipSpot(vivid::Vector2 pos)
{
    vivid::Vector2 g_Position = pos;
    int x = (int)((g_Position.x - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());
    int y = (int)((g_Position.y - 200.0f + 0.5f) / (float)STAGE.GetMapChipSize());

    return { x,y };
}
