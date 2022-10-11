#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
	int direction = 0;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
	m_shotInterval = 0;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");

	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
	m_shotInterval = 0;
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}
	m_shotInterval--;
	if (m_shotInterval < 0) m_shotInterval = 0;

	// �L�[���͏���
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((padState & PAD_INPUT_2) && (m_shotInterval <= 0))
	{
		for (auto & shot : m_shot)
		{
			if (shot.isExist()) continue;

			shot.startLeft(m_player.getPos());
			m_shotInterval = kShotInterval;

			direction = 1;

			break;
		}
	}
	if ((padState & PAD_INPUT_1) && (m_shotInterval <= 0))
	{
		for (auto& shot : m_shot)
		{
			if (shot.isExist()) continue;

			shot.startRight(m_player.getPos());
			m_shotInterval = kShotInterval;

			direction = 0;
			break;
		}
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	if (direction == 1)
	{
		m_player.drawLeft();
	}
	else
	{
		m_player.drawRight();
	}
	

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	// ���ݑ��݂��Ă���ʂ̐���\��
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�e�̐��F%d", shotNum);
}