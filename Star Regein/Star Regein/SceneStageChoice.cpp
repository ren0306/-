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
	Draw::LoadImage(L"HeroTouka.png", 1, TEX_SIZE_512);
	//�X�e�[�W�I���I�u�W�F�N�g�쐬
	CObjStageChoice* obj = new CObjStageChoice();
	Objs::InsertObj(obj, OBJ_STAGECHOICE, 10);

}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneStageChoice::Scene()
{

}
