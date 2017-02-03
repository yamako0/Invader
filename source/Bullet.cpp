#include "Bullet.h"

CBullet::CBullet(Vec2 vec, double speed, String s) : CObject(s)
{
	Pos = vec;
	Speed = speed;
	HitRange.r = 5;
}

CBullet::~CBullet()
{
}

void CBullet::Update()
{
	Pos.moveBy(0, Speed);
	HitRange.setPos(Pos);
}

void CBullet::Draw()
{
	//HitRange.draw(Palette::Red);
	if (Speed == 2)
	{
		Image.rotate(Radians(180)).drawAt(Pos);
	}
	else
	{
		Image.drawAt(Pos);
	}
}

bool CBullet::IsScreenOver()
{
	bool ScreenOver = Pos.y < 0 || Pos.y > 480;

	return ScreenOver ? true : false;
}
