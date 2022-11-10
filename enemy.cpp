#include "DxLib.h"
#include"enemy.h"

Enemry::Enemry()
{
	m_handle = -1;
	
	m_waitFrame = 0;
}

Enemry::~Enemry()
{

}

void Enemry::init()
{
	m_isDead = false;
}

void Enemry::setGraphic(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

void Enemry::setSpeedLeft(float speedleft)
{
	m_SpeedLeft = speedleft;
	m_vec.x = -10.0f;
}
void Enemry::setSpeedRight(float speedright)
{
	m_SpeedRight = speedright;
	m_vec.x = 10.0f;
}

void Enemry::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;

	m_waitFrame = 120;
}

void Enemry::setPos(Vec2 pos)
{
	m_pos = pos;
}


void Enemry::upda()
{
	if (m_isDead) return;
	if (m_waitFrame > 0)
	{
		m_waitFrame--;
		return;
	}
	m_pos += m_vec;

	if (m_isDead)
	{
		//setPos(0.0f, 0.0f);
	}

	//m_isDead = 0;
	
}
void Enemry::draw()
{
	if (!m_isDead)
	{
		DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	}

}
void Enemry::drawturn()
{
	if (!m_isDead)
	{
		DrawTurnGraph(m_pos.x, m_pos.y, m_handle, true);
	}
}