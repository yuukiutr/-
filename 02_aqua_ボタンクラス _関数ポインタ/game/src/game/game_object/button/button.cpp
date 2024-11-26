#include "button.h"

const int CButton::m_sprite_count = 9;
const int CButton::m_corner_size = 12;

const unsigned int CButton::m_default_color = 0xffffffff;
const unsigned int CButton::m_selected_color= 0xffeeeeee;
const unsigned int CButton::m_clicked_color= 0xffeeffff;
const unsigned int CButton::m_text_color = 0xff000000;

const int CButton::m_default_font_size = 16;
const int CButton::m_default_texture_size = 64;
const int CButton::m_min_button_size = CButton::m_corner_size * 10;
//コンストラクタ
CButton::CButton(IGameObject* parent)
	:IGameObject(parent)
	,m_Position(aqua::CVector2(0.0f,0.0f))
	,m_Width(m_default_texture_size)
	,m_Height(m_default_texture_size)
{
}
//初期化
void CButton::Initialize(const BUTTON_INFO& info)
{
	m_Sprite = AQUA_NEW aqua::CSprite[m_sprite_count];
	for (int i = 0; i < m_sprite_count; ++i)
	{
		m_Sprite[i].Create("data\\button.png");
	}
	m_Text.Create(info.font_size);

	m_Text.text = "ボタン";
	m_Text.color = m_text_color;

	SetUpRect();
	SetSize(info.width, info.height);
	SetPosition(info.position);
	OnClick = info.on_click;
}

//初期化
void CButton::Initialize(CLICK_FUNCTION on_click,
	const aqua::CVector2& position,
	int width,
	int height,
	int font_size,
	const std::string& text)
{
	BUTTON_INFO info;

	info.position = position;
	info.width;
	info.height;
	info.font_size = font_size;
	info.text = text;
	info.on_click = on_click;

	Initialize(info);
}
//更新
void CButton::Update(void)
{
	namespace mouse = aqua::mouse;

	aqua::CPoint mpos = mouse::GetCursorPos();
		/*
		*	カーソウルがボタンの範囲内に居るか否か
		*	(ifの式はカーソルが範囲内にいない)
		*/
	if (mpos.x<m_Position.x || mpos.x>m_Position.x + m_Width
		|| mpos.y<m_Position.y || mpos.y>m_Position.y + m_Height)
	{
		//	範囲外	:色をデフォルトにSetする
		SetColor(m_default_color);
	}
	else
	{
		//	範囲内	:　色を選択色にSetする
		SetColor(m_selected_color);

		//マウスボタンの状態確認
		if (mouse::Button(mouse::BUTTON_ID::LEFT))
			//ボタンが押されている:色をクリック色にSetする
			SetColor(m_clicked_color);
		else if (mouse::Released(mouse::BUTTON_ID::LEFT))
			if (OnClick)OnClick();
	}
}
//描画
void CButton::Draw(void)
{
	for (int i = 0; i < m_sprite_count; ++i)
	{
		m_Sprite[i].Draw();
	}
	m_Text.Draw();
}
//解放
void CButton::Finalize(void)
{
	for (int i = 0; i < m_sprite_count; i++)
	{
		m_Sprite[i].Delete();
	}

	AQUA_SAFE_DELETE_ARRAY(m_Sprite);
	
	m_Text.Delete();
	m_ExplosionSound.Delete();
}
/*
* 位置設定
*/
void CButton::SetPosition(const aqua::CVector2& position)
{
	m_Position = position;
	//各スプライトの位置設定
	float cw = (float)(m_Width - m_corner_size);
	float ch = (float)(m_Height - m_corner_size);

	m_Sprite[(int)LAYOUT_ID::UPPER_LEFT].position	= m_Position;
	m_Sprite[(int)LAYOUT_ID::UPPER_RIGHT].position	= m_Position + aqua::CVector2(cw						,0.0f);
	m_Sprite[(int)LAYOUT_ID::LOWER_LEFT].position	= m_Position + aqua::CVector2(0.0f						,ch);
	m_Sprite[(int)LAYOUT_ID::LOWER_RIGHT].position	= m_Position + aqua::CVector2(cw						,ch);
	m_Sprite[(int)LAYOUT_ID::LEFT].position			= m_Position + aqua::CVector2(0.0f						,(float)m_corner_size);
	m_Sprite[(int)LAYOUT_ID::UPPER].position		= m_Position + aqua::CVector2((float)m_corner_size		,0.0f);
	m_Sprite[(int)LAYOUT_ID::RIGHT].position		= m_Position + aqua::CVector2(cw						,(float)m_corner_size);
	m_Sprite[(int)LAYOUT_ID::LOWER].position		= m_Position + aqua::CVector2((float)m_corner_size		,ch);
	m_Sprite[(int)LAYOUT_ID::CENTER].position		= m_Position + aqua::CVector2((float)m_corner_size		,(float)m_corner_size);


	//ラベルの座標修正
	m_Text.position = m_Position;
	m_Text.position.x += (float)m_Width/ 2.0f - (float)m_Text.GetTextWidth() / 2.0f;
	m_Text.position.y += (float)m_Height/ 2.0f - (float)m_Text.GetFontHeight() / 2.0f;;
}

