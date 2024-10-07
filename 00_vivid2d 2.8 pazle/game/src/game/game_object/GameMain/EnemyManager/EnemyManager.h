#pragma once
#include "vivid.h"
#include <map>
#include <list>
#include <functional>
#include "Enemy_ID.h"

class Character;
class Ground;
class EnemyBase;

class EnemyManager
{
private:
	EnemyManager();
	~EnemyManager();
	EnemyManager(const EnemyManager& rhs);
	EnemyManager(const EnemyManager&& rhs);
	EnemyManager& operator=(const EnemyManager& rhs);

	using ENEMYLIST = std::list<EnemyBase*>;
	ENEMYLIST m_EnemyList;

	std::map<ENEMY_ID, std::function<EnemyBase* (void)>> m_Generator;

	Character* m_character;
	Ground* m_ground;
public:
	//BoxManagerインスタンス
	static EnemyManager& GetInstance(void);
	//初期化
	void Initialize(Character* character);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);

	bool GetLoseFlag(void);

	void Create(ENEMY_ID ID, vivid::Vector2 pos);
};