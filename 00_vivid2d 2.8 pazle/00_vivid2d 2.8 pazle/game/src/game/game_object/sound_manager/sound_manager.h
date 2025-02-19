#pragma once
#include "vivid.h"
//�T�E���hID

enum class SOUND_ID
{
	TITLE,				//�^�C�g��BGM
	STAGESELECT,		//�X�e�[�W�Z���N�gBGM
	GAMEMAIN,			//�Q�[�����C��BGM
	RESULT,				//���U���gBGM
	SELECT,				//�I����
	DECISION,			//���艹
	CANCEL,				//��������
	BLAST,				//���j��
	START,				//�J�n��
	RETRY,				//���g���C��
	GET_KEY,			//�J�M�l����
	DICE_MOVE,			//�T�C�R�����]���鉹
	GOAL,				//�S�[���W���O��

	MAX
};

class CSoundManager
{
public:
	//�C���X�^���X�̎擾
	static CSoundManager& GetInstance(void);

	//�T�E���h�̓ǂݍ���
	void Load(void);

	//�T�E���h�̍Đ�
	void Play(SOUND_ID id, bool loop = false);

	//�T�E���h�̒�~
	void StopSound(SOUND_ID id);

private:
	//�R���X�g���N�^
	CSoundManager(void);
	
	//�R�s�[�R���X�g���N�^
	CSoundManager(const CSoundManager& rhs);

	//�f�X�g���N�^
	~CSoundManager(void);

	//������Z�q
	CSoundManager& operator=(const CSoundManager& rhs);

	//�T�E���h�̃t�@�C����
	static const char* m_sound_file_names[(int)SOUND_ID::MAX];
};
