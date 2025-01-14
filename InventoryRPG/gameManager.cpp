#include "GameManager.h"

#include "Event.h"
#include "PrepareDishes.h"
#include "CommandScheduler.h"

#include "raylib.h"

void GameManager::Init()
{
	commandScheduler = new CommandScheduler();
	randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;

	auto firstCustomer = std::make_shared<CustomerData>();
	allCustomers.push_back(firstCustomer);
}

void GameManager::Update()
{
	//Customer
	timeElapsedCustomer += GetFrameTime();

	//Customer coming in every 1 to 4 secs.
	if(timeElapsedCustomer >= randomTimeBetweenCustomer)
	{
		timeElapsedCustomer -= randomTimeBetweenCustomer;

		randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;
		randomTimeToPrepare = rand() % maxTimeToPrepare + minTimeToPrepare;

		printf("NEW CUSTOMER ARRIVED !!\n");

		newDishID++;
		Dish* newDish = new Dish(randomTimeToPrepare, newDishID);
		PrepareDishes* newDishesCommand = new PrepareDishes(newDish);
		newDishesCommand->onCooked.AddObserver(this);
		commandScheduler->AddCommandToQueue(newDishesCommand);
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
