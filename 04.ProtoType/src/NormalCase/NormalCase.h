#pragma once

#include "pch.h"

namespace NormalCase {

	struct Address
	{
		std::string street, city;
		int suite;
	};

	struct Contact
	{
		std::string name;
		Address address;
	};

	inline void exec()
	{
		Contact worker{ "", Address{"123 east Dr", "London", 0} };
		Contact john = worker;
		john.name = "john Doe";
		john.address.suite = 10;
	}
}

