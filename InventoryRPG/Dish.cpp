#include "Dish.h"

#include "CommandScheduler.h"

Dish::Dish(float newTimeToPrepare, int newID)
{
	commandScheduler = CommandScheduler::GetInstance();

	timeToPrepare = newTimeToPrepare;
	id = newID;
}

void Dish::OnNotify()
{
	commandScheduler->RemovePreparedCommand();

	if(commandScheduler->commandQueue.size() != 0)
	{
		commandScheduler->ExecuteNextCommand();
	}
}
