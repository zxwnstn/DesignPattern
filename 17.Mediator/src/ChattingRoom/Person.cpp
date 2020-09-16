#include "pch.h"

#include "Person.h"
#include "ChatRoom.h"

namespace ChattingRoom {
	Person::Person(const std::string & name)
		: name(name)
	{}

	void Person::receive(const std::string & origin, const std::string & message)
	{
		std::string s(origin + ": \"" + message + "\"");
		std::cout << "[" << name << "'s chat session] " << s << "\n";
		chat_log.push_back(s);
	}

	void Person::Say(const std::string & message)
	{
		room->broadcast(name, message);
	}

	void Person::pm(const std::string & who, const std::string & message) const
	{
		room->message(name, who, message);
	}

}
