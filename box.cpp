#include "DxLib.h"
#include"box.h"

namespace
{
	// �҂�����
	constexpr int kWaitFrameMin = 30;
	constexpr int kWaitFrameMax = 90;
	
}

Box::Box()
{
	m_isDead = false;
	m_waitFrame = 0;
}

Box::~Box()
{

}

void Box::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;

	m_vec.x = m_kSpeed;

	// �����n�߂�܂ł̎��Ԃ�ݒ�@1�b����3�b�҂@60�t���[������180�t���[��
	m_waitFrame = GetRand(kWaitFrameMax - kWaitFrameMin) + kWaitFrameMin;

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
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
	DrawFormatString(50, 100, GetColor(255, 255, 255), "wait;%d", m_waitFrame);

}
