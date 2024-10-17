/*
 * ground.cpp
 *
 * producer takuma kumamoto
 *
 * final update 2024/05/23
 */
#include "StageCreate.h"

#include <fstream>

#include "../EnemyManager/EnemyManager.h"
#include "../../StageSelect/StageSelect.h"

void StageCreate::Initialize(StageSelect* target)
{
    m_Select = target;
    m_StageID = m_Select->GetNowStageID();

    m_GroundPosition = { 0.0f,0.0f };

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
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_width);
            pos.y = (float)(i * (float)g_map_chip_height);

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
    if (m_GroundPosition.x > 0.0f)
    {
        m_GroundPosition.x = 0.0f;
    }
}

void StageCreate::Draw(void)
{
    //要素数分繰り返す
    for (int i = 0; i < g_map_chip_count_height; ++i)
    {
        for (int k = 0; k < g_map_chip_count_width; ++k)
        {
            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_width) + m_GroundPosition.x;
            pos.y = (float)(i * (float)g_map_chip_height) + m_GroundPosition.y;

            //読み込み範囲を求める
            vivid::Rect rect = {};
            rect.left = (int)m_Map[i][k] * g_map_chip_width;
            rect.right = rect.left + g_map_chip_width;
            rect.top = 0;
            rect.bottom = g_map_chip_height;

            //描画
            vivid::DrawTexture("data\\g.png", pos, 0xffffffff, rect);
            //vivid::DrawTexture("data/groundplus.png", { 0.0f,0.0f });
        }
    }
}

void StageCreate::Finalize(void)
{
}

/*
 * @brief マップチップの当たり判定
 * @param[in] vivid::Vector2 vec2 <- 当たり判定がほしいキャラクターの座標
 * @param[in] int width <- 当たり判定がほしいキャラクターの横幅
 * @param[in] int height <- 当たり判定がほしいキャラクターの縦幅
 * @return vivid::Vector vec2 <- param で入れたvivid::Vector2で受け取らせる
 *
 */
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
                pos.x = (float)(k * (float)g_map_chip_width) + m_GroundPosition.x;
                pos.y = (float)(i * (float)g_map_chip_height) + m_GroundPosition.y;

                //
                if (m_Map[i - 1][k] != 1u && i > 0 || i == 0)
                {
                    if (vec2.x + (float)width > pos.x + between
                        && vec2.x < pos.x + (float)g_map_chip_width - between
                        && vec2.y + (float)height >= pos.y
                        && vec2.y < pos.y - (float)height / 2.0f)
                    {
                        vec2.y = pos.y - (float)height;
                    }
                }

                if (vec2.y <= pos.y + (float)g_map_chip_height
                    && vec2.y + (float)height >= pos.y + (float)g_map_chip_height
                    && vec2.x + (float)width > pos.x + between
                    && vec2.x < pos.x + (float)g_map_chip_width - between)
                {
                    vec2.y = pos.y + (float)g_map_chip_height;
                }
                //}

                //横
                if (vec2.x + (float)width >= pos.x
                    && vec2.x <= pos.x + (float)g_map_chip_width / 3.0f
                    && vec2.y + (float)height > pos.y + (float)g_map_chip_height / 3.0f
                    && vec2.y < pos.y + (float)g_map_chip_height / 1.5f)
                {
                    vec2.x = pos.x - (float)width;
                }

                if (vec2.x + (float)width >= pos.x + (float)g_map_chip_width / 2.0f
                    && vec2.x <= pos.x + (float)g_map_chip_width
                    && vec2.y + (float)height > pos.y + (float)g_map_chip_height / 3.0f
                    && vec2.y < pos.y + (float)g_map_chip_height / 1.5f)
                {
                    vec2.x = pos.x + (float)g_map_chip_width;
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
            pos.x = (float)(k * (float)g_map_chip_width) + 10.0f;
            pos.y = (float)(i * (float)g_map_chip_height) - 1.0f;

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
            if (m_Map[i][k] != 3) continue;

            vivid::Vector2 pos;
            pos.x = (float)(k * (float)g_map_chip_width);
            pos.y = (float)(i * (float)g_map_chip_height);

            if (vec2.x + (float)width >= pos.x + width / 2.0f
                && vec2.x <= pos.x + (float)g_map_chip_width - width / 2.0f
                && vec2.y + (float)height > pos.y + (float)g_map_chip_height - height * 2.0f / 3.0f
                && vec2.y < pos.y + (float)g_map_chip_height - height / 3.0f)
            {
                return true;
            }
        }
    }

    return false;
}


