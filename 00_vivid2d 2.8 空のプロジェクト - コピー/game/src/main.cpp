
//main.cpp

/*!
 *  @file       main.cpp
 *  @brief      エントリーポイント
 *  @author     Kazuya Maruyama
 *  @date       2021/06/18
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "vivid.h"

#include "game/game.h"
/*!
 *  @brief      描画関数
 */
void
Display(void)
{
    //全画面表示
    ChangeWindowMode(FALSE);

    //ゲームの更新
    UpdateGame();

    //ゲームの描画
    DrawGame();
}

/*!
 *  @brief      メイン関数
 *
 *  @param[in]  hInst       インスタンスハンドル
 *  @param[in]  hPrevInst   Win16時代の遺物
 *  @param[in]  lpCmdLine   コマンドライン文字列
 *  @param[in]  nCmdShow    ウィンドの表示方法
 *
 *  @return     メイン関数の成否
 */
int WINAPI
WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;



    // vividライブラリ初期化
    vivid::Initialize(hInst);

    //ゲームの初期化
    InitializeGame();

    // 更新/描画関数登録
    vivid::DisplayFunction(Display);

    // ゲームループ
    vivid::MainLoop();

    // vividライブラリ解放
    vivid::Finalize();
}
