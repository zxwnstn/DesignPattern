#pragma once

#include "Players.h"

namespace MediatorEvent {

	inline void exec()
	{
		Game game;
		Player player{ "Sam", game };
		Coach coach(game);

		player.score();
		player.score();
		player.score();
	}

}
