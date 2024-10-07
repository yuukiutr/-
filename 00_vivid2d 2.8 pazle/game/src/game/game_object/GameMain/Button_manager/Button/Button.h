#pragma once
#include "vivid.h"

/*!
 *BUTTN.h
 *BUTTN.cpp
 *
 *システム要件
 *
 *クラスを使用する
 *
 *キャラクターがボタンの真上に来た時
 *上に乗ってから5f経った時ボタンを踏んだ判定にする
 *ボタンが押されたことがわかるbool型の関数を用意する
 *
 *ボタンは複数出せるようにManagerもシングルトンクラスで作成する
 * 
 * !-> シングルトンクラスの書き方は gekiden_2内のテンプレートを参照
 * 
 *　*** できればやってほしい ***
 * 
 *BaseClassを作成しておく
 *Buttonclassを軸にしたプログラムの作成
 *
 *
 */

class Character;

class Button
{
protected:
	vivid::Vector2 m_Button_Position;
	vivid::Vector2 m_Pushed_Button_Position;
	const int m_width;
	const int m_height;
	vivid::Vector2 m_rect;
	Character* m_Character;
	const float m_max_button_timer;
	float m_Button_Timer;
	bool m_ButtonOnFlag;
	bool m_OnCharacterFlag;


public:
	void Initialize(Character* character, vivid::Vector2 pos);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};
