#pragma once
#include"vivid.h"


class Title
{
protected:
	//static const int m_max_BG;
	//static const int m_message_font_size;

	const int m_title_width = 0;		//タイトル用背景サイズ横
	const int  m_title_height = 0;		//タイトル用背景サイズ縦
	const int m_title_logo_width = 0;	//タイトルロゴのサイズ横
	const int m_title_logo_height = 0;	//タイトルロゴのサイズ縦

	vivid::Rect m_Rect;			//描画範囲


	float g_TitlePower;
	int m_NowTitle;
	int m_time;
	unsigned int m_color;
	bool m_color_flag;
	int m_in_color;
	vivid::Vector2 m_anchor;// 中心
	vivid::Vector2 m_Scale;
public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};