#pragma once

#include "IObserver.h"

class Dish : public IObserver
{
public:
	Dish(float newTimeToPrepare, int newId);

	void OnNotify() override;
	
	float timeToPrepare;
	int id;
};

