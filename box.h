#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	virtual void setSize(float x, float y);
	virtual void setColor(unsigned int color) { m_color = color; }
	//virtual void setSpeed(float speed);


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

	int m_kSpeed;
	// �h��Ԃ�
	bool m_isFill;
	// ����
	bool m_isDead;

	

};

