#include "Event.h"

void Event::AddObserver(std::shared_ptr<IObserver> observer)
{
	observers.push_back(observer);
}

void Event::RemoveObserver(std::shared_ptr<IObserver> observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	if(it == observers.end())
	{
		return;
	}

	observers.erase(it);
}

void Event::Notify()
{
	for(std::shared_ptr<IObserver> observer : observers)
	{
		observer->OnNotify();
	}
}
