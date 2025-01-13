#include "Dish.h"

#include "CommandScheduler.h"

Dish::Dish(float newTimeToPrepare, int newID, CommandScheduler* newCommandScheduler)
{
	commandScheduler = newCommandScheduler;

	timeToPrepare = newTimeToPrepare;
	id = newID;
}

void Dish::OnNotify()
{
	printf("DISH %i IS FINISHED !!\n", id);
}
