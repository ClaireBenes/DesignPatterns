#pragma once

#include "Dish.h"
#include "ICommand.h"
#include "GameManager.h"

class PrepareDishes : public ICommand
{
public:
	PrepareDishes(Dish* newDish);
	void Execute() override;

protected:
	GameManager* gameManager;

private :
	Dish* dish;
};

