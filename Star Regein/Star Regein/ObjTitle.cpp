//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_up=false;
	m_down=false;
	m_start=false;
	m_end=false;


}

//�A�N�V����
void CObjTitle::Action()
{
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };
	//��L�[���������Ƃ�
	if (Input::GetVKey(VK_UP) == true)
	{
		m_up = true;
		m_down = false;

	}
	//���L�[���������Ƃ�
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_down = true;
		m_up = false;
	}
	//�Q�[���J�n
	if (m_start == true)
	{
		Scene::SetScene(new CSceneStageChoice());
	}
	//�Q�[���I��
	if (m_end == true)
	{
		exit(4);
	}
	//�J�[�\��������
	if (m_up == true)
	{
		Font::StrDraw(L"���Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"�Q�[���I��", 280, 340, 32, c);
		//�y�L�[�Ŏn�߂�
		if (Input::GetVKey('Z') == true)
		{
			m_start = true;
		}

	}
	else if (m_down == true)
	{
		Font::StrDraw(L"�Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"���Q�[���I��", 280, 340, 32, c);
		//Z�L�[�ŏI���
		if (Input::GetVKey('Z') == true)
		{
			m_end = true;
		}


	}
	//�n�߂͂��̏��
	else
	{
		Font::StrDraw(L"�Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"�Q�[���I��", 280, 340, 32, c);
	}


	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top =0.0f;
	src.m_left = 0.0f;
	src.m_right = 554.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 200.0f ;
	dst.m_left = 120.0f;
	dst.m_right = 674.0f;
	dst.m_bottom = 232.0f;

	//�\��
	Draw::Draw(2, &src, &dst, c, 0.0f);

}
