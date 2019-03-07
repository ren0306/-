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
	m_key_flag = true;
}

//�A�N�V����
void CObjStageChoice::Action()
{
	float c[4] = { 1,1,1,1 };

	//��l���ʒu�擾
	CObjStageChoiceHero* hero = (CObjStageChoiceHero*)Objs::GetObj(OBJ_STAGECHOICEHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	if (Input::GetVKey('Z') == true )
	{

		if (hx >= Earthx && hx <= Earthxx && hy >= Earthy&&hy <= Earthyy&&m_key_flag==false)
		{
			Font::StrDraw(L"Z�L�[�ŃX�^�[�g", 280, 300, 10000, c);
			Scene::SetScene(new CSceneEarth());
		}

	}
	else
	{
		m_key_flag = false;
	}

}

//�h���[
void CObjStageChoice::Draw()
{


}
