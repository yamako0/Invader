#include "Enemy.h"

CEnemy::CEnemy(Vec2 pos) : CObject(L"dat/image/enemy.png")
{
	Pos = pos;
	HitRange.r = 10;
}

CEnemy::~CEnemy()
{
}

void CEnemy::Update()
{
	HitRange.setPos(Pos);
	//Pos.moveBy(5, 0);

	bool SpawnBullet = Random(1, 900) == 1;

	if (SpawnBullet)
	{
		CBulletMgr::Inst()->SpawnBullet(Pos, 2, "Enemy");
	}
}

void CEnemy::Draw()
{
	//HitRange.draw(Palette::Red);
	Image.drawAt(Pos);
}

void CEnemy::Move(Vec2 vec)
{
	Pos.moveBy(vec);
}