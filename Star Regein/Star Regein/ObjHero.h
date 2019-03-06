#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//-------定数------------------------
//初期位置
#define POTISION_X 100
#define POTISION_Y 100

//アニメーション用
#define ANITIME 1

//ダッシュ速度
#define DASH_SPEED 5.0
//通常速度
#define NORMAL_SPEED 3.0

//主人公の向き
#define POS_UP 1    //上
#define POS_DOWN 2  //下
#define POS_LEFT 3  //左
#define POS_RIGHT 4 //右

//-------------------------------------
//オブジェクト:主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

private:
	float m_px;  //位置
	float m_py;
	float m_vx;  //移動ベクトル
	float m_vy;
	float m_posture; //姿勢

	float m_speed_power; //スピードパワー

	int m_ani_time; //アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	int m_f;//攻撃制御用

	int m_time = 0;


};


