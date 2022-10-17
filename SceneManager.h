#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneStart.h"

class SceneManager
{
public:
	// �V�[���̎�ޒ�`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindStart,
		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();


private:
	SceneKind	m_kind;

	SceneTitle	m_title;
	SceneMain	m_main;

	SceneStart m_start;
};