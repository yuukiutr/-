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
	vivid::Vector2	m_dice_Position;
	vivid::Vector2	m_TITLE_position;
	vivid::Vector2	m_OPTION_position;
	vivid::Rect		rect;
	bool m_GoStageSelect;
	const int m_dice_width = 64;
	const int m_dice_height = 64;
	const int m_title_logo_width = 1700;	//タイトルロゴのサイズ横
	//const int m_title_logo_height = 568;	//タイトルロゴのサイズ縦

	vivid::Rect m_Rect;			//描画範囲

	vivid::Vector2 m_anchor;// 中心
	vivid::Vector2 m_Scale;

	GameScene_ID m_ID;
};