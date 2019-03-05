//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[MAPSIZE][MAPSIZE])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(MAPSIZE * MAPSIZE));
}

//イニシャライズ
void CObjBlock::Init()
{

}

//アクション
void CObjBlock::Action()
{
	//出現
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			//列の中からを探す
			if (m_map[i][j] == 1)
			{

			}
			if (m_map[i][j] == 2)
			{

			}
		}
	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 800.0f;
	src.m_bottom = 600.0f;

	//表示位置の設定
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}


