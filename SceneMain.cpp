#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// ショットの発射間隔
	constexpr int kShotInterval = 15;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
	m_hEnemyGraphic = -1;
	m_hEnemryGraphic = -1;

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

	m_hEnemryGraphic  = LoadGraph("data/enemy.png");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	// Enemry
	m_Enemry1.setGraphic(m_hEnemryGraphic);
	m_Enemry1.setSpeedRight(1.0f);
	m_Enemry1.setPos(-452.0f, 0.0f);
	m_Enemry1.init();

	m_Enemry2.setGraphic(m_hEnemryGraphic);
	m_Enemry2.setSpeedLeft(1.0f);
	m_Enemry2.setPos(1200.0f, 0.0f);
	m_Enemry2.init();

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
	m_shotInterval = 0;


	m_isEnd = false;
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

	// Enemry
	m_Enemry1.upda();
	m_Enemry2.upda();

	for (auto& shot : m_shot)
	{
		if (shot.isCol(m_Enemry1))
		{
			shot.isExist();
		}
		if (shot.isCol(m_Enemry2))
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
		}
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	
	for (auto& shot : m_shot)
	{
		if (shot.isExist())
		{
			if (shot.isCol(m_Enemry1))
			{
				m_Enemry1.setSpeedRight(0.0f);
				m_Enemry1.setDead(true);
			}
			if (shot.isCol(m_Enemry2))
			{
				m_Enemry2.setSpeedLeft(0.0f);
				m_Enemry2.setDead(true);
				SetFontSize(128);
				DrawFormatString(100, 230, GetColor(0, 255, 255),
					"クリア！");
				ScreenFlip();
				WaitTimer(1000);
				m_isEnd = true;

				return;
			}
		}
		shot.draw();
	}

	m_Enemry1.drawturn();
	m_Enemry2.draw();

	// 当たり判定
	if (m_player.isCol(m_Enemry1))
	{
		m_player.setDead(true);
		m_player.draw();
		m_isEnd = true;
		ScreenFlip();
		WaitTimer(1000);
		return;
	}

	if (m_player.isCol(m_Enemry2))
	{
		m_player.setDead(true);
		m_player.draw();
		m_isEnd = true;
		ScreenFlip();
		WaitTimer(1000);
		return;
	}

	// 現在存在している玉の数を表示
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist()) shotNum++;
	}
	SetFontSize(24);
	//DrawFormatString(0, 30, GetColor(255, 255, 255), "弾の数：%d", shotNum);
	DrawFormatString(0, 0, GetColor(255, 255, 255), 
		"1ボタン（発射）");
}