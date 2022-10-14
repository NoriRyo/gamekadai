#include "DxLib.h"
#include"box.h"

namespace
{
	// 待ち時間
	constexpr int kWaitFrameMin = 60;
	constexpr int kWaitFrameMax = 60;
	
}

Box::Box()
{
	m_handle = -1;
	m_isDead = false;
	m_waitFrame = 0;
}

Box::~Box()
{

}
void Box::setGraphic(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

void Box::setSpeedLeft(float speedleft)
{
	m_SpeedLeft = speedleft;
	m_vec.x = -m_SpeedLeft;
}
void Box::setSpeedRight(float speedright)
{
	m_SpeedRight = speedright;
	m_vec.x = m_SpeedRight;
}

void Box::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;



	// 動き始めるまでの時間を設定　1秒から3秒待つ　60フレームから180フレーム
	m_waitFrame = 120;//GetRand(kWaitFrameMax - kWaitFrameMin) + kWaitFrameMin;

}

void Box::setPos(Vec2 pos)
{
	m_pos = pos;
}


void Box::upda()
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

	m_isDead = 0;
	
}
void Box::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	//DrawFormatString(100, 100, GetColor(255, 255, 255),
	//	"wait;%d", m_waitFrame);
}