#pragma once

#include "IObserver.h"
#include "CommandScheduler.h"

class Dish : public IObserver
{
public:
	Dish(float newTimeToPrepare, int newId, CommandScheduler* newCommandScheduler);

	void OnNotify() override;
	
	float timeToPrepare;
	int id;

protected:
	CommandScheduler* commandScheduler;
};

