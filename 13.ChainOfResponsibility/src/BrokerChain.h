#pragma once

namespace BChain
{
	struct Query
	{
		enum Argument
		{
			atk, def
		};

		std::string creature_name;
		Argument argument;
		int result;
	};

	struct Game
	{
		boost::signals2::signal<void(Query&)> quries;
	};

	class Creature
	{
	public:
		Creature(Game& game, const std::string& name, int atk, int def)
			: game{ game }, name(name), atk(atk), def(def)
		{}

		int get_attack() const
		{
			Query q{ name, Query::Argument::atk, atk };
			game.quries(q);
			return q.result;
		}

		int get_def() const
		{
			Query q{ name, Query::Argument::def, def };
			game.quries(q);
			return q.result;
		}

		friend std::ostream& operator<<(std::ostream& out, Creature& other)
		{
			out << other.name << "\n" << "atk : " << other.get_attack() << "\ndef : " << other.get_def() << "\n";
			return out;
		}


	public:
		std::string name;

	private:
		Game& game;
		int atk, def;
	};

	class CreatureModifier
	{
		Game& game;
		Creature& creature;

	public:
		CreatureModifier(Game& game, Creature& creature)
			: game(game), creature(creature)
		{}
	};

	class DoubleAttackModifier : public CreatureModifier
	{
		boost::signals2::connection conn;
	public:
		DoubleAttackModifier(Game& game, Creature& creature)
			: CreatureModifier(game, creature)
		{
			conn = game.quries.connect([&](Query& q)
			{
				if (q.creature_name == creature.name && q.argument == Query::Argument::atk)
				{
					q.result *= 2;
				}
			});
		}

		~DoubleAttackModifier()
		{
			conn.disconnect();
		}
	};

	class IncreaseDefModifier : public CreatureModifier
	{
		boost::signals2::connection conn;
	public:
		IncreaseDefModifier(Game& game, Creature& creature)
			: CreatureModifier(game, creature)
		{
			conn = game.quries.connect([&](Query& q)
			{
				if (q.creature_name == creature.name && q.argument == Query::Argument::def)
				{
					q.result += 1;
				}
			});
		}

		~IncreaseDefModifier()
		{
			conn.disconnect();
		}
	};



	struct BChain
	{
	public:
		static void exec()
		{
			Game game;
			Creature goblin(game, "goblin", 2, 2);
			{
				DoubleAttackModifier dam(game, goblin);
				std::cout << goblin;

				IncreaseDefModifier inc(game, goblin);
				std::cout << goblin;
			}
			std::cout << goblin;
		}
	};

}
