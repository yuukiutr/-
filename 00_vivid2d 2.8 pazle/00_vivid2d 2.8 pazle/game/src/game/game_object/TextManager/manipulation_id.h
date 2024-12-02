#pragma once

//���[�h�̑���
enum class LOAD_ID
{
	//���l�̂�
	ONLY_NUMERIC,
	//�A���t�@�x�b�g�̂�
	ONLY_ALPHABET,
	//���{��̂�
	ONLY_JAPANESE,
	//���l�ƃA���t�@�x�b�g�̂�
	ALPHABET_AND_NUMERIC,
	//���ׂ�
	ALL,

	//��O����
	DUMMY
};

//�Z�[�u�̑���
enum class SAVE_ID
{
	//����
	CREATE,
	//�㏑��
	OVERWRITING,
	//�ǋL
	PS,

	DUMMY
};

//�R�s�[�̑���
enum class COPY_ID
{
	//�㏑��
	NORMAL,
	//�f����(�㏑�� 1MB�܂�)
	QUICK,
	//���ɘA��
	CONNECT_BOTTOM,
	//�O�ɘA��
	CONNECT_TOP,


	DUMMY
};
