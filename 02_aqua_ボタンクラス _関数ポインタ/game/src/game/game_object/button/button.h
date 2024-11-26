#pragma once
#include"aqua.h"
#include <functional>

class CButton :public aqua::IGameObject
{
public:
	using CLICK_FUNCTION = std::function<void(void)>;

	struct BUTTON_INFO
	{
		aqua::CVector2 position = aqua::CVector2::ZERO;
		int width = m_min_button_size;
		int height = m_min_button_size;
		int font_size = m_default_font_size;
		std::string text = "ボタン";
		CLICK_FUNCTION on_click = [](){};
		
	};
	//コンストラクタ
	CButton(IGameObject* parent);
	//デストラクタ
	~CButton(void) = default;

	//初期化
	void Initialize(CLICK_FUNCTION on_click = [](){},
		const aqua::CVector2& position = aqua::CVector2::ZERO,
		int width = m_min_button_size,
		int height = m_min_button_size,
		int font_size = m_default_font_size,
		const std::string& text = "ボタン");



	//初期化
	void Initialize(const BUTTON_INFO& info);
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;
	//一回のクリック
	//void OnClick(void);
	
	/*
	void(*OnClick)(void);
	*/
	CLICK_FUNCTION OnClick;
	
	//位置を取得
	void SetPosition(const aqua::CVector2& position);
	//サイズ取得
	void SetSize(int width, int height);

private:

	/*
	*	@brief	レイアウト
	*/
	enum class LAYOUT_ID
	{
		UPPER_LEFT,		//左上
		UPPER_RIGHT,	//右上
		LOWER_LEFT,		//左下
		LOWER_RIGHT,	//右下
		LEFT,			//左
		UPPER,			//上
		RIGHT,			//右
		LOWER,			//下
		CENTER,			//中央
	};

	/*
	*	@brief	セットアップレクト
	*/
	void SetUpRect(void);

	/*
	*	@brief カラー設定
	*/
	void SetColor(const aqua::CColor& color);

	static const int			m_sprite_count;			//スプライトカウント
	static const int			m_corner_size;			//コーナーサイズ
	static const int			m_default_font_size;	//デフォルトフォントサイズ
	static const int			m_default_texture_size;	//デフォルトテクスチャサイズ

	static const unsigned int	m_default_color;		//デフォルトカラー
	static const unsigned int	m_selected_color;		//カーソルが乗っているときの色
	static const unsigned int	m_clicked_color;		//クリックされた時の色
	static const unsigned int	m_text_color;

	int							m_Width;				//幅
	int							m_Height;				//高さ

	aqua::CSprite*				m_Sprite;				//スプライトクラス
	aqua::CVector2				m_Position;				//位置
	aqua::CLabel				m_Text;					//テキスト
	aqua::CSoundPlayer			m_ExplosionSound;		//爆発サウンド
	

	static const int m_min_button_size;



};