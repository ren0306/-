//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjStar::CObjStar(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjStar::Init()
{
	m_GetStar = false;	//�����擾�ϐ��̏�����

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py,64, 64., ELEMENT_STAR, OBJ_STAR, 1);
}

//�A�N�V����
void CObjStar::Action()
{
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)//�������Ă�����擾
	{
		hit->SetInvincibility(true);	//�G����Ȃ�����
		m_GetStar = true;			//�擾�����ہA�F��ς���ׂɃt���O���I���ɂ���
		g_StarCount++;				//���ݎ擾���Ă��鐯�̐����J�E���g����

	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px + block->GetScrollx(), m_py + block->GetScrolly());

}

//�h���[
void CObjStar::Draw()
{
	//�`��J���[���
	float b[4] = { 0.4f,0.4f,0.4f,1.0f };	//�擾�ł��Ă��Ȃ��F
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };	//�擾�ł��Ă���F

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 640.0f;
	src.m_bottom = 608.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrolly();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left   = 0.0f + m_px + block->GetScrollx();
	dst.m_right  = 64.0f + m_px + block->GetScrollx();
	dst.m_bottom = 64.0f + m_py + block->GetScrolly();

	//�`��
	if(m_GetStar == false)
		Draw::Draw(6, &src, &dst, b, 0.0f);
	else
		Draw::Draw(6, &src, &dst, c, 0.0f);
}


