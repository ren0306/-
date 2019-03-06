//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"

#define Earthx 300
#define Earthy 400

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjStageChoice::Init()
{

}

//アクション
void CObjStageChoice::Action()
{
	//主人公位置取得
	CObjStageChoiceHero* hero = (CObjStageChoiceHero*)Objs::GetObj(OBJ_STAGECHOICEHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//指定の場所でZキーでスタート
	if (hx >= Earthx && hy <= Earthy)
	{
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
