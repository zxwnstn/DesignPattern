#pragma once

#include "Coin.h"

namespace MyObserver {

	inline void exec()
	{
		Coin c;
		CoinObserver v;
		CoinObserver v2;
		v2.setConnectFunc([](Coin* coin) {std::cout << "나는 2번째\n"; });
		c.subscribe(&v);
		c.subscribe(&v2);

		c.setValue(4);
		c.setValue(5);
		c.setValue(6);
		c.setValue(7);

		v.setConnectFunc([](Coin* coin) {std::cout << "sex!\n"; });

		c.setValue(8);
		c.setValue(9);
		c.setValue(10);
		c.setValue(11);
		c.unsubscribe(&v2);

		v.setConnectFunc([](Coin* coin) {std::cout << coin->value << "\n"; });

		c.setValue(12);
		c.setValue(13);
		c.setValue(14);
		c.setValue(15);
	}

}