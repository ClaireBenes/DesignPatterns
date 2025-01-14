#include "GameManager.h"

#include "Event.h"
#include "PrepareDishes.h"
#include "CommandScheduler.h"
#include "Customer.h"

#include "raylib.h"

void GameManager::Init()
{
	commandScheduler = new CommandScheduler();
	randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;

	waitingCustomerData = std::make_shared<CustomerData>();
	waitingCustomerData->speed = 200;
	runningCustomerData = std::make_shared<CustomerData>();
	runningCustomerData->speed = 400;
}

void GameManager::Update()
{
	for(auto& object : objectsToAdd)
	{
		allObjects.push_back(object);
		object->Init();
	}

	for(auto& object : allObjects)
	{
		object->Update();
	}

	for(auto& object : objectsToRemove)
	{
		auto objectToKill = std::find(allObjects.begin(), allObjects.end(), object);
		if(objectToKill == allObjects.end())
		{
			continue;
		}

		allObjects.erase(objectToKill);
	}

	objectsToAdd.clear();
	objectsToRemove.clear();

	//Customer
	timeElapsedCustomer += GetFrameTime();

	//Customer coming in every 1 to 4 secs.
	if(timeElapsedCustomer >= randomTimeBetweenCustomer)
	{
		timeElapsedCustomer -= randomTimeBetweenCustomer;

		randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;
		randomTimeToPrepare = rand() % maxTimeToPrepare + minTimeToPrepare;

		NewCustomer();

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
	for(auto& object : allObjects)
	{
		object->Draw();
	}

	DrawText(TextFormat("GameObjects : %i", allObjects.size()), 20, 20, 20, RED);
}

void GameManager::Unload()
{
	
}

void GameManager::NewCustomer()
{
	printf("NEW CUSTOMER ARRIVED !!\n");

	auto customer = std::make_shared<Customer>();
	customer->waitingPos += waitingCustomerData->customerImages.width * 3 * allCustomers.size();
	customer->ChangeCustomerData(waitingCustomerData);

	allCustomers.push_back(customer);
	AddObject(customer);
}

void GameManager::AddObject(std::shared_ptr<GameObject> object)
{
	object->gameManager = this;
	objectsToAdd.push_back(object);
}

void GameManager::EraseObject(std::shared_ptr<GameObject> object)
{
	objectsToRemove.push_back(object);
}

void GameManager::OnNotify()
{
	printf("Some dish has been prepared!\n");
	printf("Remaining customers: %i\n", (int)(commandScheduler->commandQueue.size() - 1));

	allCustomers[0]->willBeDestroyed = true;
	allCustomers[0]->waitingPos = -200;
	allCustomers[0]->ChangeCustomerData(runningCustomerData);
	allCustomers.erase(allCustomers.begin());

	for(int i = 0; i < allCustomers.size(); i++)
	{
		allCustomers[i]->waitingPos = 200 + allCustomers[i]->customerData->customerImages.width * 3 * i;
	}
}
