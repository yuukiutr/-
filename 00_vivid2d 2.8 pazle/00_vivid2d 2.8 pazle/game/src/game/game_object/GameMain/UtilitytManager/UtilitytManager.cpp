#include "../StageCreate/StageCreate.h"
#include "../dice/dice.h"
#include "UtilitytManager.h"
#include "UtilityBase/Key/key.h"
#include "UtilityBase/BreakableWall/BreakableWall.h"

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
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return *this;
}

UtilityManager& UtilityManager::GetInstance(void)
{
	static UtilityManager Instance;
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�

	return Instance;
}

void UtilityManager::Initialize(void)
{	
	m_Generator[UTILITY_ID::BreakableWall] = []() {return new BreakableWall(); };
	m_Generator[UTILITY_ID::KEY] = []() {return new Key(); };


	m_KeyDigit = STAGE.GetKeyDigit();
}

void UtilityManager::Update(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();

	while (it != end)
	{
		UtilityBase* base = (*it);

		base->Update();

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

		base->Finalize();

		++it;
	}
}

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

		if (flag)
		{
			return true;
		}

		++it;
	}

	return false;
}


Blast_state UtilityManager::Blast(void)
{
	UTILITYLIST::iterator it = m_UtilityList.begin();
	UTILITYLIST::iterator end = m_UtilityList.end();


	while (it != end)
	{
		UtilityBase* base = (*it);
		if (base->GetUtilityID() == UTILITY_ID::BreakableWall ||
			base->GetUtilityID() == UTILITY_ID::KEY)
		{
			//Dice::GetInstance().BlastSpot()
		}
	}

	return { false,{0.0f,0.0f},MAP_CHIP_ID::KEY };

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

