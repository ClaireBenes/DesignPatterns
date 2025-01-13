#pragma once
#include <string>
#include <vector>

class Event;
class CommandScheduler;

class GameManager
{
public :
	GameManager();

	void Init();
	void Update();
	void Draw();
	void Unload();

	static GameManager* GetInstance();

	float timeToPrepare = 0.0f;
	int dishID = 0;

private:

	const int minTimeToPrepare = 1;
	const int maxTimeToPrepare = 6;
	const int minTimeBetweenCustomers = 1;
	const int maxTimeBetweenCustomers = 3;

	int randomTimeBetweenCustomer = 2;
	int randomTimeToPrepare = 2; 
	int newDishID = 0;
	
	float timeElapsedCustomer = 0.0f;
	float timeElapsedDishes = 0.0f;

	Event* eventDishReady = nullptr;
	CommandScheduler* commandScheduler = nullptr;
	static GameManager* instance;
};

