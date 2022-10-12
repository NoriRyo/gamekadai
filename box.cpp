#include "DxLib.h"
#include"box.h"

namespace
{
	constexpr float kSpeed = 4.0f;
}

Box::Box()
{
	m_color = 0;
	m_isFill = false;
	m_isDead = false;
	m_handle = -1; 
	
}

Box::~Box()
{

}

void Box::init()
{

}

void Box::setHandle(int handle)
{
	m_handle = handle;
}

void Box::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void Box::setPos(Vec2 pos)
{
	m_pos = pos;
}

void Box::setSize(float x, float y)
{
	m_size.x = x;
	m_size.y = y;
}

void Box::upda()
{
	if (m_isDead)
	{
		setPos(100.0f, 300.0f);
	}

	m_isDead = 0;

	/*
	// マウスでの操作
	int mouseX = 0;
	int mouseY = 0;

	if (GetMousePoint(&mouseX, &mouseY) == 1) return;

	m_pos.x = mouseX;
	m_pos.y = mouseY;
	*/

	/*
	// ゲームパッドでの移動
	int padState = GetJoypadInputState(DX_INPUT_PAD1);
	if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x -= kSpeed;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x += kSpeed;
	}
	if (padState & PAD_INPUT_UP)
	{
		m_pos.y -= kSpeed;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y += kSpeed;
	}
	*/
	
	// キーボードでの移動
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_pos.x -= kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_pos.x += kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		m_pos.y -= kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		m_pos.y += kSpeed;
	}
	
	
}
void Box::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
}

BoxSin::BoxSin()
{
	m_sinRate = 0.0f;
}


void BoxSin::init()
{
	m_vec.x = 1.0f;
	m_vec.y = 0.0f;
}

void BoxSin::setPos(float x, float y)
{
	Box::setPos(x, y);
	m_basePos = m_pos;
}

void BoxSin::upda()
{
	m_pos += m_vec;
	m_sinRate += 0.03f;// 速度

	m_pos = m_basePos;
	m_pos.y += sinf(m_sinRate) * 230.0f;// 距離

}

