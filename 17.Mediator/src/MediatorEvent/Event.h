#pragma once

namespace MediatorEvent {

	struct EventData
	{
		virtual ~EventData() = default;
		virtual void print() const = 0;
	};

	struct PlayerScoredData : EventData
	{
		std::string player_name;
		int goals_scored_so_far;

		PlayerScoredData(const std::string& player_name, const int goals_scored_so_far)
			: player_name(player_name), goals_scored_so_far(goals_scored_so_far)
		{}

		void print() const override
		{
			std::cout << player_name << "has scored! (ther " << goals_scored_so_far << " goal)" << "\n";
		}
	};

}
