#include "PrepareDishes.h"

#include "raylib.h"

PrepareDishes::PrepareDishes(Dish* newDish)
{
	gameManager = GameManager::GetInstance();
	dish = newDish;
}

void PrepareDishes::Execute()
{
	gameManager->timeToPrepare = dish->timeToPrepare;
	gameManager->dishID = dish->id;
}
