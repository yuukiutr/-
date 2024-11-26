
/*!
 *  @file       game.cpp
 *  @brief      ゲーム管理
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
    // 何かしらの処理
    OutputDebugString("ボタンが押された\n");
}

/*
 *  コンストラクタ
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  初期化
 */
void
CGame::
Initialize(void)
{
    // 最初に作るオブジェクト群
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
 *  描画
 */
void
CGame::
Draw(void)
{
    // 画面のクリア
    aqua::Clear(m_clear_color);

    // 描画したいオブジェクト群

    IGameObject::Draw();
}

/*
 *  エフェクト作成
 */
void 
CGame::
CreateEffect( void )
{
    CExplosionEffect* effect = aqua::CreateGameObject<CExplosionEffect>( this );
    effect->Initialize( aqua::CVector2( 300.0f,300.0f ) );
}
