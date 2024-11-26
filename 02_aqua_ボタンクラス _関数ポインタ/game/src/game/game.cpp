
/*!
 *  @file       game.cpp
 *  @brief      �Q�[���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/06
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game.h"
#include"game_object/button/button.h"
#include "game_object/explosion_effect/explosion.h"

const unsigned int CGame::m_clear_color = 0xff7f7f7f;

void CreateExplosion( void )
{
    // ��������̏���
    OutputDebugString("�{�^���������ꂽ\n");
}

/*
 *  �R���X�g���N�^
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  ������
 */
void
CGame::
Initialize(void)
{
    // �ŏ��ɍ��I�u�W�F�N�g�Q
    CButton* button = aqua::CreateGameObject<CButton>( this );

    button->Initialize( [&]() {
        CExplosionEffect* effect = aqua::CreateGameObject<CExplosionEffect>( this ); 
        effect->Initialize( aqua::CVector2( 300.0f, 300.0f ) ); 
        }, 
        aqua::CVector2::ZERO, 
        200, 
        100 );

    IGameObject::Initialize();
}

/*
 *  �`��
 */
void
CGame::
Draw(void)
{
    // ��ʂ̃N���A
    aqua::Clear(m_clear_color);

    // �`�悵�����I�u�W�F�N�g�Q

    IGameObject::Draw();
}

/*
 *  �G�t�F�N�g�쐬
 */
void 
CGame::
CreateEffect( void )
{
    CExplosionEffect* effect = aqua::CreateGameObject<CExplosionEffect>( this );
    effect->Initialize( aqua::CVector2( 300.0f,300.0f ) );
}
