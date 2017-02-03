#pragma once

#include <Siv3D.hpp>
#include"BulletMgr.h"
#include "Object.h"

using namespace std;

enum PlayerState
{
	eAlive,
	eDeath
};

class CPlayer : public CObject
{
	PlayerState State;

public:
	CPlayer();
	~CPlayer();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;

	void SetState(PlayerState state) { State = state; }
	PlayerState GetState() { return State; }

	//inline Vec2 GetPos() { return Pos; }
};
