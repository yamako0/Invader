#include <Siv3D.hpp>
#include "source\StageMgr.h"

void Main()
{
	CStageMgr StageMgr;

	StageMgr.Initialize();

	while (System::Update())
	{
		StageMgr.Update();
		StageMgr.Draw();
	}

	StageMgr.Finalize();
}