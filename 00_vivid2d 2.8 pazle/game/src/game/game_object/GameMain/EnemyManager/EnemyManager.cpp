#include "EnemyManager.h"
#include "Enemy/EnemyBase.h"
#include "../character/character.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

EnemyManager::EnemyManager(const EnemyManager&rhs)
{
    (void)rhs;
}

EnemyManager::EnemyManager(const EnemyManager&& rhs)
{
    (void)rhs;
}

EnemyManager& EnemyManager::operator=(const EnemyManager& rhs)
{
    (void)rhs;
    // TODO: return ステートメントをここに挿入します
    return *this;
}

EnemyManager& EnemyManager::GetInstance(void)
{
    static EnemyManager Instance;
    // TODO: return ステートメントをここに挿入します
    return Instance;
}

void EnemyManager::Initialize(Character* character)
{
    m_character = character;

    m_Generator[ENEMY_ID::BASE] = []() {return new EnemyBase(); };
}


void EnemyManager::Update(void)
{
    ENEMYLIST::iterator it = m_EnemyList.begin();
    ENEMYLIST::iterator end = m_EnemyList.end();

    while (it != end)
    {
        EnemyBase* base = (*it);

        base->Update();
        if (base->GetDeadFlag())
        {
            delete (*it);
            it = m_EnemyList.erase(it);
        }

        ++it;
    }
}

void EnemyManager::Draw(void)
{
    ENEMYLIST::iterator it = m_EnemyList.begin();
    ENEMYLIST::iterator end = m_EnemyList.end();

    while (it != end)
    {
        EnemyBase* base = (*it);

        base->Draw();

        ++it;
    }
}

void EnemyManager::Finalize(void)
{
    ENEMYLIST::iterator it = m_EnemyList.begin();
    ENEMYLIST::iterator end = m_EnemyList.end();

    while (it != end)
    {
        (*it)->Finalize();

        delete (*it);

        it = m_EnemyList.erase(it);
    }
}

bool EnemyManager::GetLoseFlag(void)
{
    ENEMYLIST::iterator it = m_EnemyList.begin();
    ENEMYLIST::iterator end = m_EnemyList.end();
    bool flag = false;

    while (it != end)
    {
        EnemyBase* base = (*it);

        flag = base->GetLoseFlag();

        if (flag) break;

        ++it;

    }

    return flag;
}

void EnemyManager::Create(ENEMY_ID ID, vivid::Vector2 pos)
{
    EnemyBase* base = nullptr;

    base = m_Generator[ID]();

    if (base != nullptr)
    {
        base->Initialize(m_character);

        m_EnemyList.push_back(base);
    }
}
