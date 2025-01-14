#include "Dish.h"

#include "CommandScheduler.h"

Dish::Dish(float newTimeToPrepare, int newID)
{
	timeToPrepare = newTimeToPrepare;
	id = newID;
}

void Dish::Init()
{
	float randomImages = rand() % dishData->foodImages.size();
}

void Dish::OnNotify()
{
	printf("DISH %i IS FINISHED !!\n", id);
}

void Dish::ChangeDishData(std::shared_ptr<DishData> newData)
{
	dishData = newData;
}
