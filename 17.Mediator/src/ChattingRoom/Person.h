#pragma once

namespace ChattingRoom {

	struct ChatRoom;

	struct Person
	{
		std::string name;
		ChatRoom* room = nullptr;
		std::vector<std::string> chat_log;

		Person(const std::string& name);

		void receive(const std::string& origin, const std::string& message);
		void Say(const std::string& message);
		void pm(const std::string& who, const std::string& message) const;

	};

}
