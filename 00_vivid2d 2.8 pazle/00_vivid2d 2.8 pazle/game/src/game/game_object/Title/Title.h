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
	int m_OuterFrameCount;	//外枠の点滅
	const int m_outer_frame_roop_time = 50;
	const int m_outer_frame_light_time = 40;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const int m_title_width = 0;		//タイトル用背景サイズ横
	const int  m_title_height = 0;		//タイトル用背景サイズ縦
	const int m_title_logo_width = 1500;	//タイトルロゴのサイズ横
	const int m_title_logo_height = 562;	//タイトルロゴのサイズ縦

	vivid::Rect m_Rect;			//描画範囲

	vivid::Vector2 m_anchor;// 中心
	vivid::Vector2 m_Scale;

	GameScene_ID m_ID;
};