#pragma once

// �I�����̂��߂ɓ��{��ɂ��Ă��邾���Ȃ̂� "

// �I���ۂɏ����Ƃ��͕K���p�P��ɂ��Ă������� "


//�x�[�X���̂Ɍ^����������
//������O����override���鎖�Ńx�[�X�̖���������^
//���̏ꍇ�x�[�X��cpp���I"�K�v"
class �x�[�X_���z�֐�
{
	/*
	 * override���Ȃ��Ă�����
	 * 
	 */

protected:
	//�ϐ��A�萔�� !"�K�v"(�萔�̏ꍇ static �ɂ���)
	int �ϐ�;
	static const int �萔;

public:
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);
	bool ActiveFlag(void); //�����Ăق����Ƃ��Afalse�ɂ���

};


//�x�[�X���̂Ɍ^����������
//�O���ł�override�Ɋ��S�ˑ���
//����̎󂯎M�����邱�ƂŃx�[�X�̖���������^
//���̏ꍇ�x�[�X��cpp���I"�s�v"
class �x�[�X_�������z�֐�
{
	/*!
	 * 
	 * �I��΂� override �����Ȃ���΂Ȃ�Ȃ� �I
	 * 
	 * �@*��L�̂��Ƃ��������Ă��Ȃ��Ƃ� ERRER ��f���܂�
	 * 
	 */

protected:
	//�ϐ��A�萔�� !"�s�v"

public:
	virtual void Initalize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Finalize(void) = 0;
	virtual bool ActiveFlag(void) = 0; //�����Ăق����Ƃ��Afalse�ɂ���

};
