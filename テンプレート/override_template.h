#pragma once
#include "base_template.h"

class 子クラス : public ベース_仮想関数　//ベース_純粋仮想関数でもOK
{
	/*!
	 * protected: にしている理由
	 * 
	 * private: の場合 override しても
	 * ベースクラスがその変数、定数、関数を認識してくれない
	 * 
	 */
protected:
	/*!
	 * ベース_仮想関数を override した場合
	 * ベース_仮想関数の public, protected 内の変数、定数が使い放題
	 * 
	 */

	//子クラス独自の変数を定義することも可能(定数は staticを付ける)
	

public:
	/*!
	 * ！overrideする関数は 名前,引数,戻り値 このすべてが
	 * 　完全一致しなければならない！
	 * 
	 * ！上記のことが満たせていないとき ERRER を吐きます！
	 * 
	 */

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

};
