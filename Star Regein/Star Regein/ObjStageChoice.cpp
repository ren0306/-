//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"




//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjStageChoice::Init()
{
	m_right = false;
	m_left = false;
	m_start = false;
	m_end = false;


}

//アクション
void CObjStageChoice::Action()
{
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_right = true;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_left = true;
	}

	


}

//ドロー
void CObjStageChoice::Draw()
{
	float c[4] = { 1,1,1,1 };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 64.0f ;
	dst.m_bottom = 64.0f ;


}
