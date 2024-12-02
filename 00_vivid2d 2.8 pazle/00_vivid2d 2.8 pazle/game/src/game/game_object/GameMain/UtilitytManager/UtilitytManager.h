#pragma once
#pragma once
#include "vivid.h"
#include <list>
#include <map>
#include <functional>
#include "Utility_ID.h"

class Dice;
class UtilityBase;

struct Blast_state
{
	bool			DicePosFlag;
	vivid::Vector2	BlastPos;
	MAP_CHIP_ID		ID;
};

class UtilityManager
{
private:
	UtilityManager();
	~UtilityManager();
	UtilityManager(const UtilityManager& rhs);
	UtilityManager(const UtilityManager&& rhs);
	UtilityManager& operator=(const UtilityManager& rhs);

	Dice* m_Dice;

	using UTILITYLIST = std::list<UtilityBase*>;
	UTILITYLIST m_UtilityList;

	std::map<UTILITY_ID, std::function<UtilityBase* (void)>> m_Generator;


	int m_KeyDigit;
	//vivid::Vector2 m_KeyPosition[];

public:
	/*!
	 *	@brief	インスタンスの取得
	 *
	 *	@return	キーマネージャークラスのインスタンス
	 */
	static UtilityManager& GetInstance();
	//初期化
	void Initialize(Dice* dice);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);
	//サイコロとの当たり判定
	bool Collision(void);

	Blast_state Blast(void);

	void Create(UTILITY_ID id, vivid::Vector2 pos);
	//デバック時に描画されるデータ
	void KEY_DEBUG_DRAW_DATA(void);
};
