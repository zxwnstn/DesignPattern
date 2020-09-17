#pragma once

#include "pch.h"

namespace Functional {

	struct Logger
	{
		std::function<void(void)> func;
		std::string name;

		Logger(const std::function<void(void)>& func, const std::string& name)
			: func(func), name(name)
		{}

		void operator()()
		{
			std::cout << "Entering \n";
			func();
			std::cout << "Exiting\n";
		}
	};

	template<typename Func>
	struct Logger2
	{
		Func func;
		std::string name;

		Logger2(const Func& func, const std::string& name)
			: func(func), name(name)
		{}

		void operator()() const
		{
			std::cout << "Entering \n";
			func();
			std::cout << "Exiting\n";
		}
	};

	template<typename Func, typename = std::void_t<decltype(std::declval<Func>()())>>
	auto make_logger2(Func func, const std::string& name)
	{
		return Logger2<Func>{func, name};
	}

	double add(double a, double b)
	{
		std::cout << a << " + " << b << " = " << (a + b) << std::endl;
		return a + b;
	}

	template<typename R, typename... Args>
	struct Logger3
	{
		using ReturnType = R;

		Logger3(std::function<R(Args...)> func, const std::string& name)
			:func(func), name(name)
		{}

		ReturnType operator()(Args... args)
		{
			std::cout << "Entering " << name << std::endl;
			ReturnType ret = func(args...);
			std::cout << "Exiting " << name << std::endl;
			return ret;
		}

		std::function<R(Args...)> func;
		std::string name;
	};

	template<typename R, typename ...Args>
	auto make_logger3(R (*func)(Args...), const std::string& name)
	{
		return Logger3<R, Args...>(func, name);
	}

	inline void exec()
	{
		Logger logger([]() { std::cout << "hello" << std::endl; }, "HelloFunction");
		logger();

		auto logger2 = make_logger2([]() {std::cout << "fuck you" << std::endl; }, "fuck you");
		logger2();

		std::list<int> v;

		auto logger3 = make_logger3(add, "add");
		auto ret = logger3(3.0, 4.0);
	}

}