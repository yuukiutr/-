#pragma once
#include <fstream>

//テキストに書き込み
class TextWriter
{
public:

	/*
	 * @brief 指定データを上書き
	 *
	 * @param[in] std::string write_target データ指定
	 * @param[in] std::string entry_data 書き込み内容
	 *
	 */
	void OverWriting(std::string write_target,std::string entry_data);

	/*
	 * @brief 指定データに追記
	 *
	 * @param[in] std::string write_target データ指定
	 * @param[in] std::string entry_data 書き込み内容
	 *
	 */
	void PostScript(std::string write_target, std::string entry_data);

	/*
	 * @brief 指定したテキストファイルのデータを削除
	 *
	 * @param[in] std::string delete_target データ指定
	 *
	 */
	void DeleteTextData(std::string delete_target);
};
