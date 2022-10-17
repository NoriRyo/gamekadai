#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setGraphic(int handle);

	virtual void setSpeedLeft(float speedleft);
	virtual void setSpeedRight(float speedraight);


	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	

	void setDead(bool isDead) { m_isDead = isDead; }

	// �f�[�^�̎擾
	Vec2 getPos() const { return m_pos; } 
	// �T�C�Y�̎擾
	Vec2 getSize() const { return m_size; }

	bool isDead() const { return m_isDead; }

	// �X�V����
	void upda();

	// �`��
	void draw();

	void drawturn();


private:
	int m_handle;
	// �ړ��J�n�܂ł̑҂�����(�t���[�����j
	int m_waitFrame;
	// ���W
	Vec2 m_pos;
	// �T�C�Y
	Vec2 m_size;

	// �ړ���
	Vec2 m_vec;		// vector�@�x�N�g��

	// �O���t�B�b�N�̕��ƍ���
	Vec2 m_graphSize;
	// �����蔻��̕��ƍ���
	Vec2 m_colSize;

	bool m_SpeedLeft;
	bool m_SpeedRight;
	
	// ����
	bool m_isDead;

	

};

