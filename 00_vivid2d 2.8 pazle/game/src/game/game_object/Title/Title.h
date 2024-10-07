#pragma once
#include"vivid.h"


class Title
{
protected:
	static const int m_max_BG;
	static const int m_message_font_size;

	const int m_title_width;		//�^�C�g���p�w�i�T�C�Y��
	const int  m_title_height;		//�^�C�g���p�w�i�T�C�Y�c
	const int m_title_logo_width;	//�^�C�g�����S�̃T�C�Y��
	const int m_title_logo_height;	//�^�C�g�����S�̃T�C�Y�c

	vivid::Rect m_Rect;			//�`��͈�


	float g_TitlePawa;
	int m_NowTitle;
	int m_time;
	unsigned int m_color;
	bool m_color_flag;
	int m_in_color;
	vivid::Vector2 m_anchor;// ���S
	vivid::Vector2 m_Scale;
public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};