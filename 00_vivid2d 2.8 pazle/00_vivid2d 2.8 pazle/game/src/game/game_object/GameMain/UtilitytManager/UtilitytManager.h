#pragma once
#pragma once
#include "vivid.h"
#include <list>
#include <map>
#include <functional>
#include "Utility_ID.h"

class Dice;
class UtilityBase;

struct Blast_state
{
	bool			DicePosFlag;
	vivid::Vector2	BlastPos;
	MAP_CHIP_ID		ID;
};

class UtilityManager
{
private:
	UtilityManager();
	~UtilityManager();
	UtilityManager(const UtilityManager& rhs);
	UtilityManager(const UtilityManager&& rhs);
	UtilityManager& operator=(const UtilityManager& rhs);

	Dice* m_Dice;

	using UTILITYLIST = std::list<UtilityBase*>;
	UTILITYLIST m_UtilityList;

	std::map<UTILITY_ID, std::function<UtilityBase* (void)>> m_Generator;


	int m_KeyDigit;
	//vivid::Vector2 m_KeyPosition[];

public:
	/*!
	 *	@brief	�C���X�^���X�̎擾
	 *
	 *	@return	�L�[�}�l�[�W���[�N���X�̃C���X�^���X
	 */
	static UtilityManager& GetInstance();
	//������
	void Initialize(Dice* dice);
	//�X�V
	void Update(void);
	//�`��
	void Draw(void);
	//���
	void Finalize(void);
	//�T�C�R���Ƃ̓����蔻��
	bool Collision(void);

	Blast_state Blast(void);

	void Create(UTILITY_ID id, vivid::Vector2 pos);
	//�f�o�b�N���ɕ`�悳���f�[�^
	void KEY_DEBUG_DRAW_DATA(void);
};
