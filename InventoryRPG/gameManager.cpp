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

	auto firstCustomerData = std::make_shared<CustomerData>();
	firstCustomerData->size = 5;
	//allCustomers.push_back(firstCustomerData);

	auto firstCustomer = std::make_shared<Customer>();
	firstCustomer->ChangeCustomerData(firstCustomerData);

	AddObject(firstCustomer);
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
}

void GameManager::Unload()
{
	
}

void GameManager::NewCustomer()
{
	printf("NEW CUSTOMER ARRIVED !!\n");

	auto customer = std::make_shared<Customer>();
	//AddObject(customer);
}

void GameManager::AddObject(std::shared_ptr<GameObject> object)
{
	objectsToAdd.push_back(object);
}

void GameManager::OnNotify()
{
	printf("Some dish has been prepared!\n");
	printf("Remaining customers: %i\n", (int)(commandScheduler->commandQueue.size() - 1));
}
