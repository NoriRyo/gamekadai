#pragma once

class SelectMenu
{
public:
	SelectMenu();
	virtual ~SelectMenu();

	// 初期化、終了処理
	void init();
	void end();

	// 更新
	void update();

	// 描画
	void draw();

private:
	class Item
	{
	public:
		Item();
		virtual ~Item();

		// 表示する文字列を設定
		void setText(const char* text);

	private:
		// 表示する文字列
		const char* m_text;

	};



private:

};
