#pragma once

struct Person;

struct ChatRoom
{
	std::vector<Person*> people;

	void join(Person* p);
	void broadcast(const std::string& origin, const std::string& message);
	void message(const std::string& origin, const std::string& who, const std::string& message);
};