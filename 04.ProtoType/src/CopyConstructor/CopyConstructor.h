#pragma once
#include "pch.h"

namespace CopyConstructor {

	struct Address
	{
		std::string street, city;
		int suite;

		Address(const std::string& street, const std::string& city, const int suite)
			: street{street},
			city{city},
			suite{suite}
		{}

	};
	struct Contact
	{
		std::string name;
		Address* address;

		Contact(const Contact& other)
			: name(other.name)
			, address{ new Address{ *other.address } }
		{}

		Contact(const std::string& name, Address* address)
			: name(name), address(address)
		{}

		Contact& operator=(const Contact& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			address = other.address;
			return *this;
		}
	};

	inline void exec()
	{
		Contact worker{ "", new Address{"123 East Dr", "London", 0} };
		Contact john{ worker };
		john.name = "john";
		john.address->suite = 10;
	}

}