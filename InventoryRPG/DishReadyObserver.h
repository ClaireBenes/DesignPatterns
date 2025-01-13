#pragma once

#include "IObserver.h"
#include "CommandScheduler.h"

class DishReadyObserver : public IObserver
{
public:
	DishReadyObserver();

	void OnNotify() override;

protected:
	CommandScheduler* commandScheduler;
};

