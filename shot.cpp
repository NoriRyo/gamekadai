#include "DxLib.h"
#include "shot.h"
#include "game.h"

namespace
{
	// 弾のサイズ
	constexpr float kSizeX = 50.0f;
	constexpr float kSizeY = 54.0f;

	constexpr float kShotSpeed = 4.0f;
}


Shot::Shot()
{
	m_handle = -1;
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = false;
}

Shot::~Shot()
{

}

void Shot::setHandle(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_graphSize.x, &m_graphSize.y);
	m_colSize = m_graphSize;
}

void Shot::startLeft(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
	
	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;

}

void Shot::startRight(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;

	m_vec.x = -kShotSpeed;
	m_vec.y = 0.0f;

}

void Shot::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}

	else if (m_pos.x < 0)
	{
		m_isExist = false;
	}
}
// 表示
void Shot::draw()
{
	if (!m_isExist) return;
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}

bool Shot::isCol(Enemry& enemry)
{
	float shotLeft = getPos().x;
	float shotRight = getPos().x + kSizeX;

	float EnemryLeft = enemry.getPos().x + 70.0f;
	float EnemryRight = enemry.getPos().x + enemry.getSize().x - 70.0f;

	if (shotLeft > EnemryRight)
	{
		return false;
	}
	if (shotRight < EnemryLeft)
	{
		return false;
	}

	return true;
	
}