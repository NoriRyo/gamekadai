#pragma once

#include "player.h"
#include "shot.h"
#include "Vec2.h"
#include "box.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
	
private:
	// ショットの最大数
	static constexpr int kShotMax = 128;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	int m_hEnemyGraphic;
	int m_hBoxGraphic;
	// プレイヤー
	Player m_player;
	Box m_box1;
	Box m_box2;
	// ボックス
	//Box m_box;
	
	// ショット
	Shot m_shot[kShotMax];
	// ショットの発射間隔
	int m_shotInterval;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
};