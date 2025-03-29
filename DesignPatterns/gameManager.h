#pragma once
#include "Event.h"
#include "GameObject.h"
#include "Customer.h"
#include "Dish.h"

#include <string>
#include <vector>
#include <memory>
#include <array>

class CommandScheduler;

class GameManager : public IObserver, public std::enable_shared_from_this<GameManager>
{
public :
	void Init();
	void Update();
	void Draw();
	void Unload();

	void NewCustomer();
	void NewDish();
	void AddObject(std::shared_ptr<GameObject> object);
	void EraseObject(std::shared_ptr<GameObject> object);

	void OnNotify() override;

	std::array<std::shared_ptr<Dish>, 15> allDishes {};

private:
	const float gapBetweenTexture = 4;

	const int minTimeToPrepare = 1;
	const int maxTimeToPrepare = 6;
	const int minTimeBetweenCustomers = 2;
	const int maxTimeBetweenCustomers = 4;

	int randomTimeBetweenCustomer = 2;
	int randomTimeToPrepare = 2; 
	int newDishID = 0;
	
	float timeElapsedCustomer = 0.0f;

	//using smart (shared) pointer to automatically deallocate the objects when they are not referenced anymore
	std::shared_ptr<CustomerData> waitingCustomerData;
	std::shared_ptr<CustomerData> runningCustomerData;
	std::shared_ptr<DishData> dishData;

	std::vector<std::shared_ptr<Customer>> allCustomers;

	std::vector<std::shared_ptr<GameObject>> objectsToAdd;
	std::vector<std::shared_ptr<GameObject>> allObjects;
	std::vector<std::shared_ptr<GameObject>> objectsToRemove;

	std::shared_ptr<CommandScheduler> commandScheduler;

	Texture2D background;
};

