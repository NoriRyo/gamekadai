#include "DxLib.h"
#include "game.h"
#include "enemy.h"

Enemy::Enemy()
{
	m_handle = -1;
}

void Enemy::setGraphic(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

void Enemy::setup(float fieldY)
{
	m_pos.x = Game::kScreenWidth + 16.0f;

	m_vec.x = -16.0f;
	m_vec.y = 0.0f;
}

void Enemy::update()
{
	m_pos += m_vec;
}

void Enemy::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}