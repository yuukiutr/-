#pragma once
#include <fstream>

//�e�L�X�g�ɏ�������
class TextWriter
{
public:

	/*
	 * @brief �w��f�[�^���㏑��
	 *
	 * @param[in] std::string write_target �f�[�^�w��
	 * @param[in] std::string entry_data �������ݓ��e
	 *
	 */
	void OverWriting(std::string write_target,std::string entry_data);

	/*
	 * @brief �w��f�[�^�ɒǋL
	 *
	 * @param[in] std::string write_target �f�[�^�w��
	 * @param[in] std::string entry_data �������ݓ��e
	 *
	 */
	void PostScript(std::string write_target, std::string entry_data);

	/*
	 * @brief �w�肵���e�L�X�g�t�@�C���̃f�[�^���폜
	 *
	 * @param[in] std::string delete_target �f�[�^�w��
	 *
	 */
	void DeleteTextData(std::string delete_target);
};
