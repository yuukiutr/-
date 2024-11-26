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
//�R���X�g���N�^
CButton::CButton(IGameObject* parent)
	:IGameObject(parent)
	,m_Position(aqua::CVector2(0.0f,0.0f))
	,m_Width(m_default_texture_size)
	,m_Height(m_default_texture_size)
{
}
//������
void CButton::Initialize(const BUTTON_INFO& info)
{
	m_Sprite = AQUA_NEW aqua::CSprite[m_sprite_count];
	for (int i = 0; i < m_sprite_count; ++i)
	{
		m_Sprite[i].Create("data\\button.png");
	}
	m_Text.Create(info.font_size);

	m_Text.text = "�{�^��";
	m_Text.color = m_text_color;

	SetUpRect();
	SetSize(info.width, info.height);
	SetPosition(info.position);
	OnClick = info.on_click;
}

//������
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
//�X�V
void CButton::Update(void)
{
	namespace mouse = aqua::mouse;

	aqua::CPoint mpos = mouse::GetCursorPos();
		/*
		*	�J�[�\�E�����{�^���͈͓̔��ɋ��邩�ۂ�
		*	(if�̎��̓J�[�\�����͈͓��ɂ��Ȃ�)
		*/
	if (mpos.x<m_Position.x || mpos.x>m_Position.x + m_Width
		|| mpos.y<m_Position.y || mpos.y>m_Position.y + m_Height)
	{
		//	�͈͊O	:�F���f�t�H���g��Set����
		SetColor(m_default_color);
	}
	else
	{
		//	�͈͓�	:�@�F��I��F��Set����
		SetColor(m_selected_color);

		//�}�E�X�{�^���̏�Ԋm�F
		if (mouse::Button(mouse::BUTTON_ID::LEFT))
			//�{�^����������Ă���:�F���N���b�N�F��Set����
			SetColor(m_clicked_color);
		else if (mouse::Released(mouse::BUTTON_ID::LEFT))
			if (OnClick)OnClick();
	}
}
//�`��
void CButton::Draw(void)
{
	for (int i = 0; i < m_sprite_count; ++i)
	{
		m_Sprite[i].Draw();
	}
	m_Text.Draw();
}
//���
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
* �ʒu�ݒ�
*/
void CButton::SetPosition(const aqua::CVector2& position)
{
	m_Position = position;
	//�e�X�v���C�g�̈ʒu�ݒ�
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


	//���x���̍��W�C��
	m_Text.position = m_Position;
	m_Text.position.x += (float)m_Width/ 2.0f - (float)m_Text.GetTextWidth() / 2.0f;
	m_Text.position.y += (float)m_Height/ 2.0f - (float)m_Text.GetFontHeight() / 2.0f;;
}

/*
*	@brief	�T�C�Y�ݒ�
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
*	@brief	�����N���b�N
*/

/*
*	@brief	���N�g�A�b�v�ݒ�
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
*	 �J���[�ݒ�
*/
void CButton::SetColor(const aqua::CColor& color)
{
	for(int i=0;i<m_sprite_count;i++)
	m_Sprite[i].color = color;
}
