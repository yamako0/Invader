#pragma once

#include <Siv3D.hpp>
#include "Enemy.h"

using namespace std;

enum Direction
{
	eRight,
	eLeft,
	eUp,
	eDown,

	eDirectionNum
};

class CEnemyMgr : public Task
{
	list<CEnemy> Enemy;
	Vec2 BasePos;

	Direction Dir;
	Direction LastDir;

	void ChangeDir();

public:
	CEnemyMgr();
	~CEnemyMgr();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;

	list<CEnemy> *GetEnemyArray() { return &Enemy; }
};
