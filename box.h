#pragma once

#include "Vec2.h"
class Box
{
public:
	Box();
	virtual ~Box();

	virtual void init();
	

	//virtual void updata() = 0; // 純粋仮想関数
	virtual void setHandle(int handle);
	virtual void setPos(float x, float y);
	virtual void setPos(Vec2 pos);
	virtual void setSize(float x, float y);
	virtual void setColor(unsigned int color) { m_color = color; }
	virtual void setFill(bool Fill) { m_isFill = Fill; }

	void dead() { m_isDead = true; }

	// データの取得
	Vec2 getPos() const { return m_pos; } // 左上座標
	Vec2 getBottomRight() const { return m_pos + m_size; } //右上座標


	bool isDead() const { return m_isDead; }

	// 更新処理
	virtual void upda();

	// 描画
	virtual void draw();


protected:

	// 画像データ	
	int m_handle;

	// 左上座標
	Vec2 m_pos;
	// サイズ
	Vec2 m_size;

	// 移動量
	Vec2 m_vec;		// vector　ベクトル

	// カラー
	unsigned int m_color;
	// 塗りつぶし
	bool m_isFill;
	// 生死
	bool m_isDead;




};


class BoxSin : public Box
{
public:
	BoxSin();
	virtual ~BoxSin() {}

	virtual void init() override;
	virtual void setPos(float x, float y) override;
	virtual void upda() override;

	float m_sinRate;
private:
	
	Vec2 m_basePos;
};
