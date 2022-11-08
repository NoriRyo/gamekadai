#include "SceneStart.h"
#include "DxLib.h"

SceneStart::SceneStart()
{

}
SceneStart::~SceneStart()
{

}

void SceneStart::init()
{
	m_isEnd = false;
}

void SceneStart::upda()
{
	WaitTimer(2000);
	
	m_isEnd = true;
	
	return;
}


void SceneStart::draw()
{
	SetFontSize(64);
	DrawFormatString(100, 100, GetColor(255, 255, 255),
		"ìGÇì|ÇπÅIÅI");
}