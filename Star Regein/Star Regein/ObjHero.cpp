//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;





//イニシャライズ
void CObjHero::Init()
{
	//初期リス
	m_px = POTISION_X;
	m_py = POTISION_Y;

	//初期姿勢
	m_posture = POS_DOWN;

	m_ani_time = 0;
	m_ani_frame = 1;

	
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//Shiftキーが入力されたらダッシュ
	if ((Input::GetVKey(VK_SHIFT)))
	{
		m_speed_power = DASH_SPEED;
	}
	else//通常速度
	{
		m_speed_power = NORMAL_SPEED;
	}

	if (Input::GetVKey(VK_UP))//矢印キー（上）が入力されたとき
	{
		m_vy -= m_speed_power;
		m_posture = POS_UP;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_DOWN))//矢印キー（下）が入力されたとき
	{
		m_vy += m_speed_power;
		m_posture = POS_DOWN;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_LEFT))//矢印キー（左）が入力されたとき
	{
		m_vx -= m_speed_power;
		m_posture = POS_LEFT;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_RIGHT))//矢印キー（右）が入力されたとき
	{
		m_vx += m_speed_power;
		m_posture = POS_RIGHT;
		m_ani_time += ANITIME;
	}

	if (Input::GetVKey('Z'))
	{
		//ビームサーベルオブジェクト作成
		CObjBeamSaber* objb = new CObjBeamSaber(m_px + 14, m_py + 50);
		Objs::InsertObj(objb, OBJ_BEAMSABER, 2);
	}


	//アニメーション用
	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//画面外に出ないようにする処理
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}
	else if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}
	else if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	else if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}


	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
}



//ドロー
void CObjHero::Draw()
{
	//アニメーション
	int AniData[5] =
	{
		0,1,2,3,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				
	if (m_posture == POS_UP)//矢印キー（上）が入力されたとき
	{
		//切り取り位置の設定
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;
	}
	else if (m_posture == POS_DOWN)//矢印キー（下）が入力されたとき
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;
	}
	else if (m_posture == POS_LEFT)//矢印キー（左）が入力されたとき
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;
		
	}
	else if (m_posture == POS_RIGHT)//矢印キー（右）が入力されたとき
	{
		//切り取り位置の設定
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;
	}

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//表示
	Draw::Draw(1, &src, &dst, c, 0.0f);
}
