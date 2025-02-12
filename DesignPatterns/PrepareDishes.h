#pragma once

#include "Dish.h"
#include "ICommand.h"
#include "GameManager.h"
#include "Event.h"

class PrepareDishes : public ICommand
{
public:
	PrepareDishes(std::shared_ptr<Dish> newDish);
	bool Execute() override;
	
	Event onCooked;

private:
	std::shared_ptr<Dish> dish;
	float currentCookingTime = 0.0f;
};

