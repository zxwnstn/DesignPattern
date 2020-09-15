#pragma once

template<typename T>
struct SigObservable
{
	boost::signals2::signal<void(T&, const std::string&)> property_changed;
};

struct SigPerson : SigObservable<SigPerson>
{
	SigPerson(int age)
		: age(age)
	{}

	void set_age(const int age)
	{
		if (this->age == age)
			return;
		this->age = age;
		property_changed(*this, "age");
	}

	int age;
};

struct SigObserver
{
	template<typename T>
	void connection(SigObservable<T>* observable)
	{
		connection = observable->property_changed.connect(boost::bind(*this, &SigObserver::connectFunc));
	}

	virtual void connectFunc(SigPerson& person, const std::string& prop_name) = 0;

	boost::signals2::connection conn;
};

struct PersonSigObserver : SigObserver
{
	virtual void connectFunc(SigPerson& person, const std::string& prop_name) override
	{

	}

};