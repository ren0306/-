//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitleBack.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjTitleBack::Init()
{
	m_up = false;
	m_down = false;
	m_start = false;
	m_end = false;


}

//アクション
void CObjTitleBack::Action()
{
}

//ドロー
void CObjTitleBack::Draw()
{
	float c[4] = { 1,1,1,1 };
	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置
	if (g_Count == 0)
	{
		//背景描画
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//描画
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	else if (g_Count == 1)
	{
		//背景描画
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1920.0f;
		src.m_bottom = 1080.0f;
		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//描画
		Draw::Draw(2, &src, &dst, c, 0.0f);

	}
}
