#pragma once
#include"vivid.h"
#include "../gamescene_manager/gamescene_id.h"


class Title
{
public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
private:
	vivid::Vector2	m_Position;
	vivid::Rect		rect;
	bool m_GoStageSelect;
	int m_OuterFrameCount;	//�O�g�̓_��
	const int m_outer_frame_roop_time = 50;
	const int m_outer_frame_light_time = 40;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const int m_title_width = 0;		//�^�C�g���p�w�i�T�C�Y��
	const int  m_title_height = 0;		//�^�C�g���p�w�i�T�C�Y�c
	const int m_title_logo_width = 1500;	//�^�C�g�����S�̃T�C�Y��
	const int m_title_logo_height = 562;	//�^�C�g�����S�̃T�C�Y�c

	vivid::Rect m_Rect;			//�`��͈�

	vivid::Vector2 m_anchor;// ���S
	vivid::Vector2 m_Scale;

	GameScene_ID m_ID;
};