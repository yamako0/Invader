#pragma once

#include "Object.h"
#include "BulletMgr.h"

using namespace std;

class CEnemy : public CObject
{

public:
	CEnemy(Vec2 pos);
	~CEnemy();

	//void Initialize();
	//void Finalize();
	void Update() override;
	void Draw() override;


	void Move(Vec2 vec);
};
