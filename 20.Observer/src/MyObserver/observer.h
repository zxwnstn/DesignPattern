#pragma once

namespace MyObserver {
	
	template<typename T, typename FuncType_ = void(void)>
	struct Observer
	{
		using FuncType = FuncType_;

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