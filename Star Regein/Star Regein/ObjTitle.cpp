//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjTitle::Init()
{
	m_up=false;
	m_down=false;
	m_start=false;
	m_end=false;


}

//アクション
void CObjTitle::Action()
{
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };
	//上キーを押したとき
	if (Input::GetVKey(VK_UP) == true)
	{
		m_up = true;
		m_down = false;

	}
	//下キーを押したとき
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_down = true;
		m_up = false;
	}
	//ゲーム開始
	if (m_start == true)
	{
		Scene::SetScene(new CSceneStageChoice());
	}
	//ゲーム終了
	if (m_end == true)
	{
		exit(4);
	}
	//カーソルが動く
	if (m_up == true)
	{
		Font::StrDraw(L"→ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"ゲーム終了", 280, 340, 32, c);
		//Ｚキーで始める
		if (Input::GetVKey('Z') == true)
		{
			m_start = true;
		}

	}
	else if (m_down == true)
	{
		Font::StrDraw(L"ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"→ゲーム終了", 280, 340, 32, c);
		//Zキーで終わる
		if (Input::GetVKey('Z') == true)
		{
			m_end = true;
		}


	}
	//始めはこの状態
	else
	{
		Font::StrDraw(L"ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"ゲーム終了", 280, 340, 32, c);
	}


	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	//切り取り位置の設定
	src.m_top =0.0f;
	src.m_left = 0.0f;
	src.m_right = 554.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 200.0f ;
	dst.m_left = 120.0f;
	dst.m_right = 674.0f;
	dst.m_bottom = 232.0f;

	//表示
	Draw::Draw(2, &src, &dst, c, 0.0f);

}
