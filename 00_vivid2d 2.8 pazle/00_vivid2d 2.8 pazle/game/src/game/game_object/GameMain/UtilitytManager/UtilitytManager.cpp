#include "../StageCreate/StageCreate.h"
#include "../dice/dice.h"
#include "UtilitytManager.h"
#include "UtilityBase/Key/key.h"
#include "UtilityBase/BreakableWall/BreakableWall.h"
#include "../../sound_manager/sound_manager.h"

UtilityManager::UtilityManager()
{
}

UtilityManager::~UtilityManager()
{
}

UtilityManager::UtilityManager(const UtilityManager& rhs)
{
	(void)rhs;
}

UtilityManager::UtilityManager(const UtilityManager&& rhs)
{
	(void)rhs;
}

UtilityManager& UtilityManager::operator=(const UtilityManager& rhs)
{
	(void)rhs;
	// TODO: return ステートメントをここに挿入します
	return *this;
}

UtilityManager& UtilityManager::GetInstance(void)
{
	static UtilityManager Instance;
	// TODO: return ステートメントをここに挿入します

	return Instance;
}

void UtilityManager::Initialize(void)
{	
	m_Generator[UTILITY_ID::BreakableWall] = []() {return new BreakableWall(); };
	m_Generator[UTILITY_ID::KEY] = []() {return new Key(); };

	
	m_KeyDigit = STAGE.GetKeyDigit();
	m_KeyDeleteFlag = false;
	CSoundManager::GetInstance().Load();
}

void UtilityManager::Update(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	while (it != end)
	{
		UtilityBase* base = (*it);

		base->Update();

		//カギを消す処理
		if (base->GetUtilityID()==UTILITY_ID::KEY
			&& (base->GetPosition() == Dice::GetInstance().GetDicePosition()))
		{
			delete(*it);
			it = m_UtilityList.erase(it);
			SetKeyDeleteFlag(true);
			CSoundManager::GetInstance().Play(SOUND_ID::GET_KEY);
		}
		if (it == end)break;
		++it;
	}
}

void UtilityManager::Draw(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	while (it != end)
	{
		UtilityBase* base = (*it);

		base->Draw();

		++it;
	}
}

void UtilityManager::Finalize(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	while (it != end)
	{
		UtilityBase* base = (*it);

		(*it)->Finalize();

		delete(*it);
		it = m_UtilityList.erase(it);
	}
}

/*
* マスが鍵の場合は移動できる
*/
bool UtilityManager::Collision(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();
	vivid::Vector2 tmp = Dice::GetInstance().GetDicePosition();

	bool flag = false;

	while (it != end)
	{
		UtilityBase* base = (*it);

		if (tmp == base->GetPosition())
		{
			++it;
			continue;
		}

		flag = base->GetCollisionFlag();

		if (flag &&
			base->GetUtilityID()==UTILITY_ID::BreakableWall)
		{
			return true;
		}

		++it;
	}

	return false;
}


void UtilityManager::Blast(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	bool flg = false;
	bool begin_flg = false;

	while (it != end)
	{
		UtilityBase* base = (*it);

		switch (Dice::GetInstance().GetDiceDigit())
		{
		case 1:

			for (int j = -1; j <= 1 && flg == false; j += 2)
			{
				if (Dice::GetInstance().BlastSpot(0, j).DicePosFlag)
					if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
						base->GetUtilityID() == UTILITY_ID::KEY)
						&& base->GetPosition() == Dice::GetInstance().BlastSpot(0, j).BlastPos)
					{
						flg = true;
						delete(*it);
						it = m_UtilityList.erase(it);
						break;
					}
			}
			break;
		case 2:
			for (int i = -1; i <= 1 && flg == false; i += 2)
			{
				if (Dice::GetInstance().BlastSpot(i, 0).DicePosFlag)
					if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
						base->GetUtilityID() == UTILITY_ID::KEY)
						&& base->GetPosition() == Dice::GetInstance().BlastSpot(i, 0).BlastPos)
					{
						flg = true;
						delete(*it);
						it = m_UtilityList.erase(it);
						break;
					}
			}
			break;
		case 3:
			for (int i = -1; i <= 1 && flg == false; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
						if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
							base->GetUtilityID() == UTILITY_ID::KEY)
							&& base->GetPosition() == Dice::GetInstance().BlastSpot(i, j).BlastPos)
						{
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							break;
						}
				}
			}
			break;
		case 4:
			for (int i = -1; i <= 1 && flg == false; i++)
			{
				for (int j = -2; j <= 2; j += 4)
				{
					if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
					{
						if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
							base->GetUtilityID() == UTILITY_ID::KEY)
							&& base->GetPosition() == Dice::GetInstance().BlastSpot(i, j).BlastPos)
						{
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							break;
						}
					}
				}
			}
			break;
		case 5:
			for (int i = -2; i <= 2 && flg == false; i += 4)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
						if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
							base->GetUtilityID() == UTILITY_ID::KEY)
							&& base->GetPosition() == Dice::GetInstance().BlastSpot(i, j).BlastPos)
						{
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							break;
						}
				}
			}
			break;
		case 6:
			for (int i = -2; i <= 2 && flg == false; i += 4)
			{
				for (int j = -2; j <= 2; j += 4)
				{
					if (Dice::GetInstance().BlastSpot(i, j).DicePosFlag)
						if ((base->GetUtilityID() == UTILITY_ID::BreakableWall ||
							base->GetUtilityID() == UTILITY_ID::KEY)
							&& base->GetPosition() == Dice::GetInstance().BlastSpot(i, j).BlastPos)
						{
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							break;
						}
				}
			}
			break;
		default:
			break;
		}
		if (it == end)break;
		++it;
	}


}

void UtilityManager::Create(UTILITY_ID ID, vivid::Vector2 pos)
{
	UtilityBase* base = nullptr;

	base = m_Generator[ID]();

	if (base != nullptr)
	{
		base->Initialize(pos);

		m_UtilityList.push_back(base);
	}
}


void UtilityManager::KEY_DEBUG_DRAW_DATA(void)
{
#ifdef VIVID_DEBUG

	int UtilityCount = 0;

	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	while (it != end)
	{
		UtilityCount++;

		++it;
	}

	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::NUMPAD3))
	{
		vivid::DrawText(30, "BC:" + std::to_string(UtilityCount), { 0.0f,240.0f }, 0xff00ff00);
	}
#endif //VIVID_DEBUG

}

bool UtilityManager::GetKeyDeleteFlag(void)
{
	return m_KeyDeleteFlag;
}

void UtilityManager::SetKeyDeleteFlag(bool flg)
{
	m_KeyDeleteFlag = flg;
}

