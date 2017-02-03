#pragma once

#include <Siv3D.hpp>
#include"Task.h"

class CObject : public Task
{
protected:
	Vec2 Pos;
	Circle HitRange;
	Texture Image;

public:
	CObject(String s);
	virtual ~CObject();

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;

	Circle GetCollision() { return HitRange; }
};
