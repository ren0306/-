//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMessage.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMessage::Init()
{
	m_memory = 0;	//���̐����v��ϐ��̏�����
	m_time = 0;		//���b�Z�[�W���ԗp�̕ϐ��̏�����

	m_MaxStar = 5;	//���̍ő�̐��̏������i�������W�߂�ꏊ�ɂ���ĕω��j
}

//�A�N�V����
void CObjMessage::Action()
{
	
}

//�h���[
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,0.4f,1.0f };	//���b�Z�[�W�t�H���g�J���[

	wchar_t STAR[128];	//���̐��𐔂��郁�b�Z�[�W�p

	//���̃J�E���g���������ꍇ
	if (g_StarCount > m_memory)
	{
		m_time++;	//time���v���X���Ă��鎞�������b�Z�[�W��\��
		swprintf_s(STAR, L"%d�ڂ́����擾�A�c��%d�I", g_StarCount, m_MaxStar - g_StarCount);
		Font::StrDraw(STAR, 150, 240, 25, c);//HP��\��
		if (m_time == 100) {
			m_memory = g_StarCount;	//���݂̐��̐�����
			m_time = 0;	//time�̏�����
		}
	}
}
