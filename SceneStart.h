#pragma once

class SceneStart
{
public:
	SceneStart();
	~SceneStart();

	void init();

	// �X�V����
	void upda();

	// �`��
	void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;
};

