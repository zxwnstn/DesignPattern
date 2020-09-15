#include "pch.h"

#include "BasicObserver/BasicObserver.h"
#include "SignalObserver/SignalObserverPattern.h"

int main()
{
	BasicObserverPattern::exec();
	SigObserverPattern::exec();
}