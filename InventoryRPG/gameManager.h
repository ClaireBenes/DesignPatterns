#pragma once
#include "Dish.h"
#include <string>
#include <vector>

class Event;
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
	float timeElapsedDishes = 0.0f;

	bool isPreparingDish = false;

	Event* eventDishReady = nullptr;
	CommandScheduler* commandScheduler = nullptr;
};

