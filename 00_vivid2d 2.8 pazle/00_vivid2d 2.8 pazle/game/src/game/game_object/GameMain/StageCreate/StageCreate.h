#pragma once

#include <string>

#include "vivid.h"
#include "../../StageSelect/Stage_id.h"
#include "MapChipID.h"
class StageSelect;
class Dice;

// �}�b�v�`�b�v�ԍ���񋓌^�Œ�`

const int g_map_chip_size = 64;
const int g_map_chip_count_width = 12;
const int g_map_chip_count_height = 12;
struct MAP_CHIP_SPOT
{
	int x;
	int y;
};

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

	static StageCreate& GetInstance(void);

	//������
	void Initialize(StageSelect* target);
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

	/* @brief �S�[���ɃL�����N�^�[���ڐG������
	*  @return (�ڐG���� == true, other == false)
	*/
	bool GoalFlag(int x, int y);

	void BlastRange(void);

	int GetKeyDigit(void);

	int GetMapChipSize(void);

	//�����̃}�X�ڂ̏ꏊ���ǂ��ǂ������ׂ�
	//��true�@�ʘHfalse
	bool CheckWall(int x, int y);

	MAP_CHIP_ID GetMapChipID(int x, int y);

	//�}�b�v�`�b�v�̂ǂ��ɂ�����̂���Ԃ�
	MAP_CHIP_SPOT GetMapChipSpot(vivid::Vector2 pos);
};

#define STAGE StageCreate::GetInstance()
