#include "pch.h"
using namespace std;

template<class... Ts>
struct overload : Ts...
{
	using Ts::operator()...;
};


template<class... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
	auto a = overload{
		[]() { cout << "()" << endl; },
		[](int) { cout << "(int)" << endl; },
		[](float) { cout << "(float)" << endl; },
	};

}