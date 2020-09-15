#pragma once

template<typename T>
struct Observer
{
	virtual void field_Changed(T& source, const std::string& field_name) = 0;
};

template<typename T>
struct Observable
{
	void notify(T& source, const std::string& name)
	{
		for (auto obs : observers)
		{
			obs->field_Changed(source, name);
		}
	}

	void subscribe(Observer<T>* f)
	{
		observers.push_back(f);
	}

	void unsubscribe(Observer<T>* f)
	{
		auto target = std::find_if(observers.begin(), observers.end(), [&](Observer<T>* ff) {
			return f == ff;
		});
		if (target != observers.end())
		{
			v.erase(target);
		}
	}

	std::vector<Observer<T>*> observers;
};