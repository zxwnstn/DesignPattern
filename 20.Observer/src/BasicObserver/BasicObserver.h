#pragma once
#include "Person.h"

namespace BasicObserver {
	
	inline void exec()
	{
		Person p{ 20 };
		ConsolePersonObserver cpo;
		p.subscribe(&cpo);
		p.set_age(21);
		p.set_age(22);
	}
}