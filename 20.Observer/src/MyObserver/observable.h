#pragma once
#include "pch.h"

#include "observer.h"

namespace MyObserver {

	template<typename T, typename FuncType = void(void)>
	struct Observable
	{
		void subscribe(Observer<T, FuncType>* observer)
		{
			sig.connect(observer->connectFunc);
		}

		void unsubscribe(Observer<T, FuncType>* observer)
		{
			observer->conn.disconnect();
		}

		virtual void notify() = 0;

		boost::signals2::signal<FuncType> sig;
	};

}