#pragma once
#include "Vec2.h"
#include "box.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle);

	// �V���b�g�J�n
	void startLeft(Vec2 pos);

	void startRight(Vec2 pos);
	// �X�V
	void update();
	// �\��
	void draw();

	// �e�ƓG�̏Փ˔���
	bool isCol(Box& box);

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	// �T�C�Y�̎擾
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }

	// ���݂��邩
	bool isExist() const { return m_isExist; }

private:
	// �O���t�B�b�N�n���h��
	int m_handle;

	// �O���t�B�b�N�̕��ƍ���
	Vec2 m_graphSize;
	// �����蔻��̕��ƍ���
	Vec2 m_colSize;

	// �\���ʒu
	Vec2	m_pos;
	// �ړ�
	Vec2	m_vec;
	// ���݂��邩
	bool	m_isExist;
};