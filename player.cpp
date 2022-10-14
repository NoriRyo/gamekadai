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
	constexpr float kSpeedMax = 4.0f;
	constexpr float kAcc = 0.4f;
}

Player::Player()
{
	m_handle = -1;

	m_direction = false;

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
	m_pos.y = 320.0f;
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
	else if (padState & PAD_INPUT_LEFT)
	{
		m_direction = false;
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_direction = true;
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	
	else
	{
		// 加速
		m_vec.x *= 0.9f;
		m_vec.y *= 0.9f;
	}
	
	m_pos += m_vec;
}


void Player::draw()
{
	if (m_direction == true)
	{
		DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	}
	else
	{
		DrawTurnGraph(m_pos.x, m_pos.y, m_handle, true);
	}
}

bool Player::isCol(Box& box)
{
	float playerLeft = getPos().x;
	float playerRight = getPos().x + kSizeX;
	
	float boxLeft = box.getPos().x + 70.0f;
	float boxRight = box.getPos().x + box.getSize().x - 70.0f;
	

	//DrawFormatString(0, 60, GetColor(255, 0, 255),
	//	"P座標x:%g", playerLeft);
	
	//DrawFormatString(0, 100, GetColor(255, 0, 255),
	//	"B座標x:%g", boxRight);
	
	
	if (playerLeft > boxRight)	return false;
	if (playerRight < boxLeft)	return false;
	

	return true;
}
