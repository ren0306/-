//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"

#define Earthx 300
#define Earthy 400

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjStageChoice::Init()
{

}

//�A�N�V����
void CObjStageChoice::Action()
{
	//��l���ʒu�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�w��̏ꏊ��
	if (hx >= Earthx && hy <= Earthy)
	{
		if (Input::GetVKey('Z') == true)
		{
			Scene::SetScene(new CSceneEarth());
		}
	}

}

//�h���[
void CObjStageChoice::Draw()
{


}
