#pragma once
#include"vivid.h"


class Title
{
protected:
	static const int m_max_BG = 2;
	static const int m_message_font_size = 40;

	vivid::Vector2 g_TitleBG1Position;						//タイトルポジション空、一番奥
	vivid::Vector2 g_TitleBG2Position[m_max_BG];			//タイトルポジション　、真ん中
	vivid::Vector2 g_TitleBG3Position[m_max_BG];			//タイトルポジション　、一番前
	const	vivid::Vector2 g_titlerogoposition = { ((float)vivid::WINDOW_WIDTH - 1818.0f) / 2.0f,0.0 };		//ロゴのポジ
	const	vivid::Vector2 g_titlestartposition = { ((float)vivid::WINDOW_WIDTH - (float)m_message_font_size * 9.5f) / 2.0f,((float)vivid::WINDOW_HEIGHT / 8.0f * 7.0f) - ((float)m_message_font_size - 2.0f) };		//スタートする奴のポジション
	const int m_title_width = 3840;		//タイトル用背景サイズ横
	const int  m_title_height = 1080;	//タイトル用背景サイズ縦
	const int m_title_logo_width = 796;	//タイトルロゴのサイズ横
	const int m_title_logo_height = 312;	//タイトルロゴのサイズ縦

	vivid::Rect m_Rect;			//描画範囲


	float g_TitlePawa;
	int m_NowTitle;
	int m_time;
	unsigned int m_color;
	bool m_color_flag;
	int m_in_color;
	vivid::Vector2 m_anchor = { (float)m_title_width / 2.0f,0.0f };//中心
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




	const std::string g_title_rogo = "data/rogo.png";			//タイトルロゴ

	const std::string g_title_message = "Aボタンでスタート";

	const std::string g_title_message_credit = "Dボタンでクレジットへ";

	const std::string white_back = "data/tmp_back.png";	//暗転明転要白背景





public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};