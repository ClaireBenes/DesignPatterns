#include "GameManager.h"

#include "Event.h"
#include "PrepareDishes.h"

#include "raylib.h"

void GameManager::Init()
{
	commandScheduler = new CommandScheduler();
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
		Dish* newDish = new Dish(randomTimeToPrepare, newDishID);
		PrepareDishes* newDishesCommand = new PrepareDishes(newDish);
		newDishesCommand->onCooked.AddObserver(this);
		commandScheduler->AddCommandToQueue(newDishesCommand);

		printf("NEW CUSTOMER ARRIVED !!\n");
	}

	//Cooking
	commandScheduler->ExecuteFirstCommand();
}

void GameManager::Draw()
{
	
}

void GameManager::Unload()
{
	
}

void GameManager::OnNotify()
{
	printf("Some dish has been prepared!\n");
	printf("Remaining customers: %i\n", (int)(commandScheduler->commandQueue.size() - 1));
}
