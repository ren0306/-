//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjHero.h"

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
		m_posture = POS_UP;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_DOWN))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vy += m_speed_power;
		m_posture = POS_DOWN;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_LEFT))//���L�[�i���j�����͂��ꂽ�Ƃ�
	{
		m_vx -= m_speed_power;
		m_posture = POS_LEFT;
		m_ani_time += ANITIME;
	}
	else if (Input::GetVKey(VK_RIGHT))//���L�[�i�E�j�����͂��ꂽ�Ƃ�
	{
		m_vx += m_speed_power;
		m_posture = POS_RIGHT;
		m_ani_time += ANITIME;
	}

	if (Input::GetVKey('Z'))
	{
		//�r�[���T�[�x���I�u�W�F�N�g�쐬
		CObjBeamSaber* objb = new CObjBeamSaber(m_px + 14, m_py + 50);
		Objs::InsertObj(objb, OBJ_BEAMSABER, 2);
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

	//��ʊO�ɏo�Ȃ��悤�ɂ��鏈��
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
