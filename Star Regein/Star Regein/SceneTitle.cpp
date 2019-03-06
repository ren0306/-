//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "GameHead.h"
#include "SceneTitle.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{
}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{
}

//�Q�[���^�C�g�����������\�b�h
void CSceneTitle::InitScene()
{
	//�摜�ǂݍ���
	Draw::LoadImageW(L"SpaceBack.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Title.png", 2, TEX_SIZE_512);
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

	//�^�C�g���o�b�N�I�u�W�F�N�g�쐬
	CObjTitleBack* obb = new CObjTitleBack();
	Objs::InsertObj(obb, OBJ_TITLEBACK, 0);

}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneTitle::Scene()
{

}
