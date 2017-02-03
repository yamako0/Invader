#pragma once

#include "Singleton.h"
#include "Bullet.h"
#include "Task.h"

using namespace std;

class CBulletMgr : public Task, public CSingleton<CBulletMgr>
{
	list<CBullet> P_Bullet;
	list<CBullet> E_Bullet;

	void BulletUpdate(list<CBullet> *Bullet);

public:
	CBulletMgr();
	~CBulletMgr();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;

	void SpawnBullet(Vec2 vec, double speed, string Tag);
	list<CBullet> *GetP_BulletArray() { return &P_Bullet; }
	list<CBullet> *GetE_BulletArray() { return &E_Bullet; }
};
