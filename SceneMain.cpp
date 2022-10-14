#include "DxLib.h"
#include "SceneMain.h"

/*
bool isCol(Player& player, Box& box)
{
	if (player.getPos().x > box.getPos().x) return false;
	if (player.getPos().x + 64.0f < box.getPos().x) return false;
	if (player.getPos().y > box.getBottomRight().y) return false;
	if (player.getPos().y + 80.0f < box.getPos().y) return false;
	
	return true;
}
*/
namespace
{
	// �V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 15;
	int direction = 0;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
	m_hEnemyGraphic = -1;
	m_hBoxGraphic = -1;

	m_shotInterval = 0;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");

	m_hShotGraphic = LoadGraph("data/kidan1.png");

	m_hBoxGraphic  = LoadGraph("data/enemy.png");

	//m_hEnemyGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	// BOX
	m_box1.setGraphic(m_hBoxGraphic);
	m_box1.setSpeedRight(10.0f);
	m_box1.setPos(-451.0f, 0.0f);
	
	//m_box1.setPos(50.0f, 0.0f);


	m_box2.setGraphic(m_hBoxGraphic);
	m_box2.setSpeedLeft(10.0f);
	m_box2.setPos(600.0f, 0.0f);
	
	//m_box2.setPos(550.0f, 0.0f);

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
	DeleteGraph(m_hEnemyGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();

	// BOX
	m_box1.upda();
	m_box2.upda();


	for (auto& shot : m_shot)
	{
		if (shot.isCol(m_box1) || shot.isCol(m_box2))
		{
			shot.isExist();
		}
		else
		{
			shot.update();
		}
	}
	m_shotInterval--;
	if (m_shotInterval < 0) m_shotInterval = 0;

	// �L�[���͏���
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((padState & PAD_INPUT_1) && (m_shotInterval <= 0))
	{
		for (auto& shot : m_shot)
		{
			if (shot.isExist()) continue;

			if (m_player.direction())
			{
				shot.startLeft(m_player.getPos());
			}
			else
			{
				shot.startRight(m_player.getPos());
			}
			
			
			m_shotInterval = kShotInterval;

			break;
		}
	}

	/*
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
	*/
	

	// �����蔻��
	if (m_player.isCol(m_box1))
	{
		m_box1.setDead(true);
		m_player.setDead(true);
	}
	if (m_player.isCol(m_box2))
	{
		m_player.setDead(true);
		m_box2.setDead(true);
	}
	
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	
	for (auto& shot : m_shot)
	{
		if (shot.isCol(m_box1) || shot.isCol(m_box2))
		{
			
		}
		else
		{
			shot.draw();
		}
	}

	m_box1.drawturn();
	m_box2.draw();


	// ���ݑ��݂��Ă���ʂ̐���\��
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
  DrawFormatString(0, 30, GetColor(255, 255, 255), "�e�̐��F%d", shotNum);
	DrawFormatString(0, 0, GetColor(255, 255, 255), 
		"1�{�^���i���ˁj");
	

}