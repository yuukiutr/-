#pragma once

// ！説明のために日本語にしているだけなので "

// ！実際に書くときは必ず英単語にしてください "


//ベース自体に型を持たせて
//それを外部でoverrideする事でベースの役割をする型
//この場合ベースのcppが！"必要"
class ベース_仮想関数
{
	/*
	 * overrideしなくてもいい
	 * 
	 */

protected:
	//変数、定数が !"必要"(定数の場合 static にする)
	int 変数;
	static const int 定数;

public:
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);
	bool ActiveFlag(void); //消してほしいとき、falseにする

};


//ベース自体に型を持たせず
//外部でのoverrideに完全依存し
//それの受け皿をすることでベースの役割をする型
//この場合ベースのcppが！"不要"
class ベース_純粋仮想関数
{
	/*!
	 * 
	 * ！絶対に override させなければならない ！
	 * 
	 * 　*上記のことが満たせていないとき ERRER を吐きます
	 * 
	 */

protected:
	//変数、定数が !"不要"

public:
	virtual void Initalize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Finalize(void) = 0;
	virtual bool ActiveFlag(void) = 0; //消してほしいとき、falseにする

};
