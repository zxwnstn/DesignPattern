#pragma once

namespace SigObserver {

	template<typename T>
	struct Observable
	{
		boost::signals2::signal<void(T&, const std::string&)> property_changed;
	};

	struct Person : Observable<Person>
	{
		Person(int age)
			: age(age)
		{}

		void set_age(const int age)
		{
			if (this->age == age)
				return;
			this->age = age;
			property_changed(*this, "age");
		}

		int age;
	};

}
