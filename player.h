#pragma once
#include "shot.h"
#include "Vec2.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle) { m_handle = handle; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void drawLeft();

	void drawRight();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

private:
	int m_handle;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
};