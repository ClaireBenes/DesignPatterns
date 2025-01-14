#pragma once
#include "Event.h"
#include "GameObject.h"
#include "CustomerData.h"

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

	std::vector<std::shared_ptr<CustomerData>> allCustomers;

	//maybe will have to do a "to add object" and "to remove" ?
	std::vector<std::shared_ptr<GameObject>> allGameObjects;

	CommandScheduler* commandScheduler = nullptr;
};

