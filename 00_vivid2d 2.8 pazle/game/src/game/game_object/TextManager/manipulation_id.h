#pragma once

//ロードの操作
enum class LOAD_ID
{
	//数値のみ
	ONLY_NUMERIC,
	//アルファベットのみ
	ONLY_ALPHABET,
	//日本語のみ
	ONLY_JAPANESE,
	//数値とアルファベットのみ
	ALPHABET_AND_NUMERIC,
	//すべて
	ALL,

	//例外処理
	DUMMY
};

//セーブの操作
enum class SAVE_ID
{
	//生成
	CREATE,
	//上書き
	OVERWRITING,
	//追記
	PS,

	DUMMY
};

//コピーの操作
enum class COPY_ID
{
	//上書き
	NORMAL,
	//素早く(上書き 1MBまで)
	QUICK,
	//後ろに連結
	CONNECT_BOTTOM,
	//前に連結
	CONNECT_TOP,


	DUMMY
};
