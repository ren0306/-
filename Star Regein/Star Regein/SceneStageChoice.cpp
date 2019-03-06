//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "GameHead.h"
#include "SceneStageChoice.h"

//コンストラクタ
CSceneStageChoice::CSceneStageChoice()
{
	g_Count = 1;
}

//デストラクタ
CSceneStageChoice::~CSceneStageChoice()
{

}

//ゲームタイトル初期化メソッド
void CSceneStageChoice::InitScene()
{
	//画像読み込み--------------------------------------
	Draw::LoadImageW(L"ステージ選択.png", 2, TEX_SIZE_2048);
	Draw::LoadImageW(L"HeroTouka.png", 3, TEX_SIZE_512);
	//--------------------------------------------------

	

	//ステージ選択オブジェクト作成----------------------------
	CObjStageChoice* o = new CObjStageChoice();
	Objs::InsertObj(o, OBJ_STAGECHOICE, 100);
	//--------------------------------------------------------
	//ステージ選択用ヒーローオブジェクト作成------------------
	CObjStageChoiceHero* oh = new CObjStageChoiceHero(0, 500);
	Objs::InsertObj(oh, OBJ_STAGECHOICEHERO, 10);
	//--------------------------------------------------------
	//背景オブジェクト作成←タイトルの背景から持ってきたやつ--
	CObjTitleBack* obb = new CObjTitleBack();
	Objs::InsertObj(obb, OBJ_TITLEBACK, 0);
	//--------------------------------------------------------

}

//ゲームタイトル実行中メソッド
void CSceneStageChoice::Scene()
{

}
