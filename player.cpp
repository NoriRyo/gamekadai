#include "DxLib.h"
#include "game.h"
#include "player.h"
#include "shot.h"

namespace
{
	// キャラクターのサイズ
	constexpr float kSizeX = 64.0f;
	constexpr float kSizeY = 80.0f;
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
}

Player::Player()
{
	m_handle = -1;

	m_isDead = false;
}

Player::~Player()
{
	
}
void Player::setHandle(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_graphSize.x, &m_graphSize.y);
	m_colSize = m_graphSize;
}

void Player::init()
{
	m_pos.x = 280.0f;
	m_pos.y = 200.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

void Player::update()
{
	if (m_isDead) return;
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	else
	{
		// 加速
		m_vec.y *= 0.9f;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}
	m_pos += m_vec;
}

void Player::drawLeft()
{
	if (m_isDead)
	{
		DrawFormatString(120, 120, GetColor(255, 255, 0), "dead");
	};
	// 右
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}

void Player::drawRight()
{
	if (m_isDead)
	{
		DrawFormatString(120, 120, GetColor(255, 255, 0), "dead");
	}
	// 左
	DrawTurnGraph(m_pos.x, m_pos.y, m_handle, true);
}

bool Player::isCol(Box& box)
{
	float playerLeft = getPos().x;
	float playerRight = getPos().x + kSizeX;
	float playerTop = getPos().y;
	float playerBottom = getPos().y + kSizeY;

	float boxLeft = box.getPos().x;
	float boxRight = box.getPos().x + box.getSize().x;
	float boxTop = box.getPos().y;
	float boxBottom = box.getPos().y + box.getSize().y;


	DrawFormatString(0, 60, GetColor(255, 0, 255),
		"P座標x:%g", playerLeft);
	DrawFormatString(0, 80, GetColor(255, 0, 255),
		"P座標y:%g", playerTop);

	//DrawFormatString(0, 100, GetColor(255, 0, 255),
	//	"B座標x:%g", boxRight);
	//DrawFormatString(0, 120, GetColor(255, 0, 255),
	//	"B座標y:%g", boxBottom);

	
	if (playerLeft > boxRight)	return false;
	if (playerRight < boxLeft)	return false;
	if (playerTop > boxBottom)	return false;
	if (playerBottom < boxTop)	return false;	

	return true;
}
