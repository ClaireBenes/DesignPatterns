#include "GameManager.h"

#include "Event.h"
#include "PrepareDishes.h"

#include "raylib.h"

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
		Dish* newDish = new Dish(randomTimeToPrepare, newDishID, commandScheduler);
		eventDishReady->AddObserver(newDish);
		PrepareDishes* newDishesCommand = new PrepareDishes(newDish);
		newDishesCommand->onCooked.AddObserver(this);
		commandScheduler->AddCommandToQueue(newDishesCommand);

		printf("NEW CUSTOMER ARRIVED !!\n");
	}

	commandScheduler->ExecuteFirstCommand();

	// Dishes
	/*if(actualDish != nullptr && actualDish->timeToPrepare != 0)
	{


		if(!isPreparingDish)
		{
			isPreparingDish = true;
		}

		timeElapsedDishes += GetFrameTime();

		if(timeElapsedDishes >= actualDish->timeToPrepare)
		{
			timeElapsedDishes -= actualDish->timeToPrepare;

			eventDishReady->Notify();
			//eventDishReady->pop;
			isPreparingDish = false;
		}
	}*/
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
