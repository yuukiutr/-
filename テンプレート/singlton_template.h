#pragma once
#include "base_id.h"
#include <functional>
#include <map>
#include <list>

// ！説明のために日本語にしているだけなので "

// ！実際に書くときは必ず英単語にしてください "


class ベースクラスの名前;

class マネージャークラス
{
	// 必ず以下の五つを private: にする
private:
	マネージャークラス();											//<- こ
	~マネージャークラス();											//<- の
	マネージャークラス(const マネージャークラス& rhs);				//<- 五
	マネージャークラス(const マネージャークラス&& rhs);				//<- つ
	マネージャークラス& operator=(const マネージャークラス& rhs);	//<- ！

	//ベースリストはすべて大文字 例：BASELIST
	using ベースリスト = std::list<ベースクラスの名前*>;

	ベースリスト m_ベースリスト;

	std::map<ベースID, std::function<ベースクラスの名前* (void)>> ジェネレータ;

public:
	static マネージャークラス& GetInstance(void);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void Create(ベースID ID); //呼び出す関数の初期化も行う関数

};

/*!
 * マネージャーの呼び出し方
 */

#include "singlton_template.h"

void TEST(void)
{
	//------例--------
	マネージャークラス::GetInstance().Create(ベースID::ベース);
	マネージャークラス::GetInstance().Update();
}




