#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//定数
#define MAPSIZE 29

//オブジェクト：ブロック＆背景
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[MAPSIZE][MAPSIZE]);
		~CObjBlock() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		int m_map[MAPSIZE][MAPSIZE];	//マップ情報

};