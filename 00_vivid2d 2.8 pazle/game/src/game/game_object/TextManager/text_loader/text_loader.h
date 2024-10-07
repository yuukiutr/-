#pragma once

#include <fstream>
#include <list>
#include <vector>

//�e�L�X�g��ǂݍ���
class TextLoader
{
private:

	//���[�h�f�[�^���Ǘ�����list�̖��̒�`
	using DATA_LIST = std::vector<std::string>;

	//���[�h�f�[�^���Ǘ�����list
	DATA_LIST m_DataList;

public:

	/*
	 * @brief ���H�Ȃ����[�h
	 *
	 * @param[in] std::string data �f�[�^�w��
	 *
	 */
	void Load_Unprocessed(std::string data) noexcept;

	/*
	 * @brief �w��Ȃ����[�h
	 * 
	 * @param[in] std::string data �f�[�^�w��
	 * 
	 */
	void Load_All(std::string data) noexcept;

	/*
	 * @brief �����̂݃��[�h
	 *
	 * @param[in] std::string data �f�[�^�w��
	 *
	 */
	void Load_OnlyNumeric(std::string data) noexcept;

	/*
	 * @brief �A���t�@�x�b�g�̂݃��[�h
	 *
	 * @param[in] std::string data �f�[�^�w��
	 *
	 */
	void Load_OnlyAlphabet(std::string data) noexcept;

	/*
	 * @brief ���{��̂݃��[�h
	 *
	 * @param[in] std::string data �f�[�^�w��
	 *
	 */
	void Load_OnlyJapanese(std::string data) noexcept;

	/*
	 * @brief �A���t�@�x�b�g�Ɛ����̂݃��[�h
	 *
	 * @param[in] std::string data �f�[�^�w��
	 *
	 */
	void Load_AlphabetAndNumeric(std::string data) noexcept;

	/*
	 * @brief ���[�h�f�[�^���擾
	 * 
	 * @return std::list<std::string>
	 * 
	 */
	std::vector<std::string>GetLoadData(void);

	//���[�h���ĕێ����Ă���f�[�^���폜
	void DeleteLoadData(void);

	long double to_long_double(std::string str);

};