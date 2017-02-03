#include "Collision.h"

CCollision::CCollision()
{
}

CCollision::~CCollision()
{
}

bool CCollision::Intersects(CObject obj1, CObject obj2)
{
	return obj1.GetCollision().intersects(obj2.GetCollision());
}