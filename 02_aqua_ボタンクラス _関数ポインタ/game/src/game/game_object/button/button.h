#pragma once
#include"aqua.h"
#include <functional>

class CButton :public aqua::IGameObject
{
public:
	using CLICK_FUNCTION = std::function<void(void)>;

	struct BUTTON_INFO
	{
		aqua::CVector2 position = aqua::CVector2::ZERO;
		int width = m_min_button_size;
		int height = m_min_button_size;
		int font_size = m_default_font_size;
		std::string text = "�{�^��";
		CLICK_FUNCTION on_click = [](){};
		
	};
	//�R���X�g���N�^
	CButton(IGameObject* parent);
	//�f�X�g���N�^
	~CButton(void) = default;

	//������
	void Initialize(CLICK_FUNCTION on_click = [](){},
		const aqua::CVector2& position = aqua::CVector2::ZERO,
		int width = m_min_button_size,
		int height = m_min_button_size,
		int font_size = m_default_font_size,
		const std::string& text = "�{�^��");



	//������
	void Initialize(const BUTTON_INFO& info);
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;
	//���̃N���b�N
	//void OnClick(void);
	
	/*
	void(*OnClick)(void);
	*/
	CLICK_FUNCTION OnClick;
	
	//�ʒu���擾
	void SetPosition(const aqua::CVector2& position);
	//�T�C�Y�擾
	void SetSize(int width, int height);

private:

	/*
	*	@brief	���C�A�E�g
	*/
	enum class LAYOUT_ID
	{
		UPPER_LEFT,		//����
		UPPER_RIGHT,	//�E��
		LOWER_LEFT,		//����
		LOWER_RIGHT,	//�E��
		LEFT,			//��
		UPPER,			//��
		RIGHT,			//�E
		LOWER,			//��
		CENTER,			//����
	};

	/*
	*	@brief	�Z�b�g�A�b�v���N�g
	*/
	void SetUpRect(void);

	/*
	*	@brief �J���[�ݒ�
	*/
	void SetColor(const aqua::CColor& color);

	static const int			m_sprite_count;			//�X�v���C�g�J�E���g
	static const int			m_corner_size;			//�R�[�i�[�T�C�Y
	static const int			m_default_font_size;	//�f�t�H���g�t�H���g�T�C�Y
	static const int			m_default_texture_size;	//�f�t�H���g�e�N�X�`���T�C�Y

	static const unsigned int	m_default_color;		//�f�t�H���g�J���[
	static const unsigned int	m_selected_color;		//�J�[�\��������Ă���Ƃ��̐F
	static const unsigned int	m_clicked_color;		//�N���b�N���ꂽ���̐F
	static const unsigned int	m_text_color;

	int							m_Width;				//��
	int							m_Height;				//����

	aqua::CSprite*				m_Sprite;				//�X�v���C�g�N���X
	aqua::CVector2				m_Position;				//�ʒu
	aqua::CLabel				m_Text;					//�e�L�X�g
	aqua::CSoundPlayer			m_ExplosionSound;		//�����T�E���h
	

	static const int m_min_button_size;



};