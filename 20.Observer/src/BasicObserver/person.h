#pragma once

#include "Observer.h"

namespace BasicObserver {

	struct Person : Observable<Person>
	{
		Person(int age)
			: age(age)
		{}

		void set_age(int age)
		{
			if (age == this->age)
				return;

			this->age = age;
			notify(*this, "age");
		}
		int get_age() const
		{
			return age;
		}

		int age;
	};

	struct ConsolePersonObserver : Observer<Person>
	{
		void field_Changed(Person & source, const std::string & field_name) override
		{
			std::cout << "Person's " << field_name << " has changed to " << source.get_age() << "\n";
		}
	};

} 