#pragma once

#include <Siv3D.hpp>
#include "Object.h"

using namespace std;

class CBullet : public CObject
{
private:
	double Speed;

public:
	CBullet(Vec2 vec, double speed, String s);
	~CBullet();

	//void Initialize();
	//void Finalize();
	void Update() override;
	void Draw() override;

	bool IsScreenOver();
};
