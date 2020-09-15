#pragma once

#include "ChatRoom.h"
#include "Person.h"

struct ChattingRoomExec
{
	static void exec()
	{
		ChatRoom room;
		Person john{ "john" };
		Person jane{ "jane" };
		room.join(&john);
		room.join(&jane);
		john.Say("hi room");
		jane.Say("oh, hey john");

		Person simon("simon");
		room.join(&simon);
		simon.Say("hi everyone!");

		jane.pm("simon", "glad you could join us, simon");
	}
};