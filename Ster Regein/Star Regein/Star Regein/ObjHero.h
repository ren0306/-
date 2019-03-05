#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//-------�萔------------------------
//�����ʒu
#define POTISION_X 100
#define POTISION_Y 100

//�A�j���[�V�����p
#define ANITIME 1

//�_�b�V�����x
#define DASH_SPEED 5.0
//�ʏ푬�x
#define NORMAL_SPEED 3.0

//��l���̌���
#define POS_UP 1    //��
#define POS_DOWN 2  //��
#define POS_LEFT 3  //��
#define POS_RIGHT 4 //�E

//-------------------------------------
//�I�u�W�F�N�g:��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

private:
	float m_px;  //�ʒu
	float m_py;
	float m_vx;  //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��

	float m_speed_power; //�X�s�[�h�p���[

	int m_ani_time; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	int m_f;//�U������p

	int m_time = 0;


};


