//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjStageChoiceHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjStageChoiceHero::CObjStageChoiceHero(float x, float y)
{//�I�u�W�F�쐬���ɓn���ꂽx,y���W�������o�ϐ��ɑ��
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjStageChoiceHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	//�����p��
	m_posture = 0;

	m_ani_time = 0;
	m_ani_frame = 1;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

}

//�A�N�V����
void CObjStageChoiceHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//Shift�L�[�����͂��ꂽ��_�b�V��
	if ((Input::GetVKey(VK_SHIFT)))
	{
		m_speed_power = DASH_SPEED;
	}
	else//�ʏ푬�x
	{
		m_speed_power = NORMAL_SPEED;
	}

	if (Input::GetVKey(VK_UP))//���L�[�i��j�����͂��ꂽ�Ƃ�
	{
		m_vy -= m_speed_power;
		m_posture = 3;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_DOWN))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vy += m_speed_power;
		m_posture = 0;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_LEFT))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vx -= m_speed_power;
		m_posture = 2;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_RIGHT))//���L�[�i�E�j�����͂��ꂽ�Ƃ�
	{
		m_vx += m_speed_power;
		m_posture = 1;
		m_ani_time += ANITIME;
	}
	else//�ړ��L�[�̓��͂������ꍇ
	{
		m_ani_frame = 0;	//�Î~�t���[���ɂ���
		m_ani_time = 0;		//�A�j���[�V�������ԃ��Z�b�g
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

	//��l���@���̈�O�s���Ȃ�����
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (m_py + 32.0f > 600.0f)
	{
		m_py = 600.0f - 32.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
}

//�h���[
void CObjStageChoiceHero::Draw()
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


	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f * m_posture;
	src.m_left = 0.0f + (AniData[m_ani_frame] * 64);
	src.m_right = 64.0f + (AniData[m_ani_frame] * 64);
	src.m_bottom = src.m_top + 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 64.0f + m_px;
	dst.m_right = 0.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�\��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}
