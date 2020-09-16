#pragma once

#include "observer.h"
#include "observable.h"

namespace MyObserver {

	struct Ex
	{
		void execMe(int coin)
		{
			std::cout << "ki kick";
		}
	};
	
	struct Coin : Observable<Coin, void(Coin*)>
	{
		void notify() override
		{
			sig(this);
		}

		void setValue(int _value)
		{
			value = _value;
			notify();
		}

		int value = 0;

	};

	struct CoinObserver : Observer<Coin, void(Coin*)>
	{
		CoinObserver()
		{
			connectFunc = [](Coin* coin) {
				std::cout << "value changed! : " << coin->value << "\n"; 
			};
		}
		
		void setConnectFunc(FuncType func)
		{
			connectFunc = func;
			conn.disconnect();
			reconnect();
		}
	};

	

}