#pragma once
#include "vivid.h"
#include "../Utility_ID.h"

class Dice;
class StageCreate;

class UtilityBase
{
protected:
	Dice* m_Dice;
	StageCreate* m_Stage;

	vivid::Vector2 m_UtilityPosition;
	static const int m_utility_width;
	static const int m_utility_height;
	unsigned int m_UtilityColor;
	static const bool m_UtilityFlag;

public:
	//初期化
	virtual void Initialize(Dice* dice, vivid::Vector2 pos);

	//更新
	virtual void Update(void);

	//描画
	virtual void Draw(void);

	//解放
	virtual void Finalize(void);

	//Utilityとの当たり判定
	virtual bool GetCollisionFlag(int x, int y);

	//Utilityの位置の取得
	virtual vivid::Vector2 GetPosition(void);

	//生成されたUtilityのID
	virtual UTILITY_ID GetUtilityID(void);


	bool GetUtilityFlag(void);
};