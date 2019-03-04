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
}

//アクション
void CObjTitle::Action()
{
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };
	flag flag = {5,5,5};
	if (Input::GetVKey(VK_UP) == true)
	{
		flag.m_up = true;
		flag.m_down = false;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		flag.m_down = true;
		flag.m_up = false;
	}

	if (flag.m_up == true)
	{
		Font::StrDraw(L"→ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"ゲーム終了", 280, 340, 32, c);

	}
	else if (flag.m_down == true)
	{
		Font::StrDraw(L"ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"→ゲーム終了", 280, 340, 32, c);

	}
	else
	{
		Font::StrDraw(L"ゲームスタート", 280, 300, 32, c);
		Font::StrDraw(L"ゲーム終了", 280, 340, 32, c);
	}


}
