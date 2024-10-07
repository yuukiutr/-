#pragma once

#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "manipulation_id.h"
#include "text_loader/text_loader.h"
#include "text_writer/text_writer.h"

//�e�L�X�g�Ǘ�
class TextManager
{
private:

	//�C���X�^���X
	TextLoader m_Loader;
	TextWriter m_Writer;

	//�R���X�g���N�^
	TextManager() = default;
	//�f�X�g���N�^
	~TextManager() = default;

	//�R�s�[�R���X�g���N�^
	TextManager(const TextManager& rhs) = delete;
	//���[�u�R���X�g���N�^
	TextManager(const TextManager&& rhs) = delete;

	//������Z�q
	TextManager& operator=(const TextManager& rhs) = delete;
	TextManager& operator=(const TextManager&& rhs) = delete;

public:

	/*
	 * @brief TextManager�B��̃C���X�^���X
	 * 
	 * @return static TextManager& instance
	 */
	static TextManager& GetInstance(void);

	/*
	 * @brief �w��f�[�^��ǂݍ���
	 * 
	 * @param[in] LOAD_ID id ���[�h�^�C�v�w��
	 * @param[in] std::string load_data �f�[�^�w��
	 * 
	 */
	void Load(LOAD_ID id, std::string load_data);

	/*
	 * @brief �w��f�[�^�ɏ�������
	 *
	 * @param[in] SAVE_ID id �Z�[�u�^�C�v�w��
	 * @param[in] std::string save_target �f�[�^�w��
	 * @param[in] std::string entry_data �������ݓ��e
	 *
	 */
	void SaveAndCreate(SAVE_ID id, std::string save_target, std::string entry_data);

	/*
	 * @brief �w��f�[�^���R�s�[
	 *
	 * @param[in] COPY_ID id ����w��
	 * @param[in] std::string target_file �R�s�[��
	 * @param[in] std::string copy_file   �R�s�[��
	 *
	 */
	void Copy(COPY_ID id, std::string target_file, std::string copy_file);

	/*
	 * @brief ���[�h�����f�[�^���擾
	 * 
	 * @return std::list<std::string>
	 * 
	 */
	std::vector<std::string> GetLoadData(void);

	//���[�h���ĕێ����Ă���f�[�^���폜
	void DeleteLoadData(void);

	/*
	 * @brief �w�肵���e�L�X�g�t�@�C���̃f�[�^���폜
	 * 
	 * @param[in] std::string target �f�[�^�w��
	 * 
	 */
	void DeleteTextData(std::string target);

	/*
	 * @brief �w�肵���e�L�X�g�t�@�C�����폜
	 *
	 * @param[in] std::string target �f�[�^�w��
	 *
	 */
	void DeleteTextFile(std::string target);

private:

	/*
	 * @brief �f�����t�@�C���̃R�s�[(�R�s�[��̃f�[�^�͂��ׂď㏑������܂� ���R�s�[�ł�����E�PMB)
	 *
	 * @param[in] std::string target_file �R�s�[��
	 * @param[in] std::string copy_file   �R�s�[��
	 *
	 */
	void QuickCopy(std::string target_file, std::string copy_file);

	/*
	 * @brief �t�@�C���̃R�s�[(�R�s�[��̃f�[�^�͂��ׂď㏑������܂�)
	 *
	 * @param[in] std::string target_file �R�s�[��
	 * @param[in] std::string copy_file   �R�s�[��
	 *
	 */
	void NormalCopy(std::string target_file, std::string copy_file);

	/*
	 * @brief �R�s�[���̃f�[�^���R�s�[��ɘA��
	 *
	 * @param[in] std::string target_file �R�s�[��
	 * @param[in] std::string copy_file   �R�s�[��
	 *
	 */
	void ConnectCopyDestination(std::string target_file, std::string copy_file);

	/*
	 * @brief �R�s�[���̃f�[�^���R�s�[��̑O���ɒu��
	 *
	 * @param[in] std::string target_file �R�s�[��
	 * @param[in] std::string copy_file   �R�s�[��
	 *
	 */
	void CopyDataToTheTop(std::string target_file, std::string copy_file);

};

#define TEXTMANAGER TextManager::GetInstance()

#define DRAW_DEBUG_DATA false
