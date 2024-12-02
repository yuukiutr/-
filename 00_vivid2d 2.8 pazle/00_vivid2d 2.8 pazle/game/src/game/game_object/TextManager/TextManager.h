#pragma once

#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "manipulation_id.h"
#include "text_loader/text_loader.h"
#include "text_writer/text_writer.h"

//テキスト管理
class TextManager
{
private:

	//インスタンス
	TextLoader m_Loader;
	TextWriter m_Writer;

	//コンストラクタ
	TextManager() = default;
	//デストラクタ
	~TextManager() = default;

	//コピーコンストラクタ
	TextManager(const TextManager& rhs) = delete;
	//ムーブコンストラクタ
	TextManager(const TextManager&& rhs) = delete;

	//代入演算子
	TextManager& operator=(const TextManager& rhs) = delete;
	TextManager& operator=(const TextManager&& rhs) = delete;

public:

	/*
	 * @brief TextManager唯一のインスタンス
	 * 
	 * @return static TextManager& instance
	 */
	static TextManager& GetInstance(void);

	/*
	 * @brief 指定データを読み込み
	 * 
	 * @param[in] LOAD_ID id ロードタイプ指定
	 * @param[in] std::string load_data データ指定
	 * 
	 */
	void Load(LOAD_ID id, std::string load_data);

	/*
	 * @brief 指定データに書き込み
	 *
	 * @param[in] SAVE_ID id セーブタイプ指定
	 * @param[in] std::string save_target データ指定
	 * @param[in] std::string entry_data 書き込み内容
	 *
	 */
	void SaveAndCreate(SAVE_ID id, std::string save_target, std::string entry_data);

	/*
	 * @brief 指定データをコピー
	 *
	 * @param[in] COPY_ID id 動作指定
	 * @param[in] std::string target_file コピー先
	 * @param[in] std::string copy_file   コピー元
	 *
	 */
	void Copy(COPY_ID id, std::string target_file, std::string copy_file);

	/*
	 * @brief ロードしたデータを取得
	 * 
	 * @return std::list<std::string>
	 * 
	 */
	std::vector<std::string> GetLoadData(void);

	//ロードして保持しているデータを削除
	void DeleteLoadData(void);

	/*
	 * @brief 指定したテキストファイルのデータを削除
	 * 
	 * @param[in] std::string target データ指定
	 * 
	 */
	void DeleteTextData(std::string target);

	/*
	 * @brief 指定したテキストファイルを削除
	 *
	 * @param[in] std::string target データ指定
	 *
	 */
	void DeleteTextFile(std::string target);

private:

	/*
	 * @brief 素早いファイルのコピー(コピー先のデータはすべて上書きされます ※コピーできる限界１MB)
	 *
	 * @param[in] std::string target_file コピー先
	 * @param[in] std::string copy_file   コピー元
	 *
	 */
	void QuickCopy(std::string target_file, std::string copy_file);

	/*
	 * @brief ファイルのコピー(コピー先のデータはすべて上書きされます)
	 *
	 * @param[in] std::string target_file コピー先
	 * @param[in] std::string copy_file   コピー元
	 *
	 */
	void NormalCopy(std::string target_file, std::string copy_file);

	/*
	 * @brief コピー元のデータをコピー先に連結
	 *
	 * @param[in] std::string target_file コピー先
	 * @param[in] std::string copy_file   コピー元
	 *
	 */
	void ConnectCopyDestination(std::string target_file, std::string copy_file);

	/*
	 * @brief コピー元のデータをコピー先の前方に置く
	 *
	 * @param[in] std::string target_file コピー先
	 * @param[in] std::string copy_file   コピー元
	 *
	 */
	void CopyDataToTheTop(std::string target_file, std::string copy_file);

};

#define TEXTMANAGER TextManager::GetInstance()

#define DRAW_DEBUG_DATA false
