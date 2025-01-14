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

	//NewCustomer();
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

	objectsToRemove.clear();

	//Customer
	timeElapsedCustomer += GetFrameTime();

	//Customer coming in every 1 to 4 secs.
	if(timeElapsedCustomer >= randomTimeBetweenCustomer)
	{
		timeElapsedCustomer -= 500.0f;//randomTimeBetweenCustomer;

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

	auto customerData = std::make_shared<CustomerData>();
	customerData->waitingPos += customerData->customerImages.width * 3 * allCustomers.size();

	auto customer = std::make_shared<Customer>();
	customer->ChangeCustomerData(customerData);

	allCustomers.push_back(customer);
	AddObject(customer);
}

void GameManager::AddObject(std::shared_ptr<GameObject> object)
{
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

	auto customerData = std::make_shared<CustomerData>();
	customerData->speed = 200;
	customerData->waitingPos = -200;

	//allCustomers[0]->ChangeCustomerData(customerData);
	allCustomers.erase(allCustomers.begin());

	/*for(auto& customer : allCustomers)
	{
		customer->customerData->waitingPos += customer->customerData->customerImages.width * 3;
	}*/
}
