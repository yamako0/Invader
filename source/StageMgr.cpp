#include "StageMgr.h"

CStageMgr::CStageMgr()
{
	FontManager::Register(L"dat/font/Carousel.ttf");
	font = Font(40, L"Carousel", FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(Palette::Red, Palette::Black, 2.0));
	//font2 = Font(30, L"Old English Text MT", FontStyle::Outline);
	font2 = Font(20, L"Carousel", FontStyle::Outline);
	font2.changeOutlineStyle(TextOutlineStyle(Palette::Red, Palette::Black, 1.0));
}

CStageMgr::~CStageMgr()
{
}

void CStageMgr::Initialize()
{
	Player.Initialize();
	EnemyMgr.Initialize();
}

void CStageMgr::Finalize()
{
	Player.Finalize();
	EnemyMgr.Finalize();
}

void CStageMgr::Update()
{
	if (Player.GetState() == eDeath)
	{
		if (Input::MouseL.clicked)
		{
			Finalize();
			Initialize();
		}
		if (Input::KeyEscape.clicked)
		{
			Finalize();
			System::Exit();
		}
		return;
	}
	Player.Update();

	EnemyMgr.Update();
	CheckHitAllObject();

	CBulletMgr::Inst()->Update();
}

void CStageMgr::Draw()
{
	Player.Draw();
	
	EnemyMgr.Draw();

	CBulletMgr::Inst()->Draw();

	if (Player.GetState() == eDeath)
	{
		font(L"GameOver").draw(20, 100);
		font2(L"Continue: LeftClick").draw(300, 300);
		font2(L"Exit: Escape").draw(300, 350);
	}
}

void CStageMgr::CheckHitAllObject()
{
	PBulletAndEnemy();
	PlayerAndEnemy();
	PlayerAndEBullet();
}

void CStageMgr::PBulletAndEnemy()
{
	auto EnemyArray = EnemyMgr.GetEnemyArray();
	auto PlayerBulletArray = CBulletMgr::Inst()->GetP_BulletArray();
	for (auto PBit = PlayerBulletArray->begin(); PBit != PlayerBulletArray->end(); PBit++)
	{
		for (auto EAit = EnemyArray->begin(); EAit != EnemyArray->end(); EAit++)
		{
			if (Collision.Intersects(*PBit, *EAit))
			{
				EAit = EnemyArray->erase(EAit);
				PBit = PlayerBulletArray->erase(PBit);
				if (EAit == EnemyArray->end())
				{
					break;
				}
				if (PBit == PlayerBulletArray->end())
				{
					break;
				}
			}
		}
		if (PBit == PlayerBulletArray->end())
		{
			break;
		}
	}
}

void CStageMgr::PlayerAndEnemy()
{
	auto EnemyArray = EnemyMgr.GetEnemyArray();
	for (auto EAit = EnemyArray->begin(); EAit != EnemyArray->end(); EAit++)
	{
		if (Collision.Intersects(Player, *EAit))
		{
			EAit = EnemyArray->erase(EAit);
			Player.SetState(eDeath);
			if (EAit == EnemyArray->end())
			{
				break;
			}
		}
	}
}

void CStageMgr::PlayerAndEBullet()
{
	auto EBulletArray = CBulletMgr::Inst()->GetE_BulletArray();
	for (auto EBit = EBulletArray->begin(); EBit != EBulletArray->end(); EBit++)
	{
		if (Collision.Intersects(Player, *EBit))
		{
			EBit = EBulletArray->erase(EBit);
			Player.SetState(eDeath);
			if (EBit == EBulletArray->end())
			{
				break;
			}
		}
	}
}