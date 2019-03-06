//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitleBack.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjTitleBack::Init()
{
	m_up = false;
	m_down = false;
	m_start = false;
	m_end = false;


}

//�A�N�V����
void CObjTitleBack::Action()
{
}

//�h���[
void CObjTitleBack::Draw()
{
	float c[4] = { 1,1,1,1 };
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu
	if (g_Count == 0)
	{
		//�w�i�`��
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//�`��
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	else if (g_Count == 1)
	{
		//�w�i�`��
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1920.0f;
		src.m_bottom = 1080.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//�`��
		Draw::Draw(2, &src, &dst, c, 0.0f);

	}
}
