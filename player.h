#pragma once
#include "shot.h"
#include "Vec2.h"
#include "box.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int handle);

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	// 描画
	void drawLeft();

	void drawRight();

	// 衝突判定
	//bool isCol(Box& box);

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// サイズの取得
	Vec2 getGraphSize() const { return m_graphSize; }
	Vec2 getColSize() const { return m_colSize; }


	// 死亡設定
	void setDead(bool isDead) { m_isDead = isDead; }

private:
	int m_handle;

	// グラフィックの幅と高さ
	Vec2 m_graphSize;
	// 当たり判定の幅と高さ
	Vec2 m_colSize;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	bool m_isDead;
};