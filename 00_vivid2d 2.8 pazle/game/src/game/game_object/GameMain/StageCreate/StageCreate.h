#pragma once

#include <string>

#include "vivid.h"
#include "../../StageSelect/Stage_id.h"

class StageSelect;

// �}�b�v�`�b�v�ԍ���񋓌^�Œ�`
enum class MAP_CHIP_ID
{
	EMPTY,			//��
	WALL,			//��
	STARTFLAG,		//�X�^�[�g
	GOALFLAG,		//�S�[��
};

const int g_map_chip_height = 32;
const int g_map_chip_width = 32;
const int g_map_chip_count_width = vivid::WINDOW_WIDTH / g_map_chip_width;
const int g_map_chip_count_height = vivid::WINDOW_HEIGHT / g_map_chip_height;

class StageCreate
{
private:
	// �z��f�[�^�����Ă������߂̓񎟌��z��i�����j
	unsigned int m_Map[g_map_chip_count_height][g_map_chip_count_width] =
	{ (unsigned int)MAP_CHIP_ID::EMPTY };

	StageSelect* m_Select;
	STAGE_ID m_StageID;

	vivid::Vector2 m_GroundPosition;
	vivid::Vector2 m_SavePosition;

	struct ROADSTAGE
	{
		const char* const RoadName;
	};

	ROADSTAGE m_StageName[(int)STAGE_ID::MAX] =
	{
		"data\\map.csv",
		"data\\stage2.csv",
		"data\\stage3.csv",
		"data\\stage4.csv",
		"data\\stage5.csv",
		"data\\stage6.csv",
		"data\\stage7.csv",
		"data\\stage8.csv",
		"data\\stage9.csv",
		"data\\stage10.csv",
		"data\\stage11.csv",
		"data\\stage12.csv",
		"data\\stage13.csv",
		"data\\stage14.csv",
		"data\\stage15.csv",
		"data\\stage16.csv",
		"data\\stage17.csv",
		"data\\stage18.csv",
		"data\\stage19.csv",
		"data\\stage20.csv",
		"data\\stage21.csv",
		"data\\stage22.csv",
		"data\\stage23.csv",
		"data\\stage24.csv",
		"data\\map_1.csv",
		"data\\special.csv",
	};

public:
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
	//�S�[���ɃL�����N�^�[���ڐG������(�ڐG���� == true, other == false)
	bool GoalFlag(vivid::Vector2 vec2, int width, int height);
};
