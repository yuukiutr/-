#include "singlton_template.h"
//#include "ベースクラス/ベースクラス.h"

// ！説明のために日本語にしているだけなので "

// ！実際に書くときは必ず英単語にしてください "

マネージャークラス::マネージャークラス()
{

}

マネージャークラス::~マネージャークラス();
{

}

マネージャークラス::マネージャークラス(const マネージャークラス& rhs);
{
	(void)rhs;
}

マネージャークラス::マネージャークラス(const マネージャークラス&& rhs);
{
	(void)rhs;
}

マネージャークラス& マネージャークラス::operator=(const マネージャークラス& rhs)
{
	(void)rhs;

	//TODO: return ステートメントをここに挿入します
	return *this;
}

//--------- public ---------

static マネージャークラス& GetInstance(void)
{
	static マネージャークラス Instance;

	//TODO: return ステートメントをここに挿入します
	return Instance;
}

void マネージャークラス::Initialize(void)
{
	ジェネレータ[ベースID::ベース] = []() {return new ベースクラスの名前(); };
}

void マネージャークラス::Update(void)
{
	ベースリスト::iterator it = m_ベースリスト.begin();
	ベースリスト::iterator end = m_ベースリスト.end;

	while (it != end)
	{
		ベースクラスの名前* base = (*it);

		base->Update();

		if (!base->ActiveFlag())
		{
			(*it)->Finalize();

			delete (*it);

			it = m_ベースリスト.erase(it);

			continue;
		}

		++it;
	}

}

void マネージャークラス::Draw(void)
{
	ベースリスト::iterator it = m_ベースリスト.begin();
	ベースリスト::iterator end = m_ベースリスト.end;

	while (it != end)
	{
		ベースクラスの名前* base = (*it);

		base->Draw();

		++it;
	}

}

void マネージャークラス::Finalize(void)
{
	ベースリスト::iterator it = m_ベースリスト.begin();
	ベースリスト::iterator end = m_ベースリスト.end;

	while (it != end)
	{
		(*it)->Finalize();

		delete (*it);

		it = m_ベースリスト.erase(it);
	}

}

void マネージャークラス::Create(ベースID ID)
{
	ベースクラスの名前* base = nullptr;

	base = ジェネレータ[ID]();

	if (base != nullptr)
	{
		base->Initialize();

		m_ベースリスト.push_back(base);
	}
}
