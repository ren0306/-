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
#include "SceneStageChoice.h"

//�R���X�g���N�^
CSceneStageChoice::CSceneStageChoice()
{

}

//�f�X�g���N�^
CSceneStageChoice::~CSceneStageChoice()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneStageChoice::InitScene()
{
	//�摜�ǂݍ���--------------------------------------
	Draw::LoadImageW(L"SpaceBack.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"HeroTouka.png", 2, TEX_SIZE_512);
	//--------------------------------------------------

	

	//�X�e�[�W�I���I�u�W�F�N�g�쐬----------------------------
	CObjStageChoice* o = new CObjStageChoice();
	Objs::InsertObj(o, OBJ_STAGECHOICE, 10);
	//--------------------------------------------------------
	//�X�e�[�W�I��p�q�[���[�I�u�W�F�N�g�쐬------------------
	CObjStageChoiceHero* oh = new CObjStageChoiceHero(32,32);
	Objs::InsertObj(oh, OBJ_STAGECHOICEHERO, 10);
	//--------------------------------------------------------
	//�w�i�I�u�W�F�N�g�쐬���^�C�g���̔w�i���玝���Ă������--
	CObjTitleBack* obb = new CObjTitleBack();
	Objs::InsertObj(obb, OBJ_TITLEBACK, 0);
	//--------------------------------------------------------

}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneStageChoice::Scene()
{

}
