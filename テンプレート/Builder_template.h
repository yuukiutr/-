#pragma once

class �x�[�X
{
public:
	virtual void �֐�1(void) = 0;
	virtual void �֐�2(void) = 0;
};

class �q�N���X1 : �x�[�X
{
public:
	void �֐�1(void) override;
	void �֐�2(void) override;
};

class �q�N���X2 : �x�[�X
{
public:
	void �����֐�1(�x�[�X&);
	void �����֐�2(�x�[�X&);
};

void Test(void)
{
	�q�N���X2 �����q�N���X;
	�q�N���X1 �I�[�o�[���C�h�q�N���X;

	�����q�N���X.�����֐�1(�I�[�o�[���C�h�q�N���X);
	�����q�N���X.�����֐�2(�I�[�o�[���C�h�q�N���X);
}
