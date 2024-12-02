#pragma once

#include <fstream>
#include <list>
#include <vector>

//テキストを読み込み
class TextLoader
{
private:

	//ロードデータを管理するlistの名称定義
	using DATA_LIST = std::vector<std::string>;

	//ロードデータを管理するlist
	DATA_LIST m_DataList;

public:

	/*
	 * @brief 加工なしロード
	 *
	 * @param[in] std::string data データ指定
	 *
	 */
	void Load_Unprocessed(std::string data) noexcept;

	/*
	 * @brief 指定なしロード
	 * 
	 * @param[in] std::string data データ指定
	 * 
	 */
	void Load_All(std::string data) noexcept;

	/*
	 * @brief 数字のみロード
	 *
	 * @param[in] std::string data データ指定
	 *
	 */
	void Load_OnlyNumeric(std::string data) noexcept;

	/*
	 * @brief アルファベットのみロード
	 *
	 * @param[in] std::string data データ指定
	 *
	 */
	void Load_OnlyAlphabet(std::string data) noexcept;

	/*
	 * @brief 日本語のみロード
	 *
	 * @param[in] std::string data データ指定
	 *
	 */
	void Load_OnlyJapanese(std::string data) noexcept;

	/*
	 * @brief アルファベットと数字のみロード
	 *
	 * @param[in] std::string data データ指定
	 *
	 */
	void Load_AlphabetAndNumeric(std::string data) noexcept;

	/*
	 * @brief ロードデータを取得
	 * 
	 * @return std::list<std::string>
	 * 
	 */
	std::vector<std::string>GetLoadData(void);

	//ロードして保持しているデータを削除
	void DeleteLoadData(void);

	long double to_long_double(std::string str);

};