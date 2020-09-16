#pragma once

#include "pch.h"
#include "NormalCase/NormalCase.h"

namespace Fatory {

	struct employeeFactory
	{
		static NormalCase::Contact main;
		static NormalCase::Contact aux;

		static std::unique_ptr<NormalCase::Contact> NewMainOfficeEmployee(std::string& name, int suite)
		{
			return NewEmployee(name, suite, main);
		}
		static std::unique_ptr<NormalCase::Contact> NewAuxOfficeEmployee(std::string& name, int suite)
		{
			return NewEmployee(name, suite, aux);
		}
	private:
		static std::unique_ptr<NormalCase::Contact> NewEmployee(const std::string& name, int suite, NormalCase::Contact& proto)
		{
			auto result = std::make_unique<NormalCase::Contact>(proto);
			result->name = name;
			result->address.suite = suite;
			return result;
		}

	};

}