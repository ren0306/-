//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHero.h"

//�����ʒu
#define POTISION_X 100
#define POTISION_Y 100
//�ړ���
#define SPEEDPOWER 2.0
//�A�j���[�V�����p
#define ANITIME 1

//��l���̌���
#define POS_UP 1    //��
#define POS_DOWN 2  //��
#define POS_LEFT 3  //��
#define POS_RIGHT 4 //�E


//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjHero::Init()
{
	//�������X
	m_px = POTISION_X;
	m_py = POTISION_Y;

	//�����p��
	m_posture = POS_DOWN;

	m_ani_time = 0;
	m_ani_frame = 1;
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (Input::GetVKey(VK_UP))//���L�[�i��j�����͂��ꂽ�Ƃ�
	{
		m_vy -= SPEEDPOWER;
		m_posture = POS_UP;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_DOWN))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vy += SPEEDPOWER;
		m_posture = POS_DOWN;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_LEFT))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vx -= SPEEDPOWER;
		m_posture = POS_LEFT;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_RIGHT))//���L�[�i�E�j�����͂��ꂽ�Ƃ�
	{
		m_vx += SPEEDPOWER;
		m_posture = POS_RIGHT;
		m_ani_time += ANITIME;
	}


		//�A�j���[�V�����p
	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}


	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}



//�h���[
void CObjHero::Draw()
{
	//�A�j���[�V����
	int AniData[5] =
	{
		0,1,2,3,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				
	if (m_posture == POS_UP)//���L�[�i��j�����͂��ꂽ�Ƃ�
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 192.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 256.0f;
	}
	else if (m_posture == POS_DOWN)//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 64.0f;
	}
	else if (m_posture == POS_LEFT)//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 128.0f;
		
	}
	else if (m_posture == POS_RIGHT)//���L�[�i�E�j�����͂��ꂽ�Ƃ�
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 64;
		src.m_right = 64.0f + AniData[m_ani_frame] * 64;
		src.m_bottom = 192.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�\��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}
