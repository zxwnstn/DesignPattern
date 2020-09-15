#pragma once

namespace PChain {

	struct Creature
	{
		std::string name;
		int attack, defense;
	};

	class CreatureModifier
	{
		CreatureModifier* next{ nullptr };

	protected:
		Creature& creature;

	public:
		explicit CreatureModifier(Creature& creature)
			: creature(creature)
		{}

		void add(CreatureModifier* cm)
		{
			if (next)
			{
				next->add(cm);
			}
			else
			{
				next = cm;
			}
		}

		virtual void handle()
		{
			if (next) next->handle();
		}
	};

	class DoubleAttackModifier : public CreatureModifier
	{
	public:
		explicit DoubleAttackModifier(Creature& creature)
			: CreatureModifier(creature)
		{}

		virtual void handle() override
		{
			creature.attack *= 2;
			CreatureModifier::handle();
		}
	};

	class IncreaseDefenseModifier : public CreatureModifier
	{
	public:
		explicit IncreaseDefenseModifier(Creature& creature)
			: CreatureModifier(creature)
		{}

		virtual void handle() override
		{
			creature.defense += 1;
			CreatureModifier::handle();
		}
	};

	class NoBonusModifier : public CreatureModifier
	{
	public:
		explicit NoBonusModifier(Creature& creature)
			: CreatureModifier(creature)
		{}

		virtual void handle() override
		{
			//CreatureModifier::handle();
		}
	};


	struct PChain
	{
	public:
		static void exec()
		{
			Creature goblin{ "Goblin", 1, 1 };
			CreatureModifier root(goblin);
			DoubleAttackModifier da(goblin);
			DoubleAttackModifier da2(goblin);
			IncreaseDefenseModifier inc(goblin);

			root.add(&da);
			root.add(&da2);
			root.add(&inc);

			root.handle();
		}
	};

}


