#pragma once

#include "Dish.h"
#include "ICommand.h"
#include "GameManager.h"
#include "Event.h"

class PrepareDishes : public ICommand
{
public:
	PrepareDishes(Dish* newDish);
	bool Execute() override;
	
	Event onCooked;

private:
	Dish* dish;
	float currentCookingTime = 0.0f;
};

