#pragma once

#include "Event.h"

namespace MediatorEvent {

	struct Game
	{
		boost::signals2::signal<void(EventData*)> events;
	};

}