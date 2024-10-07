
//main.cpp

/*!
 *  @file       main.cpp
 *  @brief      �G���g���[�|�C���g
 *  @author     Kazuya Maruyama
 *  @date       2021/06/18
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "vivid.h"

#include "game/game.h"
/*!
 *  @brief      �`��֐�
 */
void
Display(void)
{
    //�S��ʕ\��
    ChangeWindowMode(FALSE);

    //�Q�[���̍X�V
    UpdateGame();

    //�Q�[���̕`��
    DrawGame();
}

/*!
 *  @brief      ���C���֐�
 *
 *  @param[in]  hInst       �C���X�^���X�n���h��
 *  @param[in]  hPrevInst   Win16����̈╨
 *  @param[in]  lpCmdLine   �R�}���h���C��������
 *  @param[in]  nCmdShow    �E�B���h�̕\�����@
 *
 *  @return     ���C���֐��̐���
 */
int WINAPI
WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;



    // vivid���C�u����������
    vivid::Initialize(hInst);

    //�Q�[���̏�����
    InitializeGame();

    // �X�V/�`��֐��o�^
    vivid::DisplayFunction(Display);

    // �Q�[�����[�v
    vivid::MainLoop();

    // vivid���C�u�������
    vivid::Finalize();
}
