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
}

//�A�N�V����
void CObjTitle::Action()
{
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };
	flag flag = {5,5,5};
	if (Input::GetVKey(VK_UP) == true)
	{
		flag.m_up = true;
		flag.m_down = false;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		flag.m_down = true;
		flag.m_up = false;
	}

	if (flag.m_up == true)
	{
		Font::StrDraw(L"���Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"�Q�[���I��", 280, 340, 32, c);

	}
	else if (flag.m_down == true)
	{
		Font::StrDraw(L"�Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"���Q�[���I��", 280, 340, 32, c);

	}
	else
	{
		Font::StrDraw(L"�Q�[���X�^�[�g", 280, 300, 32, c);
		Font::StrDraw(L"�Q�[���I��", 280, 340, 32, c);
	}


}
