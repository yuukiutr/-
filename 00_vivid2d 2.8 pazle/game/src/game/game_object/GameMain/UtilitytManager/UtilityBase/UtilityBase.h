#pragma once
#include "vivid.h"
#include "../Utility_ID.h"

class StageCreate;

class UtilityBase
{
protected:
	StageCreate* m_Stage;
	vivid::Vector2 m_UtilityPosition;
	static const int m_utility_width;
	static const int m_utility_height;
	unsigned int m_UtilityColor;

	static const std::string m_Utility_Data;

public:
	//初期化
	virtual void Initialize(StageCreate* stage, vivid::Vector2 pos);

	//更新
	virtual void Update(void);

	//描画
	virtual void Draw(void);

	//解放
	virtual void Finalize(void);

	//BOXとの当たり判定
	virtual vivid::Vector2 UtilityCollision(vivid::Vector2 vec2, int width, int height);

	//BOXの位置の取得
	virtual vivid::Vector2 GetPosition(void);

	//生成されたBOXのID
	virtual UTILITY_ID GetUtilityID(void);
};