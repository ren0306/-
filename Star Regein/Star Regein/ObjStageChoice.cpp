//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"

#define Earthx 0
#define Earthxx 90
#define Earthy 380
#define Earthyy 600

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjStageChoice::Init()
{
	m_stage = false;
	m_key_flag = true;
}

//アクション
void CObjStageChoice::Action()
{
	float c[4] = { 1,1,1,1 };

	//主人公位置取得
	CObjStageChoiceHero* hero = (CObjStageChoiceHero*)Objs::GetObj(OBJ_STAGECHOICEHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	if (Input::GetVKey('Z') == true )
	{

		if (hx >= Earthx && hx <= Earthxx && hy >= Earthy&&hy <= Earthyy&&m_key_flag==false)
		{
			Font::StrDraw(L"Zキーでスタート", 280, 300, 10000, c);
			Scene::SetScene(new CSceneEarth());
		}

	}
	else
	{
		m_key_flag = false;
	}

}

//ドロー
void CObjStageChoice::Draw()
{


}
