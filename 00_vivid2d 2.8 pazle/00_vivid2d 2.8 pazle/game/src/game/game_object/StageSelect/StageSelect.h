#pragma once
#include "vivid.h"
#include "Stage_id.h"

class StageSelect
{
protected:
	STAGE_ID m_NowStageID;

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	STAGE_ID GetNowStageID(void);

private:
	int m_SelectNumber;
	int m_FrameCount;					//�t���[���̓_�ŗp
	int m_frame_invisible;				//�t���[���̌����Ȃ�����
	int m_frame_count_reset;			//�t���[���J�E���g�̃��Z�b�g
	int m_ReturnCount;					//�����쎞�Ԍv��
	int m_return_time;					//�^�C�g���ɖ߂�܂ł̎���
	unsigned int	m_Color;			//�����x
	bool m_FremeVisibleFlag;			//�t���[���̃t���O
	vivid::Vector2 m_ButtonPosition;	//�{�^���̈ʒu
	vivid::Vector2 m_stage1_position;	//stage 1�̈ʒu
};

#define _DRAW_DEBUG_DATA false;
