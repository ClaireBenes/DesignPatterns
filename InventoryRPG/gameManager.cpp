#include "GameManager.h"

#include "Event.h"
#include "PrepareDishes.h"
#include "CommandScheduler.h"
#include "Customer.h"

#include "raylib.h"

void GameManager::Init()
{
	//Create a CommandScheduler
	commandScheduler = std::make_shared<CommandScheduler>();

	//Random time between customers
	randomTimeBetweenCustomer = rand() % maxTimeBetweenCustomers + minTimeBetweenCustomers;

	//Initialize different type of customer data
	waitingCustomerData = std::make_shared<CustomerData>();
	waitingCustomerData->speed = 200;
	runningCustomerData = std::make_shared<CustomerData>();
	runningCustomerData->speed = 400;

	//Initialize different type of dish data
	dishData = std::make_shared<DishData>();
}

void GameManager::Update()
{
	//Adding object that we want to add
	for(auto& object : objectsToAdd)
	{
		allObjects.push_back(object);
		object->Init();
	}

	//Update all objects
	for(auto& object : allObjects)
	{
		object->Update();
	}

	//Addinf object that we want to remove
	for(auto& object : objectsToRemove)
	{
		auto objectToKill = std::find(allObjects.begin(), allObjects.end(), object);
		if(objectToKill == allObjects.end())
		{
			continue;
		}

		allObjects.erase(objectToKill);
	}

	//Clear both object to add and remove
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

		//Spawn a new customer & a new Dish
		NewCustomer();
		NewDish();
	}

	//Cooking
	commandScheduler->ExecuteFirstCommand();
}

void GameManager::Draw()
{
	//Draw all object
	for(auto& object : allObjects)
	{
		object->Draw();
	}

	//objects count
	DrawText(TextFormat("GameObjects : %i", allObjects.size()), 20, 20, 20, RED);
}

void GameManager::Unload()
{
	
}

void GameManager::NewCustomer()
{
	printf("NEW CUSTOMER ARRIVED !!\n");

	//Create new customer
	auto customer = std::make_shared<Customer>();
	//Update his go to pos
	customer->waitingPos += waitingCustomerData->customerImages.width * 3 * allCustomers.size();
	//Change its data
	customer->ChangeCustomerData(waitingCustomerData);

	allCustomers.push_back(customer);
	AddObject(customer);
}

void GameManager::NewDish()
{
	newDishID++;

	//Create new Dish
	std::shared_ptr<Dish> newDish = std::make_shared<Dish>(randomTimeToPrepare, newDishID);

	//Change its data & Initialze
	newDish->ChangeDishData(dishData);
	newDish->Init();

	AddObject(newDish);
	allDishs.push_back(newDish);

	//Add the dish to prepareDishes to start cooking it
	std::shared_ptr<PrepareDishes> newDishesCommand = std::make_shared<PrepareDishes>(newDish);
	newDishesCommand->onCooked.AddObserver(shared_from_this());

	//Add dish to queue
	commandScheduler->AddCommandToQueue(newDishesCommand);
}

void GameManager::AddObject(std::shared_ptr<GameObject> object)
{
	//Put object that will be added later
	object->gameManager = this;
	objectsToAdd.push_back(object);
}

void GameManager::EraseObject(std::shared_ptr<GameObject> object)
{
	//Put object that will be removed later
	objectsToRemove.push_back(object);
}

void GameManager::OnNotify()
{
	printf("Some dish has been prepared!\n");
	printf("Remaining customers: %i\n", (int)(commandScheduler->commandQueue.size() - 1));

	//When dish is finished -> Customer will move away, walk faster
	allCustomers[0]->willBeDestroyed = true;
	allCustomers[0]->waitingPos = -200;
	allCustomers[0]->ChangeCustomerData(runningCustomerData);
	allCustomers.erase(allCustomers.begin());

	//Move all other customers still waiting to the next available spot
	for(int i = 0; i < allCustomers.size(); i++)
	{
		allCustomers[i]->waitingPos = 200 + allCustomers[i]->customerData->customerImages.width * 3 * i;
	}
}
