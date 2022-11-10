#pragma once

#include "player.h"
#include "shot.h"
#include "Vec2.h"
#include "enemy.h"

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

	virtual bool isEnd() { return m_isEnd; }
	
private:
	// ショットの最大数
	static constexpr int kShotMax = 128;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	int m_hEnemyGraphic;
	int m_hEnemryGraphic;
	// プレイヤー
	Player m_player;
	Enemry m_Enemry1;
	Enemry m_Enemry2;
	// ボックス
	//Enemry m_Enemry;
	
	// ショット
	Shot m_shot[kShotMax];
	// ショットの発射間隔
	int m_shotInterval;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	bool m_isEnd;
};