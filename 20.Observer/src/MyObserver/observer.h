#pragma once

namespace MyObserver {
	
	template<typename T, typename FuncType = void(void)>
	struct Observer
	{
		boost::signals2::connection conn;
		FuncType* connectFunc;
	};

}