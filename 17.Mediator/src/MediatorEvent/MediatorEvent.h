#pragma once
#include "pch.h"

#include "Players.h"

struct MediatorEvent
{
	static void exec()
	{
		Game game;
		Player player{ "Sam", game };
		Coach coach(game);

		player.score();
		player.score();
		player.score();
	}
};
