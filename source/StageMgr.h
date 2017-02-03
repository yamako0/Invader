#pragma once

#include <Siv3D.hpp>
#include "Task.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Collision.h"
#include "BulletMgr.h"

class CStageMgr : public Task
{
	CPlayer Player;
	CEnemyMgr EnemyMgr;
	CCollision Collision;
	Font font;
	Font font2;

	void CheckHitAllObject();
	void PBulletAndEnemy();
	void PlayerAndEnemy();
	void PlayerAndEBullet();

public:
	CStageMgr();
	~CStageMgr();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;

};
