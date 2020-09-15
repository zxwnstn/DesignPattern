#pragma once

#include "Event.h"

struct Game
{
	boost::signals2::signal<void(EventData*)> events;
};
