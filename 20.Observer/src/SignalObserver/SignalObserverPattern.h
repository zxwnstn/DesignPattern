#pragma once

#include "SignalObserver.h"

namespace SigObserver {
	
	inline void exec()
	{
		Person p{ 123 };

		auto conn = p.property_changed.connect([](Person& person, const std::string& prop_name) {
			std::cout << prop_name << " sex has been changed!" << std::endl;
		});

		p.set_age(20);

		conn.disconnect();
	}

}

