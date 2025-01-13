#include "CommandScheduler.h"
#include "ICommand.h"

void CommandScheduler::AddCommandToQueue(ICommand* command)
{
	commandQueue.push_back(command);
}

void CommandScheduler::ExecuteFirstCommand()
{
	if(commandQueue.empty())
	{
		return;
	}

	bool isFinished = commandQueue.front()->Execute();
	if(isFinished)
	{
		RemovePreparedCommand();
	}
}

void CommandScheduler::RemovePreparedCommand()
{
	commandQueue.erase(commandQueue.begin());
}

void CommandScheduler::RemoveLastCommand()
{
	commandQueue.erase(commandQueue.begin() + commandQueue.size());
}