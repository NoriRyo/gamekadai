#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	// グラフィックデータ設定
	void setGraphic(int handle);

	virtual void setSpeedLeft(float speedleft);
	virtual void setSpeedRight(float speedraight);


	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	

	void setDead(bool isDead) { m_isDead = isDead; }

	// データの取得
	Vec2 getPos() const { return m_pos; } 
	// サイズの取得
	Vec2 getSize() const { return m_size; }

	bool isDead() const { return m_isDead; }

	// 更新処理
	void upda();

	// 描画
	void draw();

	void drawturn();


private:
	int m_handle;
	// 移動開始までの待ち時間(フレーム数）
	int m_waitFrame;
	// 座標
	Vec2 m_pos;
	// サイズ
	Vec2 m_size;

	// 移動量
	Vec2 m_vec;		// vector　ベクトル

	// グラフィックの幅と高さ
	Vec2 m_graphSize;
	// 当たり判定の幅と高さ
	Vec2 m_colSize;

	bool m_SpeedLeft;
	bool m_SpeedRight;
	
	// 生死
	bool m_isDead;

	

};

