#pragma once
#include "shot.h"
#include "Vec2.h"
#include "enemy.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle);

	// �v���C���[�̌���
	bool direction() const { return m_direction; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	
	// �`��
	void draw();

	// �G�ƃv���C���[�̏Փ˔���
	bool isCol(Enemry& Enemry);

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	// �T�C�Y�̎擾
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }


	// ���S�ݒ�
	void setDead(bool isDead) { m_isDead = isDead; }

private:
	int m_handle;

	bool m_direction;

	// �O���t�B�b�N�̕��ƍ���
	Vec2 m_graphSize;
	// �����蔻��̕��ƍ���
	Vec2 m_colSize;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	bool m_isDead;

};