#pragma once

namespace MyObserver {
	
	template<typename T, typename FuncType = void(void)>
	struct Observer
	{
		using FuncType_ = FuncType;

		boost::signals2::connection conn;
		FuncType* connectFunc;
		T* connectedObj = nullptr;

		void reconnect()
		{
			if (connectedObj)
			{
				connectedObj->subscribe(this);
			}
		}

		void disConnect()
		{
			conn.disconnect();
			connectedObj = nullptr;
		}
	};

}