#pragma once

class ベース
{
public:
	virtual void 関数1(void) = 0;
	virtual void 関数2(void) = 0;
};

class 子クラス1 : ベース
{
public:
	void 関数1(void) override;
	void 関数2(void) override;
};

class 子クラス2 : ベース
{
public:
	void 合成関数1(ベース&);
	void 合成関数2(ベース&);
};

void Test(void)
{
	子クラス2 合成子クラス;
	子クラス1 オーバーライド子クラス;

	合成子クラス.合成関数1(オーバーライド子クラス);
	合成子クラス.合成関数2(オーバーライド子クラス);
}
