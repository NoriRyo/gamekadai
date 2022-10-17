#pragma once

class SceneStart
{
public:
	SceneStart();
	~SceneStart();

	void init();

	// XVˆ—
	void upda();

	// •`‰æ
	void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;
};

