#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	virtual void init();
	

	//virtual void updata() = 0; // �������z�֐�
	virtual void setHandle(int handle);
	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	virtual void setSize(float x, float y);
	virtual void setColor(unsigned int color) { m_color = color; }
	virtual void setFill(bool Fill) { m_isFill = Fill; }

	void dead() { m_isDead = true; }

	// �f�[�^�̎擾
	Vec2 getPos() const { return m_pos; } // ������W
	Vec2 getBottomRight() const { return m_pos + m_size; } //�E����W


	bool isDead() const { return m_isDead; }

	// �X�V����
	virtual void upda();

	// �`��
	virtual void draw();


protected:

	// �摜�f�[�^	
	int m_handle;

	// ������W
	Vec2 m_pos;
	// �T�C�Y
	Vec2 m_size;

	// �ړ���
	Vec2 m_vec;		// vector�@�x�N�g��

	// �J���[
	unsigned int m_color;
	// �h��Ԃ�
	bool m_isFill;
	// ����
	bool m_isDead;




};


class BoxSin : public Box
{
public:
	BoxSin();
	virtual ~BoxSin() {}

	virtual void init() override;
	virtual void setPos(float x, float y) override;
	virtual void upda() override;

	float m_sinRate;
private:
	
	Vec2 m_basePos;
};
