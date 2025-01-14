#pragma once

#include "IObserver.h"

#include <vector>
#include <memory>

class Event
{
public:
	std::vector<std::shared_ptr<IObserver>> observers;

	void AddObserver(std::shared_ptr<IObserver> observer);
	void RemoveObserver(std::shared_ptr<IObserver> observer);
	void Notify();
};

