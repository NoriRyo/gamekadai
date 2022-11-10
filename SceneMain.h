#pragma once

#include "player.h"
#include "shot.h"
#include "Vec2.h"
#include "enemy.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();

	virtual bool isEnd() { return m_isEnd; }
	
private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 128;

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	int m_hEnemyGraphic;
	int m_hEnemryGraphic;
	// �v���C���[
	Player m_player;
	Enemry m_Enemry1;
	Enemry m_Enemry2;
	// �{�b�N�X
	//Enemry m_Enemry;
	
	// �V���b�g
	Shot m_shot[kShotMax];
	// �V���b�g�̔��ˊԊu
	int m_shotInterval;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	bool m_isEnd;
};