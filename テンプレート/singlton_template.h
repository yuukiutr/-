#pragma once
#include "base_id.h"
#include <functional>
#include <map>
#include <list>

// �I�����̂��߂ɓ��{��ɂ��Ă��邾���Ȃ̂� "

// �I���ۂɏ����Ƃ��͕K���p�P��ɂ��Ă������� "


class �x�[�X�N���X�̖��O;

class �}�l�[�W���[�N���X
{
	// �K���ȉ��̌܂� private: �ɂ���
private:
	�}�l�[�W���[�N���X();											//<- ��
	~�}�l�[�W���[�N���X();											//<- ��
	�}�l�[�W���[�N���X(const �}�l�[�W���[�N���X& rhs);				//<- ��
	�}�l�[�W���[�N���X(const �}�l�[�W���[�N���X&& rhs);				//<- ��
	�}�l�[�W���[�N���X& operator=(const �}�l�[�W���[�N���X& rhs);	//<- �I

	//�x�[�X���X�g�͂��ׂđ啶�� ��FBASELIST
	using �x�[�X���X�g = std::list<�x�[�X�N���X�̖��O*>;

	�x�[�X���X�g m_�x�[�X���X�g;

	std::map<�x�[�XID, std::function<�x�[�X�N���X�̖��O* (void)>> �W�F�l���[�^;

public:
	static �}�l�[�W���[�N���X& GetInstance(void);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void Create(�x�[�XID ID); //�Ăяo���֐��̏��������s���֐�

};

/*!
 * �}�l�[�W���[�̌Ăяo����
 */

#include "singlton_template.h"

void TEST(void)
{
	//------��--------
	�}�l�[�W���[�N���X::GetInstance().Create(�x�[�XID::�x�[�X);
	�}�l�[�W���[�N���X::GetInstance().Update();
}




