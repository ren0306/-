#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
#define MAPSIZE 29

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[MAPSIZE][MAPSIZE]);
		~CObjBlock() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		int Getmap() { return m_map[MAPSIZE][MAPSIZE]; }

		//���E�X�N���[���p
		void SetScrollx(float s) { m_scrollx = s; }
		float GetScrollx() { return m_scrollx; }
		//�㉺�X�N���[���p
		void SetScrolly(float s) { m_scrolly = s; }
		float GetScrolly() { return m_scrolly; }

		//�u���b�N�Ƃ̓����蔻��
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool*left, bool*right,
			float*vx, float*vy, int*bt
		);
	private:
		int m_map[MAPSIZE][MAPSIZE];	//�}�b�v���

		float m_scrollx;		//���E�X�N���[���p
		float m_scrolly;		//�㉺�X�N���[���p

		int m_f;//��l�����Ŏ��̃G���[���p

};