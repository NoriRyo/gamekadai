#pragma once
#include "Vec2.h"
#include "box.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle);

	// ショット開始
	void startLeft(Vec2 pos);

	void startRight(Vec2 pos);
	// 更新
	void update();
	// 表示
	void draw();

	// 弾と敵の衝突判定
	bool isCol(Box& box);

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// サイズの取得
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }

	// 存在するか
	bool isExist() const { return m_isExist; }

private:
	// グラフィックハンドル
	int m_handle;

	// グラフィックの幅と高さ
	Vec2 m_graphSize;
	// 当たり判定の幅と高さ
	Vec2 m_colSize;

	// 表示位置
	Vec2	m_pos;
	// 移動
	Vec2	m_vec;
	// 存在するか
	bool	m_isExist;
};