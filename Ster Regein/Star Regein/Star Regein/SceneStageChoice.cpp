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
	Draw::LoadImageW(L"HeroTouka.png", 1, TEX_SIZE_512);

	//�X�e�[�W�I���I�u�W�F�N�g�쐬
	CObjStageChoice* o = new CObjStageChoice();
	Objs::InsertObj(o, OBJ_STAGECHOICE, 10);


	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneStageChoice::Scene()
{

}
