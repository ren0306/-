#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneEarth :public CScene
{
	public:
		CSceneEarth();
		~CSceneEarth();
		void InitScene(); //���������\�b�h
		void Scene();     //���s�����\�b�h
	private:
		int m_memory;	//���̐��̉��Z���v��ϐ�
		int m_time;	//���b�Z�[�W�\������
		wchar_t STAR[128];	//���̐��𐔂��郁�b�Z�[�W�p
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };	//���b�Z�[�W�t�H���g�J���[

};

