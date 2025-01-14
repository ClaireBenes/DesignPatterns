#pragma once
#include "Event.h"
#include "GameObject.h"
#include "Customer.h"

#include <string>
#include <vector>
#include <memory>

class CommandScheduler;

class GameManager : public IObserver
{
public :
	void Init();
	void Update();
	void Draw();
	void Unload();

	void NewCustomer();
	void AddObject(std::shared_ptr<GameObject> object);
	void EraseObject(std::shared_ptr<GameObject> object);

	void OnNotify() override;

private:

	const int minTimeToPrepare = 1;
	const int maxTimeToPrepare = 6;
	const int minTimeBetweenCustomers = 2;
	const int maxTimeBetweenCustomers = 4;

	int randomTimeBetweenCustomer = 2;
	int randomTimeToPrepare = 2; 
	int newDishID = 0;
	
	float timeElapsedCustomer = 0.0f;

	std::shared_ptr<CustomerData> waitingCustomerData;
	std::shared_ptr<CustomerData> runningCustomerData;

	std::vector<std::shared_ptr<Customer>> allCustomers;
	std::vector<std::shared_ptr<GameObject>> objectsToAdd;
	std::vector<std::shared_ptr<GameObject>> allObjects;
	std::vector<std::shared_ptr<GameObject>> objectsToRemove;

	CommandScheduler* commandScheduler = nullptr;
};

