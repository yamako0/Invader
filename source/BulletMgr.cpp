#include "BulletMgr.h"

CBulletMgr::CBulletMgr()
{
}

CBulletMgr::~CBulletMgr()
{
	P_Bullet.clear();
	E_Bullet.clear();
}

void CBulletMgr::Initialize()
{
	P_Bullet.clear();
	E_Bullet.clear();
}

void CBulletMgr::Finalize()
{
	P_Bullet.clear();
	E_Bullet.clear();
}

void CBulletMgr::Update()
{
	BulletUpdate(&P_Bullet);
	BulletUpdate(&E_Bullet);
}

void CBulletMgr::Draw()
{
	for (auto it : P_Bullet)
	{
		it.Draw();
	}
	for (auto it : E_Bullet)
	{
		it.Draw();
	}
}

void CBulletMgr::SpawnBullet(Vec2 vec, double speed, string Tag)
{
	if (Tag == "Player")
	{
		P_Bullet.emplace_back(vec, speed, L"dat/image/bullet_player.png");
	}
	if (Tag == "Enemy")
	{
		E_Bullet.emplace_back(vec, speed, L"dat/image/bullet_enemy.png");
	}
}

void CBulletMgr::BulletUpdate(list<CBullet> *Bullet)
{
	for (auto it = Bullet->begin(); it != Bullet->end(); it++)
	{
		if (it->IsScreenOver())
		{
			it = Bullet->erase(it);
			if (it == Bullet->end())
			{
				break;
			}
		}
		it->Update();
	}
}