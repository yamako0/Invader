#include "EnemyMgr.h"

CEnemyMgr::CEnemyMgr()
{
	BasePos.set(60, 30);
	Dir = eRight;
	LastDir = eDown;
}

CEnemyMgr::~CEnemyMgr()
{
	Enemy.clear();
}

void CEnemyMgr::Initialize()
{
	Vec2 vec;
	
	BasePos.set(60, 30);
	Dir = eRight;
	LastDir = eDown;

	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 5; n++)
		{
			vec.set(i * 40, n * 60);
			//Enemy.emplace_back({ i * 10, n * 20 });
			Enemy.emplace_back(vec + BasePos);
		}
	}
}

void CEnemyMgr::Finalize()
{
	Enemy.clear();
}

void CEnemyMgr::Update()
{
	int FrameCount = System::FrameCount() % 60;
	for (auto &it : Enemy)
	{
		it.Update();
		if (FrameCount == 0)
		{
			switch (Dir)
			{
			case eRight:
				it.Move({ 5, 0 });
				break;
			case eLeft:
				it.Move({ -5, 0 });
				break;
			case eDown:
				it.Move({ 0, 20 });
				break;
			}
		}
	}

	if (FrameCount == 0)
	{
		switch (Dir)
		{
		case eRight:
			BasePos.moveBy({ 5, 0 });
			break;
		case eLeft:
			BasePos.moveBy({ -5, 0 });
			break;
		case eDown:
			BasePos.moveBy({ 0, 20 });
			break;
		}

		bool changeDir = BasePos.x < 60 || BasePos.x > 200;
		if (changeDir)
		{
			ChangeDir();
		}
	}
}

void CEnemyMgr::Draw()
{
	for (auto it : Enemy)
	{
		it.Draw();
	}
}

void CEnemyMgr::ChangeDir()
{
	switch (Dir)
	{
	case eRight:
		Dir = eDown;
		LastDir = eRight;
		break;
	case eLeft:
		Dir = eDown;
		LastDir = eLeft;
		break;
	case eUp:
		break;
	case eDown:
		if (LastDir == eRight)
		{
			Dir = eLeft;
		}
		else
		{
			Dir = eRight;
		}
		break;
	}
}