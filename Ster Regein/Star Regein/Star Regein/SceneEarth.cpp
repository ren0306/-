//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneEarth.h"
#include "GameHead.h"

//コンストラクタ
CSceneEarth::CSceneEarth()
{

}

//デストラクタ
CSceneEarth::~CSceneEarth()
{

}

//初期化メソッド
void CSceneEarth::InitScene()
{
	//外部データ読み込み（ステージ情報）
	unique_ptr<wchar_t> p;	//ステージ情報ポインター
	int size;				//ステージ情報の大きさ
	//p = Save::ExternalDataOpen(L"Earth.csv", &size);//外部データ読み込み
	p = Save::ExternalDataOpen(L"test.csv", &size);//外部データ読み込み

	int map[29][29];
	int count = 1;
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);
			map[i][j] = w;
			if (w >= 10)
			{
				count += 1;
			}
			count += 2;
		}
	}


	//グラフィック読み込み
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"SpaceBack.jpg", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"牛.png", 3, TEX_SIZE_512);


	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 1);

}


//実行中メソッド
void CSceneEarth::Scene()
{

}