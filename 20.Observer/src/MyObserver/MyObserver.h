#pragma once

#include "Coin.h"

namespace MyObserver {

	inline void exec()
	{
		Coin c;
		CoinObserver v;
		c.subscribe(&v);

		c.setValue(4);
		c.setValue(5);
		c.setValue(6);
		c.setValue(7);
	}

}