//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

int g_StarCount = 0;	//���𐔂���ϐ��̏�����

//�g�p�w�b�_�[
#include "SceneEarth.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneEarth::CSceneEarth()
{
	m_memory = 0;	//���̐����v��ϐ��̏�����
	m_time = 0;		//���b�Z�[�W���ԗp�̕ϐ��̏�����
}

//�f�X�g���N�^
CSceneEarth::~CSceneEarth()
{

}

//���������\�b�h
void CSceneEarth::InitScene()
{
	//�O���f�[�^�ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p;	//�X�e�[�W���|�C���^�[
	int size;				//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Earth.csv", &size);//�O���f�[�^�ǂݍ���

	int map[29][29];
	int count = 1;
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);
			map[i][j] = w;
			if (w >= 10)
			{
				count += 1;
			}
			count += 2;
		}
	}


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�r�[���T�[�x��.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"��.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"覐�.png", 4, TEX_SIZE_64);
	Draw::LoadImageW(L"SpaceBack.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"��.png", 6, TEX_SIZE_1024);

	
	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 1);

}


//���s�����\�b�h
void CSceneEarth::Scene()
{
	//�e�X�g�i�n���Ő���5�W�߂��玟�ֈڍs�j
	if (g_StarCount == 5)
	{
		Scene::SetScene(new CSceneMain());	//�Q�[�����C���V�[���Ɉڍs
	}
	//���̃J�E���g���������ꍇ
	if (g_StarCount > m_memory)	
	{
		m_time++;	//time���v���X���Ă��鎞�������b�Z�[�W��\��
		swprintf_s(STAR, L"%d�ڂ̐����擾�A�c��%d�I",g_StarCount,5 - g_StarCount);
		Font::StrDraw(STAR, 0, 0, 25, c);//HP��\��
		if (m_time == 100) {
			m_memory = g_StarCount;	//���݂̐��̐�����
			m_time = 0;	//time�̏�����
		}
	}
}