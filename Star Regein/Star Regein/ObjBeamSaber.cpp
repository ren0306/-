//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "ObjBeamSaber.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�g���N�^
CObjBeamSaber::CObjBeamSaber(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBeamSaber::Init()
{

}

//�A�N�V����
void CObjBeamSaber::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�ʒu�̍X�V
	m_x = hx+14;
	m_y = hy+32;
}

//�h���[
void CObjBeamSaber::Draw()
{


	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 64.0f;

	
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right = 32.0f+m_x;
	dst.m_bottom = 32.0f+m_y;

	//�\��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}
