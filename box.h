#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	virtual void setSpeedLeft(float speedleft);
	virtual void setSpeedRight(float speedraight);
	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	virtual void setSize(float x, float y);
	virtual void setColor(unsigned int color) { m_color = color; }


	void dead() { m_isDead = true; }

	// �f�[�^�̎擾
	Vec2 getPos() const { return m_pos; } // ������W

	// �T�C�Y�̎擾
	Vec2 getSize() const { return m_size; }

	Vec2 getBottomRight() const { return m_pos + m_size; } //�E����W
	


	bool isDead() const { return m_isDead; }

	// �X�V����
	void upda();

	// �`��
	void draw();


private:
	// �ړ��J�n�܂ł̑҂�����(�t���[�����j
	int m_waitFrame;
	// ���W
	Vec2 m_pos;
	// �T�C�Y
	Vec2 m_size;

	// �ړ���
	Vec2 m_vec;		// vector�@�x�N�g��

	// �J���[
	unsigned int m_color;

	bool m_SpeedLeft;
	bool m_SpeedRight;
	// �h��Ԃ�
	bool m_isFill;
	// ����
	bool m_isDead;

	

};

