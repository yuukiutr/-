#include "sound_manager.h"

const char* CSoundManager::m_sound_file_names[] =
{
	"data\\se\\AS_143571_�V���Z�^�����������Ȓ��^�������ȕ��͋C.mp3",
	"data\\se\\AS_823312_BGM_�X�e�[�W�Z���N�gA.mp3",
	"data\\se\\AS_119380_�e�[�u���Q�[���Q�p�Y���Ǝv�l�̑���.mp3",
	"data\\se\\AS_1536262_�p�Y���Q�[���̃��U���g��ʋ�.mp3",
	"data\\se\\AS_890909_�I����.mp3",
	"data\\se\\AS_890893_���艹.mp3",
	"data\\se\\AS_1080800_�L�����Z���^���j���[�^�߂�^�l�K�e�B�u.mp3",
	"data\\se\\AS_215480_�����E��C7�F���ߋ����A�Z�������E�j��.mp3",
	"data\\se\\AS_224094_�`���������i�s�R�s�R�^�e�N�m�^�C�x���g.mp3",
	"data\\se\\AS_1467764_�s�R�b�E�J�`�b�E����E�e���b�v�E�|�b�v6.mp3",
	"data\\se\\AS_39629_�L�����Ƃ������킢��SE�ł��B.mp3",
	"data\\se\\AS_1534404_�J���i���M��u�����j007.mp3",

};

//�C���X�^���X�̎擾
CSoundManager& CSoundManager::GetInstance(void)
{
	static CSoundManager instance;
	
	return instance;
}

//�ǂݍ���
void CSoundManager::Load(void)
{
	for (int i = 0; i < (int)SOUND_ID::MAX; i++)
	{
		vivid::LoadSound(m_sound_file_names[i]);
	}
}

//�Đ�
void CSoundManager::Play(SOUND_ID id, bool loop)
{
	vivid::PlaySound(m_sound_file_names[(int)id], loop);
}

void CSoundManager::StopSound(SOUND_ID id)
{
	vivid::StopSound(m_sound_file_names[(int)id]);
}

//�R���X�g���N�^
CSoundManager::CSoundManager(void)
{
}

//�R�s�[�R���X�g���N�^
CSoundManager::CSoundManager(const CSoundManager& rhs)
{
	(void) rhs;
}

//�f�X�g���N�^
CSoundManager::~CSoundManager(void)
{
}

CSoundManager& CSoundManager::operator=(const CSoundManager& rhs)
{
	(void)rhs;
	return *this;
}
