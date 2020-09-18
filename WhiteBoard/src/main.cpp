#include "pch.h"
using namespace std;

template<class... Ts>
struct overload : Ts...
{
	using Ts::operator()...;
};


template<class... Ts>
overload(Ts...)->overload<Ts...>;

class A
{
public:
	~A() throw(std::string)
	{
		
		throw(std::string("asdf"));
		
	}

};


class vector
{
public:
	vector()
	{
		
	}
	~vector() throw(std::string)
	{
		
	}
	A aa[5];
};

int main()
{
	try {
		{
			::vector a;
		}
	}
	catch (...)
	{
	}

	std::vector<int> v;
	std::find(v.begin(), v.end(), 4);
}