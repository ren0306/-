#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�r�[���T�[�x��
class CObjBeamSaber : public CObj
{
public:
	CObjBeamSaber(float x,float y);
	~CObjBeamSaber() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
private:
	float m_x;
	float m_y;
	int m_time;
};