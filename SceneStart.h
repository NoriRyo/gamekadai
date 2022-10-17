#pragma once

class SceneStart
{
public:
	SceneStart();
	~SceneStart();

	void init();

	// 更新処理
	void upda();

	// 描画
	void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;
};

