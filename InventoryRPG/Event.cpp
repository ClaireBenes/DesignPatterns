#include "Event.h"

void Event::AddObserver(IObserver* observer)
{
	observers.push_back(observer);
}

void Event::RemoveObserver(IObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	observers.erase(it);
}

void Event::Notify()
{
	for(IObserver* observer : observers)
	{
		observer->OnNotify();
	}
}
