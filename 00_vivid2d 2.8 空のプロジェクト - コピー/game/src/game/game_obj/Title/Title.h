#pragma once
#include"vivid.h"


class Title
{
protected:
	static const int m_max_BG = 2;
	static const int m_message_font_size = 40;

	vivid::Vector2 g_TitleBG1Position;						//�^�C�g���|�W�V������A��ԉ�
	vivid::Vector2 g_TitleBG2Position[m_max_BG];			//�^�C�g���|�W�V�����@�A�^��
	vivid::Vector2 g_TitleBG3Position[m_max_BG];			//�^�C�g���|�W�V�����@�A��ԑO
	const	vivid::Vector2 g_titlerogoposition = { ((float)vivid::WINDOW_WIDTH - 1818.0f) / 2.0f,0.0 };		//���S�̃|�W
	const	vivid::Vector2 g_titlestartposition = { ((float)vivid::WINDOW_WIDTH - (float)m_message_font_size * 9.5f) / 2.0f,((float)vivid::WINDOW_HEIGHT / 8.0f * 7.0f) - ((float)m_message_font_size - 2.0f) };		//�X�^�[�g����z�̃|�W�V����
	const int m_title_width = 3840;		//�^�C�g���p�w�i�T�C�Y��
	const int  m_title_height = 1080;	//�^�C�g���p�w�i�T�C�Y�c
	const int m_title_logo_width = 796;	//�^�C�g�����S�̃T�C�Y��
	const int m_title_logo_height = 312;	//�^�C�g�����S�̃T�C�Y�c

	vivid::Rect m_Rect;			//�`��͈�


	float g_TitlePawa;
	int m_NowTitle;
	int m_time;
	unsigned int m_color;
	bool m_color_flag;
	int m_in_color;
	vivid::Vector2 m_anchor = { (float)m_title_width / 2.0f,0.0f };//���S
	vivid::Vector2 m_Scale = { 1.0f,1.0f };

	//
	const std::string g_title_BG_1_name[3] =
	{
		"data/back/back1_3.png",
		"data/back/back2_3.png",
		"data/back/back3_3.png"

	};
	const std::string g_title_BG_2_name[3] =
	{
		"data/back/back1_2.png",
		"data/back/back2_2.png",
		"data/back/back3_2.png"
	};
	const std::string g_title_BG_3_nume[3] =
	{
		"data/back/back1_1.png",
		"data/back/back2_1.png",
		"data/back/back3_1.png"

	};




	const std::string g_title_rogo = "data/rogo.png";			//�^�C�g�����S

	const std::string g_title_message = "A�{�^���ŃX�^�[�g";

	const std::string g_title_message_credit = "D�{�^���ŃN���W�b�g��";

	const std::string white_back = "data/tmp_back.png";	//�Ó]���]�v���w�i





public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};