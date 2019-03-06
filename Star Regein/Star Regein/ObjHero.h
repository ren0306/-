#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//-------�萔------------------------

//�A�j���[�V�����p
#define ANITIME 1

//�_�b�V�����x
#define DASH_SPEED 5.0
//�ʏ푬�x
#define NORMAL_SPEED 3.0

//-------------------------------------
//�I�u�W�F�N�g:��l��
class CObjHero :public CObj
{
public:
	CObjHero(float x, float y) ;
	~CObjHero() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

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

	int m_time;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

};


