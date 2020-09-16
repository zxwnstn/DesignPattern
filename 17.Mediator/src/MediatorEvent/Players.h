#pragma once

#include "Game.h"

namespace MediatorEvent {

	struct Player
	{
		std::string name;

		int goals_scored = 0;
		Game& game;

		Player(const std::string& name, Game& game)
			: name(name), game(game)
		{}

		void score()
		{
			goals_scored++;
			PlayerScoredData ps{ name, goals_scored };
			game.events(&ps);
		}
	};

	struct Coach
	{
		Game& game;
		explicit Coach(Game& game)
			: game(game)
		{
			game.events.connect([](EventData* e) {
				PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
				if (ps && ps->goals_scored_so_far < 3)
				{
					std::cout << "coach says : well done, " << ps->player_name << "\n";
				}

			});

		}
	};

}
