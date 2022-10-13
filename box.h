#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	virtual void setSpeedLeft(float speedleft);
	virtual void setSpeedRight(float speedraight);
	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	virtual void setSize(float x, float y);
	virtual void setColor(unsigned int color) { m_color = color; }


	void dead() { m_isDead = true; }

	// データの取得
	Vec2 getPos() const { return m_pos; } // 左上座標

	// サイズの取得
	Vec2 getSize() const { return m_size; }

	Vec2 getBottomRight() const { return m_pos + m_size; } //右上座標
	


	bool isDead() const { return m_isDead; }

	// 更新処理
	void upda();

	// 描画
	void draw();


private:
	// 移動開始までの待ち時間(フレーム数）
	int m_waitFrame;
	// 座標
	Vec2 m_pos;
	// サイズ
	Vec2 m_size;

	// 移動量
	Vec2 m_vec;		// vector　ベクトル

	// カラー
	unsigned int m_color;

	bool m_SpeedLeft;
	bool m_SpeedRight;
	// 塗りつぶし
	bool m_isFill;
	// 生死
	bool m_isDead;

	

};

