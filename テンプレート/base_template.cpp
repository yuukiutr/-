#include "base_template.h"

// ！説明のために日本語にしているだけなので "

// ！実際に書くときは必ず英単語にしてください "

//後の書き方は普通のクラスと同じ

const int ベース_仮想関数::定数 = 0;

void ベース_仮想関数::Initalize(void)
{
	変数 = 0;
}

void ベース_仮想関数::Update(void)
{

}

void ベース_仮想関数::Draw(void)
{

}

void ベース_仮想関数::Finalize(void)
{

}

bool ベース_仮想関数::ActiveFlag(void)
{
	if (/*条件*/)
	{
		return false;
	}

	return true;
}
