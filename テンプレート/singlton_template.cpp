#include "singlton_template.h"
//#include "�x�[�X�N���X/�x�[�X�N���X.h"

// �I�����̂��߂ɓ��{��ɂ��Ă��邾���Ȃ̂� "

// �I���ۂɏ����Ƃ��͕K���p�P��ɂ��Ă������� "

�}�l�[�W���[�N���X::�}�l�[�W���[�N���X()
{

}

�}�l�[�W���[�N���X::~�}�l�[�W���[�N���X();
{

}

�}�l�[�W���[�N���X::�}�l�[�W���[�N���X(const �}�l�[�W���[�N���X& rhs);
{
	(void)rhs;
}

�}�l�[�W���[�N���X::�}�l�[�W���[�N���X(const �}�l�[�W���[�N���X&& rhs);
{
	(void)rhs;
}

�}�l�[�W���[�N���X& �}�l�[�W���[�N���X::operator=(const �}�l�[�W���[�N���X& rhs)
{
	(void)rhs;

	//TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return *this;
}

//--------- public ---------

static �}�l�[�W���[�N���X& GetInstance(void)
{
	static �}�l�[�W���[�N���X Instance;

	//TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return Instance;
}

void �}�l�[�W���[�N���X::Initialize(void)
{
	�W�F�l���[�^[�x�[�XID::�x�[�X] = []() {return new �x�[�X�N���X�̖��O(); };
}

void �}�l�[�W���[�N���X::Update(void)
{
	�x�[�X���X�g::iterator it = m_�x�[�X���X�g.begin();
	�x�[�X���X�g::iterator end = m_�x�[�X���X�g.end;

	while (it != end)
	{
		�x�[�X�N���X�̖��O* base = (*it);

		base->Update();

		if (!base->ActiveFlag())
		{
			(*it)->Finalize();

			delete (*it);

			it = m_�x�[�X���X�g.erase(it);

			continue;
		}

		++it;
	}

}

void �}�l�[�W���[�N���X::Draw(void)
{
	�x�[�X���X�g::iterator it = m_�x�[�X���X�g.begin();
	�x�[�X���X�g::iterator end = m_�x�[�X���X�g.end;

	while (it != end)
	{
		�x�[�X�N���X�̖��O* base = (*it);

		base->Draw();

		++it;
	}

}

void �}�l�[�W���[�N���X::Finalize(void)
{
	�x�[�X���X�g::iterator it = m_�x�[�X���X�g.begin();
	�x�[�X���X�g::iterator end = m_�x�[�X���X�g.end;

	while (it != end)
	{
		(*it)->Finalize();

		delete (*it);

		it = m_�x�[�X���X�g.erase(it);
	}

}

void �}�l�[�W���[�N���X::Create(�x�[�XID ID)
{
	�x�[�X�N���X�̖��O* base = nullptr;

	base = �W�F�l���[�^[ID]();

	if (base != nullptr)
	{
		base->Initialize();

		m_�x�[�X���X�g.push_back(base);
	}
}
