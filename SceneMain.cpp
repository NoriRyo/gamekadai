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
	// ショットの発射間隔
	constexpr int kShotInterval = 16;
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

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");

	m_hShotGraphic = LoadGraph("data/kidan1.png");

	m_hBoxGraphic  = LoadGraph("data/kabe.jpg");

	//m_hEnemyGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	// BOX
	m_box1.setGraphic(m_hBoxGraphic);
	//m_box1.setSpeedRight(2.0f);
	//m_box1.setPos(-70.0f, 0.0f);
	
	m_box1.setPos(70.0f, 0.0f);


	m_box2.setGraphic(m_hBoxGraphic);
	//m_box2.setSpeedLeft(2.0f);
	//m_box2.setPos(650.0f, 0.0f);
	
	m_box2.setPos(450.0f, 0.0f);

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
	m_shotInterval = 0;
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// 毎フレームの処理
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

	// キー入力処理
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((padState & PAD_INPUT_2) && (m_shotInterval <= 0))
	{
		for (auto& shot : m_shot)
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
	

	// 当たり判定
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

// 毎フレームの描画
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
		if (shot.isCol(m_box1) || shot.isCol(m_box2))
		{
			
		}
		else
		{
			shot.draw();
		}
	}

	m_box1.draw();
	m_box2.draw();


	// 現在存在している玉の数を表示
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
  DrawFormatString(0, 30, GetColor(255, 255, 255), "弾の数：%d", shotNum);
	DrawFormatString(0, 0, GetColor(255, 255, 255), 
		"1ボタン（発射）");
	

}