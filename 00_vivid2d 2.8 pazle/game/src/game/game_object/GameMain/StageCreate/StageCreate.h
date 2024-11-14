#pragma once

#include <string>

#include "vivid.h"
#include "../../StageSelect/Stage_id.h"

class StageSelect;
class Dice;
class UtilityManager;

// �}�b�v�`�b�v�ԍ���񋓌^�Œ�`
enum class MAP_CHIP_ID
{
	EMPTY,			//��
	WALL,			//��
	BLASTWALL,		//���j�ł����
	STARTFLAG,		//�X�^�[�g
	GOALFLAG,		//�S�[��
};

const int g_map_chip_size = 64;
const int g_map_chip_count_width = 12;
const int g_map_chip_count_height = 12;

class StageCreate
{
private:
	// �z��f�[�^�����Ă������߂̓񎟌��z��i�����j
	unsigned int m_Map[g_map_chip_count_height][g_map_chip_count_width] =
	{ (unsigned int)MAP_CHIP_ID::EMPTY };

	StageCreate() = default;
	~StageCreate() = default;

	StageSelect* m_Select;
	Dice* m_Dice;
	UtilityManager* m_Key;
	STAGE_ID m_StageID;

	vivid::Vector2 m_SavePosition;

	struct ROADSTAGE
	{
		const char* RoadName;
	};

	ROADSTAGE m_StageName[(int)STAGE_ID::MAX] =
	{
		"data\\excel\\stage1.csv",
		"data\\excel\\stage2.csv",
		"data\\excel\\stage3.csv",
		"data\\excel\\stage4.csv",
		"data\\excel\\stage5.csv",
		"data\\excel\\stage6.csv",
	};

	int m_DiceDigit;
	int m_KeyDigit;
	vivid::Vector2 m_DicePosition;

public:

	static StageCreate& GetInst(void);

	//������
	void Initialize(StageSelect* target, Dice* dice);
	//�X�V
	void Update(void);
	//�`��
	void Draw(void);
	//���
	void Finalize(void);
	//�ǁA������
	vivid::Vector2 GetCollision(vivid::Vector2 vec2, int width, int height, float between);
	//�X�^�[�g�ʒu������
	vivid::Vector2 StartPosition(void);
	//�S�[���ɃL�����N�^�[���ڐG������(�ڐG���� == true, other == false)
	bool GoalFlag(vivid::Vector2 vec2, int width, int height);

	void BlastRange(void);

	int GetKeyDigit(void);

	int GetMapChipSize(void);

	//�����̃}�X�ڂ̏ꏊ���ǂ��ǂ������ׂ�
//��true�@�ʘHfalse
	bool CheckWall(int x, int y);
};

#define STAGE StageCreate::GetInst()
