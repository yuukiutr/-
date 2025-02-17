#pragma once
#include "vivid.h"
//サウンドID

enum class SOUND_ID
{
	TITLE,				//タイトルBGM
	STAGESELECT,		//ステージセレクトBGM
	GAMEMAIN,			//ゲームメインBGM
	RESULT,				//リザルトBGM
	SELECT,				//選択音
	DECISION,			//決定音
	CANCEL,				//取り消し音
	BLAST,				//爆破音
	START,				//開始音
	RETRY,				//リトライ音
	GET_KEY,			//カギ獲得音
	DICE_MOVE,			//サイコロが転がる音
	GOAL,				//ゴールジングル

	MAX
};

class CSoundManager
{
public:
	//インスタンスの取得
	static CSoundManager& GetInstance(void);

	//サウンドの読み込み
	void Load(void);

	//サウンドの再生
	void Play(SOUND_ID id, bool loop = false);

	//サウンドの停止
	void StopSound(SOUND_ID id);

private:
	//コンストラクタ
	CSoundManager(void);
	
	//コピーコンストラクタ
	CSoundManager(const CSoundManager& rhs);

	//デストラクタ
	~CSoundManager(void);

	//代入演算子
	CSoundManager& operator=(const CSoundManager& rhs);

	//サウンドのファイル名
	static const char* m_sound_file_names[(int)SOUND_ID::MAX];
};
