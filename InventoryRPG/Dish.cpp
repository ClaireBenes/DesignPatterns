#include "Dish.h"

#include "CommandScheduler.h"

Dish::Dish(float newTimeToPrepare, int newID)
{
	timeToPrepare = newTimeToPrepare;
	id = newID;
}

void Dish::OnNotify()
{
	printf("DISH %i IS FINISHED !!\n", id);
}
