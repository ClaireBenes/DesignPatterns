#include "DishReadyObserver.h"

#include "CommandScheduler.h"

DishReadyObserver::DishReadyObserver()
{
	commandScheduler = CommandScheduler::GetInstance();
}

void DishReadyObserver::OnNotify()
{
	commandScheduler->RemovePreparedCommand();
	commandScheduler->ExecuteNextCommand();
}
