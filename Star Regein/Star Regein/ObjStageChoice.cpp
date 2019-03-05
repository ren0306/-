//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjStageChoice::Init()
{
	m_right = false;
	m_left = false;
	m_start = false;
	m_end = false;


}

//�A�N�V����
void CObjStageChoice::Action()
{
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_right = true;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_left = true;
	}

	


}

//�h���[
void CObjStageChoice::Draw()
{
	float c[4] = { 1,1,1,1 };
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 64.0f ;
	dst.m_bottom = 64.0f ;


}
