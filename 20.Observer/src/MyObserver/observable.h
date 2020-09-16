#pragma once
#include "pch.h"

#include "observer.h"

namespace MyObserver {

	template<typename T, typename FuncType = void(void)>
	struct Observable
	{
		void subscribe(Observer<T, FuncType>* observer)
		{
			if (observer->connectedObj)
			{
				observer->disConnect();
			}
			observer->conn = sig.connect(observer->connectFunc);
			observer->connectedObj = static_cast<T*>(this);
		}

		void unsubscribe(Observer<T, FuncType>* observer)
		{
			if (observer->connectedObj == observer)
			{
				observer->disConnect();
			}
		}

		virtual void notify() = 0;

		boost::signals2::signal<FuncType> sig;
	};

}