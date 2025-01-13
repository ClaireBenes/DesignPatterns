#pragma once

#include "IObserver.h"
#include "vector"


class Event
{
public:
	std::vector<IObserver*> observers;

	void AddObserver(IObserver* observer);
	void RemoveObserver(IObserver* observer);
	void Notify();
};

