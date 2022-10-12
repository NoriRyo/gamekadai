#pragma once

#include "player.h"
#include "shot.h"
#include "Vec2.h"

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
	static constexpr int kShotMax = 64;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	int m_hEnemyGraphic;
	// プレイヤー
	Player m_player;
	
	// ショット
	Shot m_shot[kShotMax];
	// ショットの発射間隔
	int m_shotInterval;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
};