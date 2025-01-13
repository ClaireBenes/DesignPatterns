#include "GameManager.h"

#include "Event.h"
#include "Dish.h"
#include "PrepareDishes.h"

#include "raylib.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	instance = this;
}

void GameManager::Init()
{
	commandScheduler = new CommandScheduler();
	eventDishReady = new Event();
	randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;
}

void GameManager::Update()
{
	// Customer
	timeElapsedCustomer += GetFrameTime();

	if(timeElapsedCustomer >= randomTimeBetweenCustomer)
	{
		timeElapsedCustomer -= randomTimeBetweenCustomer;

		randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;
		randomTimeToPrepare = rand() % maxTimeToPrepare + minTimeToPrepare;

		newDishID++;
		Dish newDish = Dish(randomTimeToPrepare, newDishID);
		eventDishReady->AddObserver(&newDish);
		PrepareDishes newDishesCommand = PrepareDishes(&newDish);
		commandScheduler->AddCommandToQueue(&newDishesCommand);

		printf("NEW CUSTOMER ARRIVED !!\n");

		if(timeToPrepare == 0)
		{
			commandScheduler->ExecuteNextCommand();
		}
	}


	// Dishes
	if(timeToPrepare != 0)
	{
		timeElapsedDishes += GetFrameTime();

		if(timeElapsedDishes >= timeToPrepare)
		{
			timeElapsedDishes -= timeToPrepare;

			eventDishReady->Notify();

			printf("DISH %i IS FINISHED !!\n", dishID);
		}
	}
}

void GameManager::Draw()
{
	
}

void GameManager::Unload()
{
	
}

GameManager* GameManager::GetInstance()
{
	return instance;
}
