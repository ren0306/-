//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjStageChoice.h"

#define Earthx 0
#define Earthxx 90
#define Earthy 380
#define Earthyy 600

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjStageChoice::Init()
{
	m_stage = false;
}

//�A�N�V����
void CObjStageChoice::Action()
{
	float c[4] = { 1,1,1,1 };

	//��l���ʒu�擾
	CObjStageChoiceHero* hero = (CObjStageChoiceHero*)Objs::GetObj(OBJ_STAGECHOICEHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�w��̏ꏊ��Z�L�[�ŃX�^�[�g
	if (hx >= Earthx && hx <= Earthxx && hy >= Earthy&&hy <= Earthyy)
	{
		Font::StrDraw(L"Z�L�[�ŃX�^�[�g", 280, 300, 10000, c);
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
