#include "Player.h"

CPlayer::CPlayer() : CObject(L"dat/image/player2.png")
{
	Pos = { 0, 420 };
	HitRange.r = 10;
	State = eAlive;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	Pos = { 0, 420 };
	State = eAlive;
	CBulletMgr::Inst()->Initialize();
}

void CPlayer::Finalize()
{

}

void CPlayer::Update()
{

	Pos.x = Mouse::Pos().x;

	if (Pos.x < 0)
	{
		Pos.x = 0;
	}
	if (Pos.x > 640)
	{
		Pos.x = 640;
	}

	HitRange.setPos(Pos);

	if (Input::MouseL.clicked)
	{
		CBulletMgr::Inst()->SpawnBullet(Pos, -2, "Player");
	}
}

void CPlayer::Draw()
{
	HitRange.draw(Palette::Yellow);
	Image.drawAt(Pos);
}