#pragma once
#include "base_template.h"

class �q�N���X : public �x�[�X_���z�֐��@//�x�[�X_�������z�֐��ł�OK
{
	/*!
	 * protected: �ɂ��Ă��闝�R
	 * 
	 * private: �̏ꍇ override ���Ă�
	 * �x�[�X�N���X�����̕ϐ��A�萔�A�֐���F�����Ă���Ȃ�
	 * 
	 */
protected:
	/*!
	 * �x�[�X_���z�֐��� override �����ꍇ
	 * �x�[�X_���z�֐��� public, protected ���̕ϐ��A�萔���g������
	 * 
	 */

	//�q�N���X�Ǝ��̕ϐ����`���邱�Ƃ��\(�萔�� static��t����)
	

public:
	/*!
	 * �Ioverride����֐��� ���O,����,�߂�l ���̂��ׂĂ�
	 * �@���S��v���Ȃ���΂Ȃ�Ȃ��I
	 * 
	 * �I��L�̂��Ƃ��������Ă��Ȃ��Ƃ� ERRER ��f���܂��I
	 * 
	 */

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

};
