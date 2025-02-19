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
	
	for (int i = 0; i < 6; i++)
	{
		m_EffectPos[i] = { 0.0f,0.0f };
	}
	count = 0;
	m_EffectCount = 0;
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

	if (m_effect_flg && m_EffectCount <= 24)
	{
		for (int i = 0; i < 6; i++)
		{
			if (m_EffectPos[i].x != 0.0f &&
				m_EffectPos[i].y != 0.0f)
				vivid::DrawTexture("data\\gamemain_utility\\blast.png", m_EffectPos[i]);

		}
		m_EffectCount++;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			m_EffectPos[i] = { 0.0f,0.0f };
		}
		m_effect_flg = false;
		m_EffectCount = 0;
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
						m_EffectPos[count] = Dice::GetInstance().BlastSpot(0, j).BlastPos;
						count++;
						m_effect_flg = true;
						flg = true;
						delete(*it);
						it = m_UtilityList.erase(it);
						CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
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
						m_EffectPos[count] = Dice::GetInstance().BlastSpot(i, 0).BlastPos;
						count++;
						m_effect_flg = true;
						flg = true;
						delete(*it);
						it = m_UtilityList.erase(it);
						CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
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
							m_EffectPos[count] = Dice::GetInstance().BlastSpot(i, j).BlastPos;
							count++;
							m_effect_flg = true;
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
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
							m_EffectPos[count] = Dice::GetInstance().BlastSpot(i, j).BlastPos;
							count++;
							m_effect_flg = true;
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
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
							m_EffectPos[count] = Dice::GetInstance().BlastSpot(i, j).BlastPos;
							count++;
							m_effect_flg = true;
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
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
							m_EffectPos[count] = Dice::GetInstance().BlastSpot(i, j).BlastPos;
							count++;
							m_effect_flg = true;
							flg = true;
							delete(*it);
							it = m_UtilityList.erase(it);
							CSoundManager::GetInstance().Play(SOUND_ID::BLAST);
							break;
						}
				}
			}
			break;
		default:
			break;
		}
		/*
		*/
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

void UtilityManager::Effect(vivid::Vector2 pos)
{
	vivid::DrawTexture("data\\gamemain_utility\\blast.png", pos);
}