/*
*	@brief	サイズ設定
*/
void CButton::SetSize(int width, int height)
{
	m_Width		= width;
	m_Height	= height;

	float cs = m_corner_size * 2.0f;

	float sw = (float)(m_Width - cs) / (float)(m_default_texture_size - cs);

	float sh = (float)(m_Height - cs) / (float)(m_default_texture_size - cs);

	m_Sprite[(int)LAYOUT_ID::LEFT].scale	= aqua::CVector2(1.0f	,sh);
	m_Sprite[(int)LAYOUT_ID::UPPER].scale	= aqua::CVector2(sw		,1.0f);
	m_Sprite[(int)LAYOUT_ID::RIGHT].scale	= aqua::CVector2(1.0f	,sh);
	m_Sprite[(int)LAYOUT_ID::LOWER].scale	= aqua::CVector2(sw		,1.0f);
	m_Sprite[(int)LAYOUT_ID::CENTER].scale	= aqua::CVector2(sw		,sh);

	SetPosition(m_Position);
}

/*
*	@brief	ワンクリック
*/

/*
*	@brief	レクトアップ設定
*/	
void CButton::SetUpRect(void)
{
	//int cs = m_default_texture_size(64) - m_corner_size(12)				
	int cs = m_default_texture_size - m_corner_size;

	m_Sprite[(int)LAYOUT_ID::UPPER_LEFT].rect	= aqua::CRect(0					,0				,m_corner_size					,m_corner_size);
	m_Sprite[(int)LAYOUT_ID::UPPER_RIGHT].rect	= aqua::CRect(cs				,0				,m_default_texture_size			,m_corner_size);
	m_Sprite[(int)LAYOUT_ID::LOWER_LEFT].rect	= aqua::CRect(0					,cs				,m_corner_size					,m_default_texture_size);
	m_Sprite[(int)LAYOUT_ID::LOWER_RIGHT].rect	= aqua::CRect(cs				,cs				,m_default_texture_size			,m_default_texture_size);
	m_Sprite[(int)LAYOUT_ID::LEFT].rect			= aqua::CRect(0					,m_corner_size	,m_corner_size					,cs);
	m_Sprite[(int)LAYOUT_ID::UPPER].rect		= aqua::CRect(m_corner_size		,0				,cs								,m_corner_size);
	m_Sprite[(int)LAYOUT_ID::RIGHT].rect		= aqua::CRect(cs				,m_corner_size	,m_default_texture_size			,cs);
	m_Sprite[(int)LAYOUT_ID::LOWER].rect		= aqua::CRect(m_corner_size		,cs				,cs								,m_default_texture_size);
	m_Sprite[(int)LAYOUT_ID::CENTER].rect		= aqua::CRect(m_corner_size,m_corner_size,cs,cs);
	
}

/*
*	 カラー設定
*/
void CButton::SetColor(const aqua::CColor& color)
{
	for(int i=0;i<m_sprite_count;i++)
	m_Sprite[i].color = color;
}
