#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneEarth :public CScene
{
	public:
		CSceneEarth();
		~CSceneEarth();
		void InitScene(); //初期化メソッド
		void Scene();     //実行中メソッド
	private:
		int m_memory;	//星の数の加算を計る変数
		int m_time;	//メッセージ表示時間
		wchar_t STAR[128];	//星の数を数えるメッセージ用
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };	//メッセージフォントカラー

};

