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
}

//アクション
void CObjStageChoice::Action()
{
	float c[4] = { 1,1,1,1 };

	//主人公位置取得
	CObjStageChoiceHero* hero = (CObjStageChoiceHero*)Objs::GetObj(OBJ_STAGECHOICEHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//指定の場所でZキーでスタート
	if (hx >= Earthx && hx <= Earthxx && hy >= Earthy&&hy <= Earthyy)
	{
		Font::StrDraw(L"Zキーでスタート", 280, 300, 10000, c);
		if (Input::GetVKey('Z') == true)
		{
			Scene::SetScene(new CSceneEarth());
		}
	}
}

//ドロー
void CObjStageChoice::Draw()
{


}
