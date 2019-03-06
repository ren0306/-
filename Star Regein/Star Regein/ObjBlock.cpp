//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[MAPSIZE][MAPSIZE])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(MAPSIZE * MAPSIZE));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{

	//�G�o��
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (m_map[i][j] == 5)
			{
				//���I�u�W�F�N�g�쐬
				CObjCow* cow = new CObjCow(j*MAPSIZE, i*MAPSIZE);
				Objs::InsertObj(cow, OBJ_COW, 10);
			}
		}
	}

	//�o��
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (m_map[i][j] == 3)
			{
				//��l���I�u�W�F�N�g�쐬
				CObjHero* obj = new CObjHero(j*MAPSIZE, i*MAPSIZE);//�I�u�W�F�N�g�쐬
				Objs::InsertObj(obj, OBJ_HERO, 10);//�}�l�[�W���ɓo�^

				m_scrollx = -j * MAPSIZE + 400;
				m_scrolly = -i * MAPSIZE + 300;

				return;
			}
		}
	}
}

//�A�N�V����
void CObjBlock::Action()
{

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���̈ʒu���擾
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�X�N���[��
	hero->SetX(375);
	m_scrollx -= hero->GetVX() * 4;

	hero->SetY(275);
	m_scrolly -= hero->GetVY() * 4;
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}

//BlockHit�ϐ�
//�����P�@float* x			�F������s��object��X�ʒu
//�����Q�@float* y			�F������s��object��Y�ʒu
//�����R�@bool  scroll		�F������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����Afalse=�^���Ȃ��j
//�����S�@bool* up			�F�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T�@bool* down		�F�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U�@bool*left			�F�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V�@bool*right		�F�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W�@float* vx			�F���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//�����X�@float* vy			�F�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10�@int* bt			�F���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N50*50����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈����S�`10�ɕԂ�
void CObjBlock::blockHit
(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 1)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*50.0f;
				float by = i*50.0f;

				//�X�N���[���̉e��
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scrollx) + 50.0f > bx) && (*x + (-scrollx) < bx + 50.0f) && (*y + (-scrolly) + 50.0f > by) && (*y + (-scrolly) < by + 50.0f))
				{
					//�㉺���E����

					//Vector�̍쐬
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							*right = true;//�I�u�W�F�N�g�̍��������Փ˂��Ă���
							*x = bx + 50.0f + (scrollx);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = 0.5f;//-VX*�����W��
						}

						if (r > 45 && r < 135)
						{
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 50.0f + (scrolly);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vy = -0.5f;
						}
						if (r > 135 && r < 225)
						{
							*left = true;//�I�u�W�F�N�g�̉E�������Փ˂��Ă���
							*x = bx - 50.0f + (scrollx);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vx = -0.5f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							*up = true;//�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
							*y = by + 50.0f + (scrolly);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�							
							*vy = 0.5f;

						}
					}
				}
			}
		}
	}
}