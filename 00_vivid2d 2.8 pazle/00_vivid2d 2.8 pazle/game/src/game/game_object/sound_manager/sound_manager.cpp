#include "sound_manager.h"

const char* CSoundManager::m_sound_file_names[] =
{
	"data\\se\\AS_143571_シンセ／落ち着いた曲調／おしゃれな雰囲気.mp3",
	"data\\se\\AS_823312_BGM_ステージセレクトA.mp3",
	"data\\se\\AS_119380_テーブルゲーム＿パズルと思考の大作戦.mp3",
	"data\\se\\AS_1536262_パズルゲームのリザルト画面曲.mp3",
	"data\\se\\AS_890909_選択音.mp3",
	"data\\se\\AS_890893_決定音.mp3",
	"data\\se\\AS_1080800_キャンセル／メニュー／戻る／ネガティブ.mp3",
	"data\\se\\AS_215480_爆発・大砲7：至近距離、短い爆発・破裂.mp3",
	"data\\se\\AS_224094_チャラララ（ピコピコ／テクノ／イベント.mp3",
	"data\\se\\AS_1467764_ピコッ・カチッ・決定・テロップ・ポップ6.mp3",
	"data\\se\\AS_39629_キランというかわいいSEです。.mp3",
	"data\\se\\AS_1534404_カン（小皿を置く音）007.mp3",

};

//インスタンスの取得
CSoundManager& CSoundManager::GetInstance(void)
{
	static CSoundManager instance;
	
	return instance;
}

//読み込み
void CSoundManager::Load(void)
{
	for (int i = 0; i < (int)SOUND_ID::MAX; i++)
	{
		vivid::LoadSound(m_sound_file_names[i]);
	}
}

//再生
void CSoundManager::Play(SOUND_ID id, bool loop)
{
	vivid::PlaySound(m_sound_file_names[(int)id], loop);
}

void CSoundManager::StopSound(SOUND_ID id)
{
	vivid::StopSound(m_sound_file_names[(int)id]);
}

//コンストラクタ
CSoundManager::CSoundManager(void)
{
}

//コピーコンストラクタ
CSoundManager::CSoundManager(const CSoundManager& rhs)
{
	(void) rhs;
}

//デストラクタ
CSoundManager::~CSoundManager(void)
{
}

CSoundManager& CSoundManager::operator=(const CSoundManager& rhs)
{
	(void)rhs;
	return *this;
}
