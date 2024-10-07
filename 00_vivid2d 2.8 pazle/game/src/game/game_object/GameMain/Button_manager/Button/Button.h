#pragma once
#include "vivid.h"

/*!
 *BUTTN.h
 *BUTTN.cpp
 *
 *�V�X�e���v��
 *
 *�N���X���g�p����
 *
 *�L�����N�^�[���{�^���̐^��ɗ�����
 *��ɏ���Ă���5f�o�������{�^���𓥂񂾔���ɂ���
 *�{�^���������ꂽ���Ƃ��킩��bool�^�̊֐���p�ӂ���
 *
 *�{�^���͕����o����悤��Manager���V���O���g���N���X�ō쐬����
 * 
 * !-> �V���O���g���N���X�̏������� gekiden_2���̃e���v���[�g���Q��
 * 
 *�@*** �ł���΂���Ăق��� ***
 * 
 *BaseClass���쐬���Ă���
 *Buttonclass�����ɂ����v���O�����̍쐬
 *
 *
 */

class Character;

class Button
{
protected:
	vivid::Vector2 m_Button_Position;
	vivid::Vector2 m_Pushed_Button_Position;
	const int m_width;
	const int m_height;
	vivid::Vector2 m_rect;
	Character* m_Character;
	const float m_max_button_timer;
	float m_Button_Timer;
	bool m_ButtonOnFlag;
	bool m_OnCharacterFlag;


public:
	void Initialize(Character* character, vivid::Vector2 pos);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};
