#pragma once

#include "Object.h"

class CCollision
{

public:
	CCollision();
	~CCollision();

	bool Intersects(CObject obj1, CObject obj2);
};
